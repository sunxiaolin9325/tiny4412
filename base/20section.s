
Disassembly of section .text:

000082d4 <_start>:
    82d4:	e3a0b000 	mov	fp, #0
    82d8:	e3a0e000 	mov	lr, #0
    82dc:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    82e0:	e1a0200d 	mov	r2, sp
    82e4:	e52d2004 	push	{r2}		; (str r2, [sp, #-4]!)
    82e8:	e52d0004 	push	{r0}		; (str r0, [sp, #-4]!)
    82ec:	e59fc010 	ldr	ip, [pc, #16]	; 8304 <_start+0x30>
    82f0:	e52dc004 	push	{ip}		; (str ip, [sp, #-4]!)
    82f4:	e59f000c 	ldr	r0, [pc, #12]	; 8308 <_start+0x34>
    82f8:	e59f300c 	ldr	r3, [pc, #12]	; 830c <_start+0x38>
    82fc:	ebffffee 	bl	82bc <_init+0x2c>
    8300:	ebffffea 	bl	82b0 <_init+0x20>
    8304:	00008418 	andeq	r8, r0, r8, lsl r4
    8308:	00008380 	andeq	r8, r0, r0, lsl #7
    830c:	000083b0 	undefined instruction 0x000083b0

00008310 <call_gmon_start>:
    8310:	e59f3014 	ldr	r3, [pc, #20]	; 832c <call_gmon_start+0x1c>
    8314:	e59f2014 	ldr	r2, [pc, #20]	; 8330 <call_gmon_start+0x20>
    8318:	e08f3003 	add	r3, pc, r3
    831c:	e7932002 	ldr	r2, [r3, r2]
    8320:	e3520000 	cmp	r2, #0
    8324:	012fff1e 	bxeq	lr
    8328:	eaffffe6 	b	82c8 <_init+0x38>
    832c:	00008ce0 	andeq	r8, r0, r0, ror #25
    8330:	00000018 	andeq	r0, r0, r8, lsl r0

00008334 <__do_global_dtors_aux>:
    8334:	e59f3010 	ldr	r3, [pc, #16]	; 834c <__do_global_dtors_aux+0x18>
    8338:	e5d32000 	ldrb	r2, [r3]
    833c:	e3520000 	cmp	r2, #0
    8340:	03a02001 	moveq	r2, #1
    8344:	05c32000 	strbeq	r2, [r3]
    8348:	e12fff1e 	bx	lr
    834c:	00011030 	andeq	r1, r1, r0, lsr r0

00008350 <frame_dummy>:
    8350:	e59f0020 	ldr	r0, [pc, #32]	; 8378 <frame_dummy+0x28>
    8354:	e92d4008 	push	{r3, lr}
    8358:	e5903000 	ldr	r3, [r0]
    835c:	e3530000 	cmp	r3, #0
    8360:	08bd8008 	popeq	{r3, pc}
    8364:	e59f3010 	ldr	r3, [pc, #16]	; 837c <frame_dummy+0x2c>
    8368:	e3530000 	cmp	r3, #0
    836c:	08bd8008 	popeq	{r3, pc}
    8370:	e12fff33 	blx	r3
    8374:	e8bd8008 	pop	{r3, pc}
    8378:	00010f14 	andeq	r0, r1, r4, lsl pc
    837c:	00000000 	andeq	r0, r0, r0

00008380 <main>:
    8380:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
    8384:	e28db000 	add	fp, sp, #0
    8388:	e24dd00c 	sub	sp, sp, #12
    838c:	e3a03005 	mov	r3, #5
    8390:	e50b3008 	str	r3, [fp, #-8]
    8394:	e59f3010 	ldr	r3, [pc, #16]	; 83ac <main+0x2c>
    8398:	e50b300c 	str	r3, [fp, #-12]
    839c:	e1a00003 	mov	r0, r3
    83a0:	e28bd000 	add	sp, fp, #0
    83a4:	e8bd0800 	pop	{fp}
    83a8:	e12fff1e 	bx	lr
    83ac:	00008428 	andeq	r8, r0, r8, lsr #8

000083b0 <__libc_csu_init>:
    83b0:	e92d45f8 	push	{r3, r4, r5, r6, r7, r8, sl, lr}
    83b4:	e59f5050 	ldr	r5, [pc, #80]	; 840c <__libc_csu_init+0x5c>
    83b8:	e59fa050 	ldr	sl, [pc, #80]	; 8410 <__libc_csu_init+0x60>
    83bc:	e1a06000 	mov	r6, r0
    83c0:	e1a07001 	mov	r7, r1
    83c4:	e1a08002 	mov	r8, r2
    83c8:	ebffffb0 	bl	8290 <_init>
    83cc:	e59f3040 	ldr	r3, [pc, #64]	; 8414 <__libc_csu_init+0x64>
    83d0:	e065a00a 	rsb	sl, r5, sl
    83d4:	e08f3003 	add	r3, pc, r3
    83d8:	e1b0a14a 	asrs	sl, sl, #2
    83dc:	e0835005 	add	r5, r3, r5
    83e0:	08bd85f8 	popeq	{r3, r4, r5, r6, r7, r8, sl, pc}
    83e4:	e3a04000 	mov	r4, #0
    83e8:	e4953004 	ldr	r3, [r5], #4
    83ec:	e1a00006 	mov	r0, r6
    83f0:	e1a01007 	mov	r1, r7
    83f4:	e1a02008 	mov	r2, r8
    83f8:	e2844001 	add	r4, r4, #1
    83fc:	e12fff33 	blx	r3
    8400:	e154000a 	cmp	r4, sl
    8404:	3afffff7 	bcc	83e8 <__libc_csu_init+0x38>
    8408:	e8bd85f8 	pop	{r3, r4, r5, r6, r7, r8, sl, pc}
    840c:	ffffff0c 	undefined instruction 0xffffff0c
    8410:	ffffff10 	undefined instruction 0xffffff10
    8414:	00008c24 	andeq	r8, r0, r4, lsr #24

00008418 <__libc_csu_fini>:
    8418:	e12fff1e 	bx	lr

Disassembly of section .fini:

0000841c <_fini>:
    841c:	e92d4008 	push	{r3, lr}
    8420:	e8bd8008 	pop	{r3, pc}

Disassembly of section .rodata:

00008424 <_IO_stdin_used>:
    8424:	00020001 	andeq	r0, r2, r1
    8428:	6c6c6568 	cfstr64vs	mvdx6, [ip], #-416	; 0xfffffe60
    842c:	0000006f 	andeq	r0, r0, pc, rrx
    8430:	6168696e 	cmnvs	r8, lr, ror #18
    8434:	0000006f 	andeq	r0, r0, pc, rrx

Disassembly of section .ARM.exidx:

00008438 <.ARM.exidx>:
    8438:	7ffffe9c 	svcvc	0x00fffe9c
    843c:	00000001 	andeq	r0, r0, r1

Disassembly of section .eh_frame:

00008440 <__FRAME_END__>:
    8440:	00000000 	andeq	r0, r0, r0

Disassembly of section .init_array:

00010f0c <__frame_dummy_init_array_entry>:
   10f0c:	00008350 	andeq	r8, r0, r0, asr r3

Disassembly of section .fini_array:

00010f10 <__do_global_dtors_aux_fini_array_entry>:
   10f10:	00008334 	andeq	r8, r0, r4, lsr r3

Disassembly of section .jcr:

00010f14 <__JCR_END__>:
   10f14:	00000000 	andeq	r0, r0, r0

Disassembly of section .dynamic:

00010f18 <_DYNAMIC>:
   10f18:	00000001 	andeq	r0, r0, r1
   10f1c:	00000010 	andeq	r0, r0, r0, lsl r0
   10f20:	0000000c 	andeq	r0, r0, ip
   10f24:	00008290 	muleq	r0, r0, r2
   10f28:	0000000d 	andeq	r0, r0, sp
   10f2c:	0000841c 	andeq	r8, r0, ip, lsl r4
   10f30:	00000019 	andeq	r0, r0, r9, lsl r0
   10f34:	00010f0c 	andeq	r0, r1, ip, lsl #30
   10f38:	0000001b 	andeq	r0, r0, fp, lsl r0
   10f3c:	00000004 	andeq	r0, r0, r4
   10f40:	0000001a 	andeq	r0, r0, sl, lsl r0
   10f44:	00010f10 	andeq	r0, r1, r0, lsl pc
   10f48:	0000001c 	andeq	r0, r0, ip, lsl r0
   10f4c:	00000004 	andeq	r0, r0, r4
   10f50:	00000004 	andeq	r0, r0, r4
   10f54:	000081a8 	andeq	r8, r0, r8, lsr #3
   10f58:	00000005 	andeq	r0, r0, r5
   10f5c:	0000820c 	andeq	r8, r0, ip, lsl #4
   10f60:	00000006 	andeq	r0, r0, r6
   10f64:	000081cc 	andeq	r8, r0, ip, asr #3
   10f68:	0000000a 	andeq	r0, r0, sl
   10f6c:	0000003c 	andeq	r0, r0, ip, lsr r0
   10f70:	0000000b 	andeq	r0, r0, fp
   10f74:	00000010 	andeq	r0, r0, r0, lsl r0
   10f78:	00000015 	andeq	r0, r0, r5, lsl r0
   10f7c:	00000000 	andeq	r0, r0, r0
   10f80:	00000003 	andeq	r0, r0, r3
   10f84:	00011000 	andeq	r1, r1, r0
   10f88:	00000002 	andeq	r0, r0, r2
   10f8c:	00000018 	andeq	r0, r0, r8, lsl r0
   10f90:	00000014 	andeq	r0, r0, r4, lsl r0
   10f94:	00000011 	andeq	r0, r0, r1, lsl r0
   10f98:	00000017 	andeq	r0, r0, r7, lsl r0
   10f9c:	00008278 	andeq	r8, r0, r8, ror r2
   10fa0:	00000011 	andeq	r0, r0, r1, lsl r0
   10fa4:	00008270 	andeq	r8, r0, r0, ror r2
   10fa8:	00000012 	andeq	r0, r0, r2, lsl r0
   10fac:	00000008 	andeq	r0, r0, r8
   10fb0:	00000013 	andeq	r0, r0, r3, lsl r0
   10fb4:	00000008 	andeq	r0, r0, r8
   10fb8:	6ffffffe 	svcvs	0x00fffffe
   10fbc:	00008250 	andeq	r8, r0, r0, asr r2
   10fc0:	6fffffff 	svcvs	0x00ffffff
   10fc4:	00000001 	andeq	r0, r0, r1
   10fc8:	6ffffff0 	svcvs	0x00fffff0
   10fcc:	00008248 	andeq	r8, r0, r8, asr #4
	...

Disassembly of section .got:

00011000 <_GLOBAL_OFFSET_TABLE_>:
   11000:	00010f18 	andeq	r0, r1, r8, lsl pc
	...
   1100c:	0000829c 	muleq	r0, ip, r2
   11010:	0000829c 	muleq	r0, ip, r2
   11014:	0000829c 	muleq	r0, ip, r2
   11018:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

0001101c <__data_start>:
   1101c:	00000000 	andeq	r0, r0, r0

00011020 <__dso_handle>:
   11020:	00000000 	andeq	r0, r0, r0

00011024 <c>:
   11024:	00000001 	andeq	r0, r0, r1

00011028 <ss.1728>:
   11028:	00008430 	andeq	r8, r0, r0, lsr r4

0001102c <g.1726>:
   1102c:	00000006 	andeq	r0, r0, r6

Disassembly of section .bss:

00011030 <completed.5796>:
   11030:	00000000 	andeq	r0, r0, r0

00011034 <b>:
   11034:	00000000 	andeq	r0, r0, r0

00011038 <f.1725>:
   11038:	00000000 	andeq	r0, r0, r0

0001103c <a>:
   1103c:	00000000 	andeq	r0, r0, r0

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003541 	andeq	r3, r0, r1, asr #10
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	0000002b 	andeq	r0, r0, fp, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	36373131 	undefined instruction 0x36373131
  18:	2d465a4a 	vstrcs	s11, [r6, #-296]	; 0xfffffed8
  1c:	09060053 	stmdbeq	r6, {r0, r1, r4, r6}
  20:	01090108 	tsteq	r9, r8, lsl #2
  24:	0412020a 	ldreq	r0, [r2], #-522	; 0x20a
  28:	01150114 	tsteq	r5, r4, lsl r1
  2c:	01180317 	tsteq	r8, r7, lsl r3
  30:	021a0119 	andseq	r0, sl, #1073741830	; 0x40000006
  34:	Address 0x00000034 is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	3a434347 	bcc	10d0d24 <__bss_end__+0x10bfce4>
   4:	74632820 	strbtvc	r2, [r3], #-2080	; 0x820
   8:	312d676e 	teqcc	sp, lr, ror #14
   c:	312e382e 	teqcc	lr, lr, lsr #16
  10:	2941462d 	stmdbcs	r1, {r0, r2, r3, r5, r9, sl, lr}^
  14:	352e3420 	strcc	r3, [lr, #-1056]!	; 0x420
  18:	Address 0x00000018 is out of bounds.

