#LINUX_SRC :=/var/ftp/opt/linux-3.5
LINUX_SRC :=/home/lin/driver/linux-3.5

obj-m += module.o
module-objs = wdt_drv.o

#obj-m += module_test1.o
all:
	make -C $(LINUX_SRC) M=`pwd` modules
clean:
	make -C $(LINUX_SRC) M=`pwd` modules clean
	
