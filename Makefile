SPACE	:= $(EMPTY) $(EMPTY)
SLASH	:= /

ifndef GCCPREFIX
GCCPREFIX := riscv64-linux-gnu-
endif

# eliminate default suffix rules
.SUFFIXES: .c .S .h

# delete target files if there is an error (or make is interrupted)
.DELETE_ON_ERROR:

DATE=`date +%y%m%d%H%M`
# define compiler and flags
GDB		:= $(GCCPREFIX)gdb

CC		:= $(GCCPREFIX)gcc
CFLAGS  := -mcmodel=medany -std=gnu99 -Wno-unused -Werror
CFLAGS	+= -fno-builtin -Wall -O2 -fno-strict-aliasing $(DEFS)
CFLAGS	+= -fno-stack-protector -ffunction-sections -fdata-sections
CTYPE	:= c S

LD      := $(GCCPREFIX)ld
LDFLAGS	:= -m elf64lriscv
LDFLAGS	+= -nostdlib --gc-sections

OBJCOPY := $(GCCPREFIX)objcopy
OBJDUMP := $(GCCPREFIX)objdump

COPY	:= cp
MKDIR   := mkdir -p
MV	:= mv
RM	:= rm -f
AWK	:= awk
SED	:= sed
SH	:= sh
TR	:= tr
TOUCH	:= touch -c

OBJDIR	:= obj
BINDIR	:= bin

include tools/function.mk

listf_cc = $(call listf,$(1),$(CTYPE))

# for cc
add_files_cc = $(call add_files,$(1),$(CC),$(CFLAGS) $(3),$(2),$(4))
create_target_cc = $(call create_target,$(1),$(2),$(3),$(CC),$(CFLAGS))

# for hostcc
add_files_host = $(call add_files,$(1),$(HOSTCC),$(HOSTCFLAGS),$(2),$(3))
create_target_host = $(call create_target,$(1),$(2),$(3),$(HOSTCC),$(HOSTCFLAGS))

cgtype = $(patsubst %.$(2),%.$(3),$(1))
objfile = $(call toobj,$(1))
asmfile = $(call cgtype,$(call toobj,$(1)),o,asm)
outfile = $(call cgtype,$(call toobj,$(1)),o,out)
symfile = $(call cgtype,$(call toobj,$(1)),o,sym)

# for match pattern
match = $(shell echo $(2) | $(AWK) '{for(i=1;i<=NF;i++){if(match("$(1)","^"$$(i)"$$")){exit 1;}}}'; echo $$?)

# -------------------------------------------------------------------
# kernel

KINCLUDE	+= driver/ libs/ 

KSRCDIR		+= init libs driver trap

KCFLAGS		+= $(addprefix -I,$(KINCLUDE))

$(call add_files_cc,$(call listf_cc,$(KSRCDIR)),kernel,$(KCFLAGS))

KOBJS	= $(call read_packet,kernel libs)

# create kernel target
KERNEL = $(call totarget,kernel)

$(KERNEL): tools/kernel.ld

$(KERNEL): $(KOBJS)
	@echo + ld $@
	$(LD) $(LDFLAGS) -T tools/kernel.ld -o $@ $(KOBJS)
	@$(OBJDUMP) -S $@ > $(call asmfile,kernel)
	@$(OBJDUMP) -t $@ | $(SED) '1,/SYMBOL TABLE/d; s/ .* / /; /^$$/d' > $(call symfile,kernel)

$(call create_target,kernel)

# >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

$(call finish_all)

TARGETS: $(TARGETS)

.DEFAULT_GOAL := TARGETS

.PHONY: k210
k210: $(KERNEL)
	$(OBJCOPY) -O binary $^ bin/kernel.bin
	sudo python3 tools/isp_auto.py bin/kernel.bin | tee $(DATE).log
	sudo minicom -D /dev/ttyUSB0

.PHONY: clean
clean:
	-$(RM) -r $(OBJDIR) $(BINDIR)

