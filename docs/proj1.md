#### isp_auto.py

1. ISP_PROG是bootloader
2. 变量\__main__的值满足条件，执行if后面的内容
3. 分析传入的参数，并创建MAIXLoader对象
4. greeting
5. 刷入bootloader和内核
6. 启动

#### entry.S

1. 屏蔽中断
2. 设置栈(不同的核有不同的栈，为后续实验开启多核作准备)
3. 跳转到c语言的部分(第二个核目前只是在死循环里空跑)

#### init.c

1. 清空bss段

