LINUX_SRC	:=/home/lin/driver/linux-3.5
#obj-m		+=adc_dev.o adc_drv.o
obj-m		+=adc_drv.o

all:
	make -C $(LINUX_SRC) M=`pwd` modules
clean:
	make -C $(LINUX_SRC) M=`pwd` modules clean
