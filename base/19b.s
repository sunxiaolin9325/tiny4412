
19b:     file format elf32-littlearm


Disassembly of section .interp:

00008174 <.interp>:
    8174:	62696c2f 	rsbvs	r6, r9, #12032	; 0x2f00
    8178:	2d646c2f 	stclcs	12, cr6, [r4, #-188]!	; 0xffffff44
    817c:	756e696c 	strbvc	r6, [lr, #-2412]!	; 0x96c
    8180:	6f732e78 	svcvs	0x00732e78
    8184:	Address 0x00008184 is out of bounds.


Disassembly of section .note.ABI-tag:

00008188 <.note.ABI-tag>:
    8188:	00000004 	andeq	r0, r0, r4
    818c:	00000010 	andeq	r0, r0, r0, lsl r0
    8190:	00000001 	andeq	r0, r0, r1
    8194:	00554e47 	subseq	r4, r5, r7, asr #28
    8198:	00000000 	andeq	r0, r0, r0
    819c:	00000002 	andeq	r0, r0, r2
    81a0:	00000006 	andeq	r0, r0, r6
    81a4:	0000001b 	andeq	r0, r0, fp, lsl r0

Disassembly of section .hash:

000081a8 <.hash>:
    81a8:	00000003 	andeq	r0, r0, r3
    81ac:	00000005 	andeq	r0, r0, r5
    81b0:	00000003 	andeq	r0, r0, r3
    81b4:	00000002 	andeq	r0, r0, r2
    81b8:	00000004 	andeq	r0, r0, r4
	...
    81cc:	00000001 	andeq	r0, r0, r1

Disassembly of section .dynsym:

000081d0 <.dynsym>:
	...
    81e0:	0000001a 	andeq	r0, r0, sl, lsl r0
    81e4:	000082d8 	ldrdeq	r8, [r0], -r8
    81e8:	00000000 	andeq	r0, r0, r0
    81ec:	00000012 	andeq	r0, r0, r2, lsl r0
    81f0:	00000027 	andeq	r0, r0, r7, lsr #32
    81f4:	000082e4 	andeq	r8, r0, r4, ror #5
    81f8:	00000000 	andeq	r0, r0, r0
    81fc:	00000012 	andeq	r0, r0, r2, lsl r0
    8200:	00000001 	andeq	r0, r0, r1
	...
    820c:	00000020 	andeq	r0, r0, r0, lsr #32
    8210:	00000020 	andeq	r0, r0, r0, lsr #32
    8214:	000082fc 	strdeq	r8, [r0], -ip
    8218:	00000000 	andeq	r0, r0, r0
    821c:	00000012 	andeq	r0, r0, r2, lsl r0

Disassembly of section .dynstr:

00008220 <.dynstr>:
    8220:	675f5f00 	ldrbvs	r5, [pc, -r0, lsl #30]
    8224:	5f6e6f6d 	svcpl	0x006e6f6d
    8228:	72617473 	rsbvc	r7, r1, #1929379840	; 0x73000000
    822c:	005f5f74 	subseq	r5, pc, r4, ror pc
    8230:	6362696c 	cmnvs	r2, #1769472	; 0x1b0000
    8234:	2e6f732e 	cdpcs	3, 6, cr7, cr15, cr14, {1}
    8238:	62610036 	rsbvs	r0, r1, #54	; 0x36
    823c:	0074726f 	rsbseq	r7, r4, pc, ror #4
    8240:	6e697270 	mcrvs	2, 3, r7, cr9, cr0, {3}
    8244:	5f006674 	svcpl	0x00006674
    8248:	62696c5f 	rsbvs	r6, r9, #24320	; 0x5f00
    824c:	74735f63 	ldrbtvc	r5, [r3], #-3939	; 0xf63
    8250:	5f747261 	svcpl	0x00747261
    8254:	6e69616d 	powvsez	f6, f1, #5.0
    8258:	494c4700 	stmdbmi	ip, {r8, r9, sl, lr}^
    825c:	325f4342 	subscc	r4, pc, #134217729	; 0x8000001
    8260:	Address 0x00008260 is out of bounds.


Disassembly of section .gnu.version:

00008264 <.gnu.version>:
    8264:	00020000 	andeq	r0, r2, r0
    8268:	00000002 	andeq	r0, r0, r2
    826c:	Address 0x0000826c is out of bounds.


Disassembly of section .gnu.version_r:

00008270 <.gnu.version_r>:
    8270:	00010001 	andeq	r0, r1, r1
    8274:	00000010 	andeq	r0, r0, r0, lsl r0
    8278:	00000010 	andeq	r0, r0, r0, lsl r0
    827c:	00000000 	andeq	r0, r0, r0
    8280:	0d696914 	stcleq	9, cr6, [r9, #-80]!	; 0xffffffb0
    8284:	00020000 	andeq	r0, r2, r0
    8288:	00000039 	andeq	r0, r0, r9, lsr r0
    828c:	00000000 	andeq	r0, r0, r0

Disassembly of section .rel.dyn:

00008290 <.rel.dyn>:
    8290:	0001101c 	andeq	r1, r1, ip, lsl r0
    8294:	00000315 	andeq	r0, r0, r5, lsl r3

Disassembly of section .rel.plt:

00008298 <.rel.plt>:
    8298:	0001100c 	andeq	r1, r1, ip
    829c:	00000116 	andeq	r0, r0, r6, lsl r1
    82a0:	00011010 	andeq	r1, r1, r0, lsl r0
    82a4:	00000216 	andeq	r0, r0, r6, lsl r2
    82a8:	00011014 	andeq	r1, r1, r4, lsl r0
    82ac:	00000316 	andeq	r0, r0, r6, lsl r3
    82b0:	00011018 	andeq	r1, r1, r8, lsl r0
    82b4:	00000416 	andeq	r0, r0, r6, lsl r4

Disassembly of section .init:

000082b8 <_init>:
    82b8:	e92d4008 	push	{r3, lr}
    82bc:	eb000020 	bl	8344 <call_gmon_start>
    82c0:	e8bd8008 	pop	{r3, pc}

Disassembly of section .plt:

000082c4 <.plt>:
    82c4:	e52de004 	push	{lr}		; (str lr, [sp, #-4]!)
    82c8:	e59fe004 	ldr	lr, [pc, #4]	; 82d4 <_init+0x1c>
    82cc:	e08fe00e 	add	lr, pc, lr
    82d0:	e5bef008 	ldr	pc, [lr, #8]!
    82d4:	00008d2c 	andeq	r8, r0, ip, lsr #26
    82d8:	e28fc600 	add	ip, pc, #0
    82dc:	e28cca08 	add	ip, ip, #32768	; 0x8000
    82e0:	e5bcfd2c 	ldr	pc, [ip, #3372]!	; 0xd2c
    82e4:	e28fc600 	add	ip, pc, #0
    82e8:	e28cca08 	add	ip, ip, #32768	; 0x8000
    82ec:	e5bcfd24 	ldr	pc, [ip, #3364]!	; 0xd24
    82f0:	e28fc600 	add	ip, pc, #0
    82f4:	e28cca08 	add	ip, ip, #32768	; 0x8000
    82f8:	e5bcfd1c 	ldr	pc, [ip, #3356]!	; 0xd1c
    82fc:	e28fc600 	add	ip, pc, #0
    8300:	e28cca08 	add	ip, ip, #32768	; 0x8000
    8304:	e5bcfd14 	ldr	pc, [ip, #3348]!	; 0xd14

Disassembly of section .text:

00008308 <_start>:
    8308:	e3a0b000 	mov	fp, #0
    830c:	e3a0e000 	mov	lr, #0
    8310:	e49d1004 	pop	{r1}		; (ldr r1, [sp], #4)
    8314:	e1a0200d 	mov	r2, sp
    8318:	e52d2004 	push	{r2}		; (str r2, [sp, #-4]!)
    831c:	e52d0004 	push	{r0}		; (str r0, [sp, #-4]!)
    8320:	e59fc010 	ldr	ip, [pc, #16]	; 8338 <_start+0x30>
    8324:	e52dc004 	push	{ip}		; (str ip, [sp, #-4]!)
    8328:	e59f000c 	ldr	r0, [pc, #12]	; 833c <_start+0x34>
    832c:	e59f300c 	ldr	r3, [pc, #12]	; 8340 <_start+0x38>
    8330:	ebffffeb 	bl	82e4 <_init+0x2c>
    8334:	ebffffe7 	bl	82d8 <_init+0x20>
    8338:	00008544 	andeq	r8, r0, r4, asr #10
    833c:	000083b4 	undefined instruction 0x000083b4
    8340:	000084dc 	ldrdeq	r8, [r0], -ip

00008344 <call_gmon_start>:
    8344:	e59f3014 	ldr	r3, [pc, #20]	; 8360 <call_gmon_start+0x1c>
    8348:	e59f2014 	ldr	r2, [pc, #20]	; 8364 <call_gmon_start+0x20>
    834c:	e08f3003 	add	r3, pc, r3
    8350:	e7932002 	ldr	r2, [r3, r2]
    8354:	e3520000 	cmp	r2, #0
    8358:	012fff1e 	bxeq	lr
    835c:	eaffffe3 	b	82f0 <_init+0x38>
    8360:	00008cac 	andeq	r8, r0, ip, lsr #25
    8364:	0000001c 	andeq	r0, r0, ip, lsl r0

00008368 <__do_global_dtors_aux>:
    8368:	e59f3010 	ldr	r3, [pc, #16]	; 8380 <__do_global_dtors_aux+0x18>
    836c:	e5d32000 	ldrb	r2, [r3]
    8370:	e3520000 	cmp	r2, #0
    8374:	03a02001 	moveq	r2, #1
    8378:	05c32000 	strbeq	r2, [r3]
    837c:	e12fff1e 	bx	lr
    8380:	00011028 	andeq	r1, r1, r8, lsr #32

00008384 <frame_dummy>:
    8384:	e59f0020 	ldr	r0, [pc, #32]	; 83ac <frame_dummy+0x28>
    8388:	e92d4008 	push	{r3, lr}
    838c:	e5903000 	ldr	r3, [r0]
    8390:	e3530000 	cmp	r3, #0
    8394:	08bd8008 	popeq	{r3, pc}
    8398:	e59f3010 	ldr	r3, [pc, #16]	; 83b0 <frame_dummy+0x2c>
    839c:	e3530000 	cmp	r3, #0
    83a0:	08bd8008 	popeq	{r3, pc}
    83a4:	e12fff33 	blx	r3
    83a8:	e8bd8008 	pop	{r3, pc}
    83ac:	00010f14 	andeq	r0, r1, r4, lsl pc
    83b0:	00000000 	andeq	r0, r0, r0

000083b4 <main>:
    83b4:	push	{r4, fp, lr}
    83b8:	add	fp, sp, #8
    83bc:	sub	sp, sp, #12
    83c0:	mov	r0, #5
    83c4:	mov	r1, #6
    83c8:	push	{r0, r1}
    83cc:	mov	r0, #1
    83d0:	mov	r1, #2
    83d4:	mov	r2, #3
    83d8:	mov	r3, #4
    83dc:	bl	8410 <hello>
    83e0:	mov	r4, r0
    83e4:	add	sp, sp, #8
    83e8:	str	r4, [fp, #-16]
    83ec:	movw	r3, #34132	; 0x8554
    83f0:	movt	r3, #0
    83f4:	mov	r0, r3
    83f8:	ldr	r1, [fp, #-16]
    83fc:	bl	82fc <_init+0x44>
    8400:	mov	r3, #0
    8404:	mov	r0, r3
    8408:	sub	sp, fp, #8
    840c:	pop	{r4, fp, pc}

00008410 <hello>
    8410:	push	{fp, lr}
    8414:	add	fp, sp, #4
    8418:	sub	sp, sp, #16
    841c:	str	r0, [fp, #-8]
    8420:	str	r1, [fp, #-12]
    8424:	str	r2, [fp, #-16]
    8428:	str	r3, [fp, #-20]
    842c:	movw	r3, #34144	; 0x8560
    8430:	movt	r3, #0
    8434:	mov	r0, r3
    8438:	ldr	r1, [fp, #-8]
    843c:	bl	82fc <_init+0x44>
    8440:	movw	r3, #34152	; 0x8568
    8444:	movt	r3, #0
    8448:	mov	r0, r3
    844c:	ldr	r1, [fp, #-12]
    8450:	bl	82fc <_init+0x44>
    8454:	movw	r3, #34160	; 0x8570
    8458:	movt	r3, #0
    845c:	mov	r0, r3
    8460:	ldr	r1, [fp, #-16]
    8464:	bl	82fc <_init+0x44>
    8468:	movw	r3, #34168	; 0x8578
    846c:	movt	r3, #0
    8470:	mov	r0, r3
    8474:	ldr	r1, [fp, #-20]
    8478:	bl	82fc <_init+0x44>
    847c:	movw	r3, #34176	; 0x8580
    8480:	movt	r3, #0
    8484:	mov	r0, r3
    8488:	ldr	r1, [fp, #4]
    848c:	bl	82fc <_init+0x44>
    8490:	movw	r3, #34184	; 0x8588
    8494:	movt	r3, #0
    8498:	mov	r0, r3
    849c:	ldr	r1, [fp, #8]
    84a0:	bl	82fc <_init+0x44>
    84a4:	ldr	r2, [fp, #-8]
    84a8:	ldr	r3, [fp, #-12]
    84ac:	add	r2, r2, r3
    84b0:	ldr	r3, [fp, #-16]
    84b4:	add	r2, r2, r3
    84b8:	ldr	r3, [fp, #-20]
    84bc:	add	r2, r2, r3
    84c0:	ldr	r3, [fp, #4]
    84c4:	add	r2, r2, r3
    84c8:	ldr	r3, [fp, #8]
    84cc:	add	r3, r2, r3
    84d0:	mov	r0, r3
    84d4:	sub	sp, fp, #4
    84d8:	pop	{fp, pc}

000084dc <__libc_csu_init>:
    84dc:	e92d45f8 	push	{r3, r4, r5, r6, r7, r8, sl, lr}
    84e0:	e59f5050 	ldr	r5, [pc, #80]	; 8538 <__libc_csu_init+0x5c>
    84e4:	e59fa050 	ldr	sl, [pc, #80]	; 853c <__libc_csu_init+0x60>
    84e8:	e1a06000 	mov	r6, r0
    84ec:	e1a07001 	mov	r7, r1
    84f0:	e1a08002 	mov	r8, r2
    84f4:	ebffff6f 	bl	82b8 <_init>
    84f8:	e59f3040 	ldr	r3, [pc, #64]	; 8540 <__libc_csu_init+0x64>
    84fc:	e065a00a 	rsb	sl, r5, sl
    8500:	e08f3003 	add	r3, pc, r3
    8504:	e1b0a14a 	asrs	sl, sl, #2
    8508:	e0835005 	add	r5, r3, r5
    850c:	08bd85f8 	popeq	{r3, r4, r5, r6, r7, r8, sl, pc}
    8510:	e3a04000 	mov	r4, #0
    8514:	e4953004 	ldr	r3, [r5], #4
    8518:	e1a00006 	mov	r0, r6
    851c:	e1a01007 	mov	r1, r7
    8520:	e1a02008 	mov	r2, r8
    8524:	e2844001 	add	r4, r4, #1
    8528:	e12fff33 	blx	r3
    852c:	e154000a 	cmp	r4, sl
    8530:	3afffff7 	bcc	8514 <__libc_csu_init+0x38>
    8534:	e8bd85f8 	pop	{r3, r4, r5, r6, r7, r8, sl, pc}
    8538:	ffffff0c 	undefined instruction 0xffffff0c
    853c:	ffffff10 	undefined instruction 0xffffff10
    8540:	00008af8 	strdeq	r8, [r0], -r8

00008544 <__libc_csu_fini>:
    8544:	e12fff1e 	bx	lr

Disassembly of section .fini:

00008548 <_fini>:
    8548:	e92d4008 	push	{r3, lr}
    854c:	e8bd8008 	pop	{r3, pc}

Disassembly of section .rodata:

00008550 <_IO_stdin_used>:
    8550:	00020001 	andeq	r0, r2, r1
    8554:	67616c66 	strbvs	r6, [r1, -r6, ror #24]!
    8558:	25203d20 	strcs	r3, [r0, #-3360]!	; 0xd20
    855c:	00000a64 	andeq	r0, r0, r4, ror #20
    8560:	203d2061 	eorscs	r2, sp, r1, rrx
    8564:	000a6425 	andeq	r6, sl, r5, lsr #8
    8568:	203d2062 	eorscs	r2, sp, r2, rrx
    856c:	000a6425 	andeq	r6, sl, r5, lsr #8
    8570:	203d2063 	eorscs	r2, sp, r3, rrx
    8574:	000a6425 	andeq	r6, sl, r5, lsr #8
    8578:	203d2064 	eorscs	r2, sp, r4, rrx
    857c:	000a6425 	andeq	r6, sl, r5, lsr #8
    8580:	203d2065 	eorscs	r2, sp, r5, rrx
    8584:	000a6425 	andeq	r6, sl, r5, lsr #8
    8588:	203d2066 	eorscs	r2, sp, r6, rrx
    858c:	000a6425 	andeq	r6, sl, r5, lsr #8

Disassembly of section .ARM.exidx:

00008590 <.ARM.exidx>:
    8590:	7ffffd78 	svcvc	0x00fffd78
    8594:	00000001 	andeq	r0, r0, r1

Disassembly of section .eh_frame:

00008598 <__FRAME_END__>:
    8598:	00000000 	andeq	r0, r0, r0

Disassembly of section .init_array:

00010f0c <__frame_dummy_init_array_entry>:
   10f0c:	00008384 	andeq	r8, r0, r4, lsl #7

Disassembly of section .fini_array:

00010f10 <__do_global_dtors_aux_fini_array_entry>:
   10f10:	00008368 	andeq	r8, r0, r8, ror #6

Disassembly of section .jcr:

00010f14 <__JCR_END__>:
   10f14:	00000000 	andeq	r0, r0, r0

Disassembly of section .dynamic:

00010f18 <_DYNAMIC>:
   10f18:	00000001 	andeq	r0, r0, r1
   10f1c:	00000010 	andeq	r0, r0, r0, lsl r0
   10f20:	0000000c 	andeq	r0, r0, ip
   10f24:	000082b8 	undefined instruction 0x000082b8
   10f28:	0000000d 	andeq	r0, r0, sp
   10f2c:	00008548 	andeq	r8, r0, r8, asr #10
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
   10f5c:	00008220 	andeq	r8, r0, r0, lsr #4
   10f60:	00000006 	andeq	r0, r0, r6
   10f64:	000081d0 	ldrdeq	r8, [r0], -r0
   10f68:	0000000a 	andeq	r0, r0, sl
   10f6c:	00000043 	andeq	r0, r0, r3, asr #32
   10f70:	0000000b 	andeq	r0, r0, fp
   10f74:	00000010 	andeq	r0, r0, r0, lsl r0
   10f78:	00000015 	andeq	r0, r0, r5, lsl r0
   10f7c:	00000000 	andeq	r0, r0, r0
   10f80:	00000003 	andeq	r0, r0, r3
   10f84:	00011000 	andeq	r1, r1, r0
   10f88:	00000002 	andeq	r0, r0, r2
   10f8c:	00000020 	andeq	r0, r0, r0, lsr #32
   10f90:	00000014 	andeq	r0, r0, r4, lsl r0
   10f94:	00000011 	andeq	r0, r0, r1, lsl r0
   10f98:	00000017 	andeq	r0, r0, r7, lsl r0
   10f9c:	00008298 	muleq	r0, r8, r2
   10fa0:	00000011 	andeq	r0, r0, r1, lsl r0
   10fa4:	00008290 	muleq	r0, r0, r2
   10fa8:	00000012 	andeq	r0, r0, r2, lsl r0
   10fac:	00000008 	andeq	r0, r0, r8
   10fb0:	00000013 	andeq	r0, r0, r3, lsl r0
   10fb4:	00000008 	andeq	r0, r0, r8
   10fb8:	6ffffffe 	svcvs	0x00fffffe
   10fbc:	00008270 	andeq	r8, r0, r0, ror r2
   10fc0:	6fffffff 	svcvs	0x00ffffff
   10fc4:	00000001 	andeq	r0, r0, r1
   10fc8:	6ffffff0 	svcvs	0x00fffff0
   10fcc:	00008264 	andeq	r8, r0, r4, ror #4
	...

Disassembly of section .got:

00011000 <_GLOBAL_OFFSET_TABLE_>:
   11000:	00010f18 	andeq	r0, r1, r8, lsl pc
	...
   1100c:	000082c4 	andeq	r8, r0, r4, asr #5
   11010:	000082c4 	andeq	r8, r0, r4, asr #5
   11014:	000082c4 	andeq	r8, r0, r4, asr #5
   11018:	000082c4 	andeq	r8, r0, r4, asr #5
   1101c:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00011020 <__data_start>:
   11020:	00000000 	andeq	r0, r0, r0

00011024 <__dso_handle>:
   11024:	00000000 	andeq	r0, r0, r0

Disassembly of section .bss:

00011028 <completed.5796>:
   11028:	00000000 	andeq	r0, r0, r0

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002e41 	andeq	r2, r0, r1, asr #28
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000024 	andeq	r0, r0, r4, lsr #32
  10:	412d3705 	teqmi	sp, r5, lsl #14
  14:	070a0600 	streq	r0, [sl, -r0, lsl #12]
  18:	09010841 	stmdbeq	r1, {r0, r6, fp}
  1c:	12020a02 	andne	r0, r2, #8192	; 0x2000
  20:	15011404 	strne	r1, [r1, #-1028]	; 0x404
  24:	18031701 	stmdane	r3, {r0, r8, r9, sl, ip}
  28:	1a011901 	bne	46434 <__bss_end__+0x35408>
  2c:	Address 0x0000002c is out of bounds.


Disassembly of section .comment:

00000000 <.comment>:
   0:	3a434347 	bcc	10d0d24 <__bss_end__+0x10bfcf8>
   4:	74632820 	strbtvc	r2, [r3], #-2080	; 0x820
   8:	312d676e 	teqcc	sp, lr, ror #14
   c:	312e382e 	teqcc	lr, lr, lsr #16
  10:	2941462d 	stmdbcs	r1, {r0, r2, r3, r5, r9, sl, lr}^
  14:	352e3420 	strcc	r3, [lr, #-1056]!	; 0x420
  18:	Address 0x00000018 is out of bounds.

