#### isp_auto.py

1. ISP_PROG是bootloader
2. 变量\__main__的值满足条件，执行if后面的内容
3. 分析传入的参数，并创建MAIXLoader对象
4. greeting
5. 刷入bootloader和内核
6. 启动

#### entry.S

1. 整个内核的入口为_start，将mie置0的作用是屏蔽中断
2. 设置栈(不同的核有不同的栈，为后续实验开启多核作准备)
3. 跳转到c语言的部分kern_init(第二个核目前只是进入低功耗模式，等待被唤醒)

#### init.c

1. 在kern_init函数里，首先清空bss段
2. 执行uarths_puts函数输出Hello World

#### 输出字符串的原理

- 内核通过控制串口控制器来输出字符

- 串口控制器提供了7个32位寄存器供内核控制，它们被映射在内存地址0x38000000处

  |        | 名称               | 偏移地址 |
  | ------ | ------------------ | -------- |
  | txdata | 传递数据寄存器     | 0x00     |
  | rxdata | 接收数据寄存器     | 0x04     |
  | txctrl | 传输控制寄存器     | 0x08     |
  | rxctrl | 接收控制寄存器     | 0x0c     |
  | ie     | UART中断使能寄存器 | 0x10     |
  | ip     | UART中断等待寄存器 | 0x14     |
  | div    | 波特率分解寄存器   | 0x18     |

- 当txdata.full为0时，表明txdata.data内没有要传送的字符，此时向txdata.data写入数据将会把数据传送到串口输出