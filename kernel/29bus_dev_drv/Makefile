#LINUX_SRC :=/var/ftp/opt/linux-3.5
LINUX_SRC :=/home/lin/driver/linux-3.5

obj-m += ledbus.o redled_dev.o greenled_dev.o blueled_dev.o
obj-m += redled_drv.o greenled_drv.o blueled_drv.o

#obj-m += module_test1.o
all:
	make -C $(LINUX_SRC) M=`pwd` modules
clean:
	make -C $(LINUX_SRC) M=`pwd` modules clean
	
