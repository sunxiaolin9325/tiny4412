
04add:     file format elf32-littlearm


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
    81ac:	00000004 	andeq	r0, r0, r4
    81b0:	00000003 	andeq	r0, r0, r3
    81b4:	00000002 	andeq	r0, r0, r2
    81b8:	00000001 	andeq	r0, r0, r1
	...

Disassembly of section .dynsym:

000081cc <.dynsym>:
	...
    81dc:	0000001a 	andeq	r0, r0, sl, lsl r0
    81e0:	000082b0 	undefined instruction 0x000082b0
    81e4:	00000000 	andeq	r0, r0, r0
    81e8:	00000012 	andeq	r0, r0, r2, lsl r0
    81ec:	00000020 	andeq	r0, r0, r0, lsr #32
    81f0:	000082bc 	undefined instruction 0x000082bc
    81f4:	00000000 	andeq	r0, r0, r0
    81f8:	00000012 	andeq	r0, r0, r2, lsl r0
    81fc:	00000001 	andeq	r0, r0, r1
	...
    8208:	00000020 	andeq	r0, r0, r0, lsr #32

Disassembly of section .dynstr:

0000820c <.dynstr>:
    820c:	675f5f00 	ldrbvs	r5, [pc, -r0, lsl #30]
    8210:	5f6e6f6d 	svcpl	0x006e6f6d
    8214:	72617473 	rsbvc	r7, r1, #1929379840	; 0x73000000
    8218:	005f5f74 	subseq	r5, pc, r4, ror pc
    821c:	6362696c 	cmnvs	r2, #1769472	; 0x1b0000
    8220:	2e6f732e 	cdpcs	3, 6, cr7, cr15, cr14, {1}
    8224:	62610036 	rsbvs	r0, r1, #54	; 0x36
    8228:	0074726f 	rsbseq	r7, r4, pc, ror #4
    822c:	696c5f5f 	stmdbvs	ip!, {r0, r1, r2, r3, r4, r6, r8, r9, sl, fp, ip, lr}^
    8230:	735f6362 	cmpvc	pc, #-2013265919	; 0x88000001
    8234:	74726174 	ldrbtvc	r6, [r2], #-372	; 0x174
    8238:	69616d5f 	stmdbvs	r1!, {r0, r1, r2, r3, r4, r6, r8, sl, fp, sp, lr}^
    823c:	4c47006e 	mcrrmi	0, 6, r0, r7, cr14
    8240:	5f434249 	svcpl	0x00434249
    8244:	00342e32 	eorseq	r2, r4, r2, lsr lr

Disassembly of section .gnu.version:

00008248 <.gnu.version>:
    8248:	00020000 	andeq	r0, r2, r0
    824c:	00000002 	andeq	r0, r0, r2

Disassembly of section .gnu.version_r:

00008250 <.gnu.version_r>:
    8250:	00010001 	andeq	r0, r1, r1
    8254:	00000010 	andeq	r0, r0, r0, lsl r0
    8258:	00000010 	andeq	r0, r0, r0, lsl r0
    825c:	00000000 	andeq	r0, r0, r0
    8260:	0d696914 	stcleq	9, cr6, [r9, #-80]!	; 0xffffffb0
    8264:	00020000 	andeq	r0, r2, r0
    8268:	00000032 	andeq	r0, r0, r2, lsr r0
    826c:	00000000 	andeq	r0, r0, r0

Disassembly of section .rel.dyn:

00008270 <.rel.dyn>:
    8270:	00011018 	andeq	r1, r1, r8, lsl r0
    8274:	00000315 	andeq	r0, r0, r5, lsl r3

Disassembly of section .rel.plt:

00008278 <.rel.plt>:
    8278:	0001100c 	andeq	r1, r1, ip
    827c:	00000116 	andeq	r0, r0, r6, lsl r1
    8280:	00011010 	andeq	r1, r1, r0, lsl r0
    8284:	00000216 	andeq	r0, r0, r6, lsl r2
    8288:	00011014 	andeq	r1, r1, r4, lsl r0
    828c:	00000316 	andeq	r0, r0, r6, lsl r3

Disassembly of section .init:

00008290 <_init>:
    8290:	e92d4008 	push	{r3, lr}
    8294:	eb00001d 	bl	8310 <call_gmon_start>
    8298:	e8bd8008 	pop	{r3, pc}

Disassembly of section .plt:

0000829c <.plt>:
    829c:	e52de004 	push	{lr}		; (str lr, [sp, #-4]!)
    82a0:	e59fe004 	ldr	lr, [pc, #4]	; 82ac <_init+0x1c>
    82a4:	e08fe00e 	add	lr, pc, lr
    82a8:	e5bef008 	ldr	pc, [lr, #8]!
    82ac:	00008d54 	andeq	r8, r0, r4, asr sp
    82b0:	e28fc600 	add	ip, pc, #0
    82b4:	e28cca08 	add	ip, ip, #32768	; 0x8000
    82b8:	e5bcfd54 	ldr	pc, [ip, #3412]!	; 0xd54
    82bc:	e28fc600 	add	ip, pc, #0
    82c0:	e28cca08 	add	ip, ip, #32768	; 0x8000
    82c4:	e5bcfd4c 	ldr	pc, [ip, #3404]!	; 0xd4c
    82c8:	e28fc600 	add	ip, pc, #0
    82cc:	e28cca08 	add	ip, ip, #32768	; 0x8000
    82d0:	e5bcfd44 	ldr	pc, [ip, #3396]!	; 0xd44

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
    8304:	00008414 	andeq	r8, r0, r4, lsl r4
    8308:	00008380 	andeq	r8, r0, r0, lsl #7
    830c:	000083ac 	andeq	r8, r0, ip, lsr #7

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
    834c:	00011024 	andeq	r1, r1, r4, lsr #32

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
    838c:	e3a03000 	mov	r3, #0
    8390:	e50b3008 	str	r3, [fp, #-8]

    8394:	e3e00000 	mvn	r0, #0

    8398:	e3a03000 	mov	r3, #0
    839c:	e1a00003 	mov	r0, r3
    83a0:	e28bd000 	add	sp, fp, #0
    83a4:	e8bd0800 	pop	{fp}
    83a8:	e12fff1e 	bx	lr

000083ac <__libc_csu_init>:
    83ac:	e92d45f8 	push	{r3, r4, r5, r6, r7, r8, sl, lr}
    83b0:	e59f5050 	ldr	r5, [pc, #80]	; 8408 <__libc_csu_init+0x5c>
    83b4:	e59fa050 	ldr	sl, [pc, #80]	; 840c <__libc_csu_init+0x60>
    83b8:	e1a06000 	mov	r6, r0
    83bc:	e1a07001 	mov	r7, r1
    83c0:	e1a08002 	mov	r8, r2
    83c4:	ebffffb1 	bl	8290 <_init>
    83c8:	e59f3040 	ldr	r3, [pc, #64]	; 8410 <__libc_csu_init+0x64>
    83cc:	e065a00a 	rsb	sl, r5, sl
    83d0:	e08f3003 	add	r3, pc, r3
    83d4:	e1b0a14a 	asrs	sl, sl, #2
    83d8:	e0835005 	add	r5, r3, r5
    83dc:	08bd85f8 	popeq	{r3, r4, r5, r6, r7, r8, sl, pc}
    83e0:	e3a04000 	mov	r4, #0
    83e4:	e4953004 	ldr	r3, [r5], #4
    83e8:	e1a00006 	mov	r0, r6
    83ec:	e1a01007 	mov	r1, r7
    83f0:	e1a02008 	mov	r2, r8
    83f4:	e2844001 	add	r4, r4, #1
    83f8:	e12fff33 	blx	r3
    83fc:	e154000a 	cmp	r4, sl
    8400:	3afffff7 	bcc	83e4 <__libc_csu_init+0x38>
    8404:	e8bd85f8 	pop	{r3, r4, r5, r6, r7, r8, sl, pc}
    8408:	ffffff0c 	undefined instruction 0xffffff0c
    840c:	ffffff10 	undefined instruction 0xffffff10
    8410:	00008c28 	andeq	r8, r0, r8, lsr #24

00008414 <__libc_csu_fini>:
    8414:	e12fff1e 	bx	lr

Disassembly of section .fini:

00008418 <_fini>:
    8418:	e92d4008 	push	{r3, lr}
    841c:	e8bd8008 	pop	{r3, pc}

Disassembly of section .rodata:

00008420 <_IO_stdin_used>:
    8420:	00020001 	andeq	r0, r2, r1

Disassembly of section .ARM.exidx:

00008424 <.ARM.exidx>:
    8424:	7ffffeb0 	svcvc	0x00fffeb0
    8428:	00000001 	andeq	r0, r0, r1

Disassembly of section .eh_frame:

0000842c <__FRAME_END__>:
    842c:	00000000 	andeq	r0, r0, r0

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
   10f2c:	00008418 	andeq	r8, r0, r8, lsl r4
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

Disassembly of section .bss:

00011024 <completed.5796>:
   11024:	00000000 	andeq	r0, r0, r0

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
   0:	3a434347 	bcc	10d0d24 <__bss_end__+0x10bfcfc>
   4:	74632820 	strbtvc	r2, [r3], #-2080	; 0x820
   8:	312d676e 	teqcc	sp, lr, ror #14
   c:	312e382e 	teqcc	lr, lr, lsr #16
  10:	2941462d 	stmdbcs	r1, {r0, r2, r3, r5, r9, sl, lr}^
  14:	352e3420 	strcc	r3, [lr, #-1056]!	; 0x420
  18:	Address 0x00000018 is out of bounds.

