	.cpu arm1176jzf-s
	.eabi_attribute 27, 3
	.fpu vfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 2
	.eabi_attribute 30, 6
	.eabi_attribute 18, 4
	.file	"03in_out.c"
	.text
	.align	2
	.global	main
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 24
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	stmfd	sp!, {r4, r5, r6, r7, fp}
	add	fp, sp, #16
	sub	sp, sp, #28
	ldr	r3, [fp, #-24]
	ldr	ip, [fp, #-28]
	ldr	r4, [fp, #-32]
#APP
@ 15 "03in_out.c" 1
	mov r0, r3
mov r1, ip
mov r2, r4
mov r7, r0
mov r6, r1
mov r5, r2

@ 0 "" 2
	str	r7, [fp, #-36]
	str	r6, [fp, #-40]
	str	r5, [fp, #-44]
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #16
	ldmfd	sp!, {r4, r5, r6, r7, fp}
	bx	lr
	.size	main, .-main
	.ident	"GCC: (ctng-1.8.1-FA) 4.5.1"
	.section	.note.GNU-stack,"",%progbits
