@地址按照4个字节对齐
.align 2
@.global 符号导出
.global main 

.text
main:
	push {r0-r12, lr}
	@printf("%s a = %d\n", "nihao", 50);
	ldr r0, =s		
	ldr r1, =ss
	ldr r2, =d1
	ldr r2, [r2, #8]
	bl printf
	pop {r0-r12, lr}
	bx lr
.data
d1:
	.word 30,40,50,60
d2:	
	.short 30,40
d3:
	.byte 30,40,50,60
s:	
	.string "%s a = %d\n"
	@.ascii "%s a = %d\n"
	@.word 0
ss:	
	.asciz "nihao"
.bss








