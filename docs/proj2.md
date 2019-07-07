#### 简介

proj1的目的是实现一个可运行的系统，打印“Hello World”出来以看到它确实运行起来了。proj2的目标是让两个核都工作起来，而让两个核都要工作实际上是要建立整个中断系统。

#### rt-thread对于中断的管理

##### 设置mtvec寄存器

- 源码在`libcpu/risc-v/k210/startup_gcc.S`

  在`_start`标记里把trap_entry的地址保存在mtvec寄存器里。mtvec寄存器用以保存中断处理例程的入口，当中断发生时就跳转到mtvec所保存的地址去执行。

- trap_entry的源码在`libcpu/risc-v/k210/interrupt_gcc.S`

  1. 将通过寄存器的值保存在栈中，即保存上下文
  2. 获取sp和mhartid的值
  3. 切换到当前CPU的𣏾(每个核都有自己的𣏾指针，个人认为此步无意义)
  4. 调用handle_trap，以mcause, mepc, sp的值为参数
  5. 如开启了多核，要切换到优先级最高的线程
  6. 如没有开启多核，则恢复栈中保存的内容到寄存器，返回调用处继续执行

- handle_trap的源码在`libcpu/risc-v/k210/interrupt.c`

  - 依据mcause的值判断中断类型
  - 如为软中断，则执行rt_schedule，它将从就绪队列里选一个优先级最高的线程，切换过去
  - 如为外中断，则执行handle_irq_m_ext
  - 如为计时器中断，则执行tick_isr
  - 如不是以上三种，则表明出现了不可识别的中断，列出出错信息，并进入死循环。

##### 平台级的中断

源码在`libcpu/risc-v/k210/interrupt.c`

函数rt_hw_interrupt_init用于初始化平台级的中断

- rtthread_startup --> rt_hw_board_init --> rt_hw_interrupt_init

  1. 关闭当前核的所有中断
  2. 所有中断的优先级设置为0
  3. 当前核的priority_threshold设置为0
  4. 所有中断的中断处理例程都设置为rt_hw_interrupt_handle
  5. 设置mie寄存器，开启外中断

- rt_hw_interrupt_handle源码在libcpu/risc-v/k210/interrupt.c

  目前尚未对外中断进行处理，只是输出中断号

##### 核间中断

源码在`libcpu/risc-v/k210/interrupt.c`

函数rt_hw_client_ipi_enable用于初始化核间中断

- rtthread_startup --> rt_hw_board_init --> rt_hw_clint_ipi_enable

  此函数做的事仅仅是开启软中断