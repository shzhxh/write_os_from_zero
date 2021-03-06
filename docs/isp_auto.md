- isp: in system programming
- iap: in application programming

### 第一步：参数分析

1. 其它参数使用默认值即可，但必须给出内核的位置
2. 创建MAIXLoader对象，此对象用以实现bootloader的功能

### 第二步：Greeting

1. 首先把SoC设置为isp模式(在线系统编程，Serial.dts与IO_16引脚对应，置为True即可)。另，Serial.rts与RESET引脚对应，置为True是引发系统重启。
2. 执行greeting。即向端口写入15个字节。

### 第三步：把bootloader和kernel刷入闪存

1. 获取内核二进制文件的句柄
2. 如指定bootloader则刷入bootloader，否则刷入默认bootloader(ISP_PROG)
3. boot
4. flash_greeting
5. init_flash
6. flash_firmware

### 第四步：启动

通过设置端口的rts为True来实现重启的功能

### 附录：bootloader分析

在isp_auto.py里有段代码ISP_PROG是刷入到flash的bootloader，它都做了点啥呢？

如下做了点尝试，但汇编代码难以理解，不再进行后续分析。

首先，把这段代码重定向到文件，并反汇编出来。

```
# 以wb模式打开一个文件out.bin，然后用write方法写入到out.bin
hexdump -C out.bin > out.hex
objdump -D -b binnary -m riscv:rv64 out.bin > out.asm
```

#### 代码

##### 第一段

```
4:		deadbeef应该是个魔数
8-c:	将mideleg和medeleg置0，是把所有的中断和异常都在机器态执行，不授权给其它态执行
10-14:	将mie和mip置0，是关闭中断，因为现在还没有设置好怎么处理中断
18-20:	用mtvec记录中断处理例程的地址，中断处理例程的绝对地址在0xe8
24-9c:	将所有的通用寄存器置0，我理解这只是一个良好的习惯，但这段代码没有意义
a0-ac:	如果misa的值小于0，表明指令集支持64位，跳转到0xb0;否则表明支持的是32位指令集，跳转到0x5570
b0-b4:	为gp赋值：0x8d78
b8-c0:	为tp赋值
c4-cc:	如mhartid的值大于等于2则进入死循环(因为k210是双核，只能是0或1)
d0-d4:	依据当前核编号设置tp的值，两个核的tp值相差4k
d8-e0:	设置sp的值，两个核的sp值相差4k
e4:		跳转到0x473c
```

##### 0xe8(中断处理)

##### 0x20d2(一个函数)

```
20d2-20ea:	a0,a1,a2,a4,a5逻辑运算，并返回
```



##### 0x473c(第二段)

```
473c-4778:	将s0,s1,s2,s3,ra的值入栈，跳转到0x20d2
```



##### 0x5570(异常处理：指令集为32位)

#### 数据

##### 0x8d78(gp)

最高到0x85ac，无此区域。

### 