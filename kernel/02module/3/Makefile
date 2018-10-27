LINUX_SRC :=/home/lin/Embedded/tiny4412/kernel/linux-3.5/

obj-m += module_test1.o module_test2.o

#obj-m += module_test1.o
all:
	make -C $(LINUX_SRC) M=`pwd` modules
clean:
	make -C $(LINUX_SRC) M=`pwd` modules clean
	
