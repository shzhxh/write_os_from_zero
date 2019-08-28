#### 简介

要深入理解高楼大厦的结构先从自己建造茅草屋开始。所以我的目标是从零开始实现一个操作系统，以深入理解操作系统的原理。这个操作系统有如下特点：

1. 运行在真实的硬件[k210](https://kendryte.com/downloads/)开发板上
2. 基于[Ucore+](https://github.com/riscv-labs/OS2018spring-projects-g08)，并参考[RT_Thread](https://github.com/RT-Thread/rt-thread)和[Linux](https://github.com/torvalds/linux)
3. 在刚开始的时候就开启多核
4. 尽力的把文档写地详细一点，并在描述的时候严格控制抽象的层次

#### 快速开始

##### 前提条件

1. 电脑上要安装Linux系统

2. Linux系统上要安装gcc for riscv64工具链

   ```
   sudo apt install riscv64-linux-gnu
   ```

   

3. Linux系统上要安装python3、minicom、git

   ```
   pip3 install pyserial
   sudo apt install minicom
   ```

   

4. 要有k210的开发板

##### 运行

注：要把k210的开发板与电脑连接

```
git clone https://github.com/shzhxh/write_os_from_zero.git
cd write_os_from_zero
make k210
```

#### 开发进度

- [ ] [proj2-2](docs/proj2.md)：核间中断

- [x] [proj2-1](docs/proj2.md)：计时器中断

- [x] [proj1](docs/proj1.md)：打印Hello World