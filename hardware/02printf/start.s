@[zyli@Uboot]# dnw 50000000
@[root@PC]# dnw arm.bin
@[zyli@Uboot]# go 50000000

@ start.s  hardware.c main.c
@ start.o  hardware.o main.o
@     [ELF][s h m]
@        [s h m]
.align 2
.global _start

_start:
	b reset
	
reset:
	push {r0-r12, lr}	
	bl main
	pop {r0-r12, pc}





