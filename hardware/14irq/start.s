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
	ldr pc, swi_addr @0xffff0008	
	nop
	nop
	nop
	ldr pc, irq_addr @0xffff0018			
unde_addr:
.word unde	
swi_addr:
.word swi
irq_addr:
.word irq

reset:@uboot sp svc 
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
swi:@svc
	@mov sp, #0x74000000
	push {r0-r12, lr}
	@到目前为止lr中存放的还是swi指令的下一条指令的地址
 	@r0=*(lr-4)
	ldr r0, [lr, #-4]
	bic r0, r0, #0xff000000	
	@apcs
	bl do_swi
	pop {r0-r12, lr}
	movs pc, lr
irq:@irq
	mov sp, #0x75000000
	push {r0-r12, lr}
	bl do_irq
	pop {r0-r12, lr}
	subs pc, lr, #4	



