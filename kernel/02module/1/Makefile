LINUX_SRC :=/var/ftp/opt/linux-3.5

obj-m += module.o
module-objs = module_test1.o

#obj-m += module_test1.o
all:
	make -C $(LINUX_SRC) M=`pwd` modules
clean:
	make -C $(LINUX_SRC) M=`pwd` modules clean
	
