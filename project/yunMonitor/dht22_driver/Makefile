LINUX_SRC :=/home/lin/driver/linux-3.5

obj-m += dht22_dev.o dht22_drv.o

#obj-m += module_test1.o
all:
	make -C $(LINUX_SRC) M=`pwd` modules
clean:
	make -C $(LINUX_SRC) M=`pwd` modules clean
install:
	cp *.ko ~/object/myroot

	
