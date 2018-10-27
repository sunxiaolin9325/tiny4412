@go 50000000  
@start.s + main.c + drvier.c

.global start
.global end

.global _start
_start:
	b reset@0x50000000 0xffff0000
	b unde@0x50000004  0xffff0004
	b swi@		   0xffff0008
	b pre_bot@         0xffff000c
	b dat_bot@         0xffff0010
	.word 0x00@	   0xffff0014
	b irq@             0xffff0018
	b fiq@
reset:@svc
	stmfd sp!, {r0-r12, lr}
	
	@设置高端向量表
	mrc p15, 0, r0, c1, c0, 0
	orr r0, r0, #(1 << 13)
	mcr p15, 0, r0, c1, c0, 0

	bl main
	ldmfd sp!, {r0-r12, pc}
unde:@unde
swi:@svc
pre_bot:
dat_bot:
irq:@irq
	mov sp, #0x52000000
	sub lr, lr, #4
	stmfd sp!, {r0-r12, lr}
	mov lr, pc
	ldr pc, _do_irq
	ldmfd sp!, {r0-r12, pc}^
_do_irq:
	.word do_irq
fiq:	

_end:

start:
	.word _start
end:
	.word _end







