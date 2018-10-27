LINUX_SRC :=/home/lin/driver/linux-3.5

#obj-m += module.o
#module-objs = relay_drv.o

obj-m += relay_drv.o
all:
	make -C $(LINUX_SRC) M=`pwd` modules
clean:
	make -C $(LINUX_SRC) M=`pwd` modules clean
	
