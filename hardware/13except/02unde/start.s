@[zyli@Uboot]# dnw 50000000
@[root@PC]# dnw arm.bin
@[zyli@Uboot]# go 50000000

@ start.s  hardware.c main.c
@ start.o  hardware.o main.o
@     [ELF][s h m]
@        [s h m]

	@ 32 [xxxx|xxxx|24]

.align 2
.global _start

_start:
	b reset	@0x50000000 ----> 0xffff0000
	ldr pc, unde_addr@0x50000004------> 0xffff0004
unde_addr:
.word unde	

reset:
	push {r0-r12, lr}	
	@设置高端向量表 
	mrc p15, 0, r4, c1, c0, 0
	orr r4, r4, #(1 << 13)
	mcr p15, 0, r4, c1, c0, 0
	bl main
	pop {r0-r12, pc}
unde:
	mov sp, #0x73000000
	push {r0-r12, lr}	
	bl do_unde	@0x50000014
	pop {r0-r12, lr}
	movs pc, lr





