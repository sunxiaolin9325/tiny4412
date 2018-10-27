#all:
#	arm-linux-gcc -c -o main.o main.c -I./include
#	arm-linux-gcc -c -o driver.o driver.c -I./include
#	arm-linux-as start.s -o start.o
#	arm-linux-ld start.o main.o driver.o -o arm -Ttext 0x50000000
#	arm-linux-objcopy -O binary arm arm.bin

TARGET		:= arm
BIN		:= $(TARGET).bin
START_OBJ	:= start.o
OBJS		:= main.o lib.o mmu.o irq.o pwm.o backlight.o
LD_ADDR		:= 0x40008000

CROSS_COMPILE	:= arm-linux-

CC		:= $(CROSS_COMPILE)gcc
AS		:= $(CROSS_COMPILE)as
LD		:= $(CROSS_COMPILE)ld
OBJCOPY		:= $(CROSS_COMPILE)objcopy
OBJDUMP		:= $(CROSS_COMPILE)objdump
NM		:= $(CROSS_COMPILE)nm

INCLUDE 	:= ./include/

CFLAGS		+= -Wall -I$(INCLUDE)
#############################################################
all:$(TARGET)
	@$(OBJCOPY) -O binary $(TARGET) $(BIN)	
	@echo OBJCOPY	$<
	@$(NM) arm > System.map
	@echo NM	$<
	@$(OBJDUMP) -D $< > asm.s
	@echo OBJDUMP	$<
$(TARGET):$(START_OBJ) $(OBJS) 
	@$(LD) $^ -o $@ -Ttext $(LD_ADDR)
	@echo LD	$@

%.o:%.s
	@$(AS) $< -o $@	
	@echo AS	$@
%.o:%.c $(INCLUDE)%.h $(INCLUDE)common.h
	@$(CC) -c -o $@ $< $(CFLAGS)
	@echo CC	$@
clean:
	@$(RM) *.o $(TARGET) $(BIN)
	@echo RM	./



