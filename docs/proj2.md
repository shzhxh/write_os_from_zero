#### 简介

proj1的目的是实现一个可运行的系统，打印“Hello World”出来以看到它确实运行起来了。proj2的目标是让两个核都工作起来，而让两个核都要工作实际上是要建立整个中断系统。

#### 计时器中断的过程

clint是管理核间中断和计时器中断的设备。我想它应该不是一个外部设备，而是位于CPU内的设备，因为它是用来处理多个核的中断的，从结构上讲它应该是在“里面”的。

clint通过把寄存器映射到一段内存上来和外界交互。clint里共有3种寄存器：

- msip  :  每个核都有一个msip寄存器，将其置1可使对应的核接收到核间中断
- mtimecmp : 每个核都有一个mtimecmp寄存器，当它的值小于等于mtime寄存器时对应的核会产生计时器中断
- mtime : 仅一个，是系统的计时器，当它的值大于等于mtimecmp时将产生计时器中断

可见，mtimecmp和mtime这两个寄存器控制着计时器中断的产生。只要在计时器中断产生的时候给mtimecmp加上一个值，计时器中断就会不停地产生。计时器中断对操作系统是很重要的，就像操作系统的心跳。操作系统把它叫做一个tick(嘀嗒)，两个嘀嗒的间隔就叫tick_cycles。ucore和rt-thread每秒钟产生的tick都是100个，所以这里也也设定为每秒产生100个tick。

在clint里的设置只是计时器中断产生的条件，它要真正被对应的核接收，还需要设置mstatus寄存器和mie寄存器。mstatus寄存器控制要接收中断所在的特权级(机器级、内核级、用户级)，mie寄存器控制要接收中断的类型(软中断、计时器中断、外中断)。

一个计时器中断的具体过程：

1. 在clint_timer_init里进行中断的初始化
2. mtime寄存器不断增长，直到等于mtimecmp[core_id]产生计时器中断
3. 查询mstatus和mie寄存器的值，判断允许接收计时器中断
4. 读取mtvec寄存器的值，即__alltraps的地址，跳转过去继续执行
5. 执行宏SAVE_ALL的指令，保存中断前的上下文
6. 跳转到trap函数继续执行
7. mcause小于0，是中断；cause的值为7，是计时器中断(IRQ_M_TIMER)。
8. 给mtimecmp加上tick_cycles使计时器中断周期性地产生，然后向屏幕输出字符串"ticks"让我们知道计时器中断确实产生了。但每秒输出100次太快了，所以控制它每秒输出一次。
9. trap函数返回，回到__alltraps
10. 执行宏RESTORE_ALL的指令，恢复中断前的上下文
11. 从中断返回

#### 核间中断

核间中断的最简设计就是让两个核交替工作了，这应该包含两个方面的工作：

- 建立核间中断的机制
- 建立自旋锁的机制

#### rt-thread对于中断的管理

##### 设置mtvec寄存器

- 源码在`libcpu/risc-v/k210/startup_gcc.S`

  在`_start`标记里把trap_entry的地址保存在mtvec寄存器里。mtvec寄存器用以保存中断处理例程的入口，当中断发生时就跳转到mtvec所保存的地址去执行。

- trap_entry的源码在`libcpu/risc-v/k210/interrupt_gcc.S`

  1. 将通过寄存器的值保存在栈中，即保存上下文
  2. 获取sp和mhartid的值
  3. 切换到当前CPU的𣏾(每个核都有自己的𣏾寄存器，个人认为此步无意义)
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

#### Linux对于中断的管理

调用次序似乎是`_start-->.Lsecondary_start-->smp_callin-->trap_init-->handle_exception`
[中断系统基本原理](https://blog.csdn.net/droidphone/article/details/7445825)
