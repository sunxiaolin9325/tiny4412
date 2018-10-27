#all:
#	arm-linux-gcc main.c -c -o main.o -I./include
#	arm-linux-gcc hardware.c -c -o hardware.o -I./include
#	arm-linux-as start.s -o start.o
#	arm-linux-ld start.o main.o hardware.o -o arm -Ttext 0x50000000
#	arm-linux-objcopy -O binary arm arm.bin

TARGET		:=arm
BIN		:=$(TARGET).bin
LD_ADDR		:=0x50000000
START_OBJ	:=start.o
OBJS		:=main.o mmu.o

CROSS_COMPILE	:=arm-linux-
CC		:=$(CROSS_COMPILE)gcc
LD		:=$(CROSS_COMPILE)ld
AS		:=$(CROSS_COMPILE)as
OBJCOPY		:=$(CROSS_COMPILE)objcopy -O binary
OBJDUMP		:=$(CROSS_COMPILE)objdump -D
NM		:=$(CROSS_COMPILE)nm

CFLAGS		:=-I./include
LDFALGS		:=

RM		:=rm -rf
# make 
all:$(TARGET)
	$(OBJCOPY) $< $(BIN)
	$(OBJDUMP) $< > bin.s
	$(NM) $< > System.map

$(TARGET):$(START_OBJ) $(OBJS)
	$(LD) $^ -o $@ -Ttext $(LD_ADDR)

%.o:%.s
	$(AS) $< -o $@ 
%.o:%.c
	$(CC) -c -o $@ $< $(CFLAGS) 

clean:
	rm *.o $(TARGET) $(BIN) System.map  bin.s
	
	



