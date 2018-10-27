LINUX_SRC :=/home/lin/driver/linux-3.5

obj-m += nrf_dev.o nrf_drv.o
nrf_dev-objs = nrf24l01_dev.o
nrf_drv-objs = nrf24l01_drv.o nrf.o

all:
	make -C $(LINUX_SRC) M=`pwd` modules
	arm-linux-gcc nrf24l01_app.c -o nrf_app
clean:
	make -C $(LINUX_SRC) M=`pwd` modules clean
	rm nrf_app
install:
	cp *.ko *app /home/lin/object/myroot

	
