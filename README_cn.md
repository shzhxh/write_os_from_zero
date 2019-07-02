开发中

第一阶段：打印Hello World

#### 前提条件

1. 电脑上要安装Linux系统
2. 要有gcc for riscv64工具链
3. 要有k210的开发板
4. 要安装python3、git

#### 下载

```
git clone https://github.com/shzhxh/write_os_from_zero.git
```

#### 运行

注：要把k210的开发板与电脑连接

```
cd write_os_from_zero
make k210
```

#### 资源

- k210
- Ucore
- RT_Thread
- Linux