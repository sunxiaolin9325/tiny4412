LINUX_SRC :=/var/ftp/opt/linux-3.5

obj-m += button_dev.o button_drv.o

#obj-m += module_test1.o
all:
	make -C $(LINUX_SRC) M=`pwd` modules
clean:
	make -C $(LINUX_SRC) M=`pwd` modules clean
	
