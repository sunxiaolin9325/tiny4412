000083b4 <main>:
    83b4:	push	{fp, lr}
    83b8:	add	fp, sp, #4
    83bc:	sub	sp, sp, #8
    83c0:	mov	r3, #0
    83c4:	str	r3, [fp, #-8]
    83c8:	mov	r3, #0
    83cc:	str	r3, [fp, #-12]
    83d0:	ldr	r3, [fp, #-8]
    83d4:	add	r3, r3, #1
    83d8:	str	r3, [fp, #-8]
    83dc:	ldr	r2, [fp, #-8]
    83e0:	ldr	r3, [fp, #-8]
    83e4:	add	r2, r2, r3
    83e8:	ldr	r3, [fp, #-8]
    83ec:	add	r3, r3, #1
    83f0:	str	r3, [fp, #-8]
    83f4:	ldr	r3, [fp, #-8]
    83f8:	add	r2, r2, r3
    83fc:	ldr	r3, [fp, #-8]
    8400:	add	r2, r2, r3
    8404:	ldr	r3, [fp, #-8]
    8408:	add	r3, r2, r3
    840c:	str	r3, [fp, #-12]
    8410:	ldr	r3, [fp, #-8]
    8414:	add	r3, r3, #1
    8418:	str	r3, [fp, #-8]
    841c:	ldr	r3, [fp, #-8]
    8420:	add	r3, r3, #1
    8424:	str	r3, [fp, #-8]
    8428:	ldr	r3, [fp, #-8]
    842c:	add	r3, r3, #1
    8430:	str	r3, [fp, #-8]
    8434:	movw	r3, #34020	; 0x84e4
    8438:	movt	r3, #0
    843c:	mov	r0, r3
    8440:	ldr	r1, [fp, #-8]
    8444:	bl	82fc <_init+0x44>
    8448:	movw	r3, #34028	; 0x84ec
    844c:	movt	r3, #0
    8450:	mov	r0, r3
    8454:	ldr	r1, [fp, #-12]
    8458:	bl	82fc <_init+0x44>
    845c:	mov	r3, #0
    8460:	mov	r0, r3
    8464:	sub	sp, fp, #4
    8468:	pop	{fp, pc}

0000846c <__libc_csu_init>:
    846c:	e92d45f8 	push	{r3, r4, r5, r6, r7, r8, sl, lr}
    8470:	e59f5050 	ldr	r5, [pc, #80]	; 84c8 <__libc_csu_init+0x5c>
    8474:	e59fa050 	ldr	sl, [pc, #80]	; 84cc <__libc_csu_init+0x60>
    8478:	e1a06000 	mov	r6, r0
    847c:	e1a07001 	mov	r7, r1
    8480:	e1a08002 	mov	r8, r2
    8484:	ebffff8b 	bl	82b8 <_init>
    8488:	e59f3040 	ldr	r3, [pc, #64]	; 84d0 <__libc_csu_init+0x64>
    848c:	e065a00a 	rsb	sl, r5, sl
    8490:	e08f3003 	add	r3, pc, r3
    8494:	e1b0a14a 	asrs	sl, sl, #2
    8498:	e0835005 	add	r5, r3, r5
    849c:	08bd85f8 	popeq	{r3, r4, r5, r6, r7, r8, sl, pc}
    84a0:	e3a04000 	mov	r4, #0
    84a4:	e4953004 	ldr	r3, [r5], #4
    84a8:	e1a00006 	mov	r0, r6
    84ac:	e1a01007 	mov	r1, r7
    84b0:	e1a02008 	mov	r2, r8
    84b4:	e2844001 	add	r4, r4, #1
    84b8:	e12fff33 	blx	r3
    84bc:	e154000a 	cmp	r4, sl
    84c0:	3afffff7 	bcc	84a4 <__libc_csu_init+0x38>
    84c4:	e8bd85f8 	pop	{r3, r4, r5, r6, r7, r8, sl, pc}
    84c8:	ffffff0c 	undefined instruction 0xffffff0c
    84cc:	ffffff10 	undefined instruction 0xffffff10
    84d0:	00008b68 	andeq	r8, r0, r8, ror #22

000084d4 <__libc_csu_fini>:
    84d4:	e12fff1e 	bx	lr

Disassembly of section .fini:

000084d8 <_fini>:
    84d8:	e92d4008 	push	{r3, lr}
    84dc:	e8bd8008 	pop	{r3, pc}

Disassembly of section .rodata:

000084e0 <_IO_stdin_used>:
    84e0:	00020001 	andeq	r0, r2, r1
    84e4:	203d2069 	eorscs	r2, sp, r9, rrx
    84e8:	000a6425 	andeq	r6, sl, r5, lsr #8
    84ec:	203d206a 	eorscs	r2, sp, sl, rrx
    84f0:	000a6425 	andeq	r6, sl, r5, lsr #8

Disassembly of section .ARM.exidx:

000084f4 <.ARM.exidx>:
    84f4:	7ffffe14 	svcvc	0x00fffe14
    84f8:	00000001 	andeq	r0, r0, r1

Disassembly of section .eh_frame:

000084fc <__FRAME_END__>:
    84fc:	00000000 	andeq	r0, r0, r0

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
   10f2c:	000084d8 	ldrdeq	r8, [r0], -r8
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

