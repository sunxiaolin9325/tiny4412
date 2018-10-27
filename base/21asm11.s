
21asm:     file format elf32-littlearm


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
    8338:	00008448 	andeq	r8, r0, r8, asr #8
    833c:	000083b4 	undefined instruction 0x000083b4
    8340:	000083e0 	andeq	r8, r0, r0, ror #7

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
    8380:	0001105e 	andeq	r1, r1, lr, asr r0

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
    83b4:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
    83b8:	e59f0014 	ldr	r0, [pc, #20]	; 83d4 <main+0x20>
    83bc:	e59f1014 	ldr	r1, [pc, #20]	; 83d8 <main+0x24>
    83c0:	e59f2014 	ldr	r2, [pc, #20]	; 83dc <main+0x28>
    83c4:	e5922008 	ldr	r2, [r2, #8]
    83c8:	ebffffcb 	bl	82fc <_init+0x44>
    83cc:	e8bd5fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
    83d0:	e12fff1e 	bx	lr
    83d4:	00011044 	andeq	r1, r1, r4, asr #32
    83d8:	00011059 	andeq	r1, r1, r9, asr r0
    83dc:	00011028 	andeq	r1, r1, r8, lsr #32

000083e0 <__libc_csu_init>:
    83e0:	e92d45f8 	push	{r3, r4, r5, r6, r7, r8, sl, lr}
    83e4:	e59f5050 	ldr	r5, [pc, #80]	; 843c <__libc_csu_init+0x5c>
    83e8:	e59fa050 	ldr	sl, [pc, #80]	; 8440 <__libc_csu_init+0x60>
    83ec:	e1a06000 	mov	r6, r0
    83f0:	e1a07001 	mov	r7, r1
    83f4:	e1a08002 	mov	r8, r2
    83f8:	ebffffae 	bl	82b8 <_init>
    83fc:	e59f3040 	ldr	r3, [pc, #64]	; 8444 <__libc_csu_init+0x64>
    8400:	e065a00a 	rsb	sl, r5, sl
    8404:	e08f3003 	add	r3, pc, r3
    8408:	e1b0a14a 	asrs	sl, sl, #2
    840c:	e0835005 	add	r5, r3, r5
    8410:	08bd85f8 	popeq	{r3, r4, r5, r6, r7, r8, sl, pc}
    8414:	e3a04000 	mov	r4, #0
    8418:	e4953004 	ldr	r3, [r5], #4
    841c:	e1a00006 	mov	r0, r6
    8420:	e1a01007 	mov	r1, r7
    8424:	e1a02008 	mov	r2, r8
    8428:	e2844001 	add	r4, r4, #1
    842c:	e12fff33 	blx	r3
    8430:	e154000a 	cmp	r4, sl
    8434:	3afffff7 	bcc	8418 <__libc_csu_init+0x38>
    8438:	e8bd85f8 	pop	{r3, r4, r5, r6, r7, r8, sl, pc}
    843c:	ffffff0c 	undefined instruction 0xffffff0c
    8440:	ffffff10 	undefined instruction 0xffffff10
    8444:	00008bf4 	strdeq	r8, [r0], -r4

00008448 <__libc_csu_fini>:
    8448:	e12fff1e 	bx	lr

Disassembly of section .fini:

0000844c <_fini>:
    844c:	e92d4008 	push	{r3, lr}
    8450:	e8bd8008 	pop	{r3, pc}

Disassembly of section .rodata:

00008454 <_IO_stdin_used>:
    8454:	00020001 	andeq	r0, r2, r1

Disassembly of section .ARM.exidx:

00008458 <.ARM.exidx>:
    8458:	7ffffeb0 	svcvc	0x00fffeb0
    845c:	00000001 	andeq	r0, r0, r1

Disassembly of section .eh_frame:

00008460 <__FRAME_END__>:
    8460:	00000000 	andeq	r0, r0, r0

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
   10f2c:	0000844c 	andeq	r8, r0, ip, asr #8
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

00011028 <d1>:
   11028:	0000001e 	andeq	r0, r0, lr, lsl r0
   1102c:	00000028 	andeq	r0, r0, r8, lsr #32
   11030:	00000032 	andeq	r0, r0, r2, lsr r0
   11034:	0000003c 	andeq	r0, r0, ip, lsr r0

00011038 <d2>:
   11038:	0028001e 	eoreq	r0, r8, lr, lsl r0
   1103c:	003c0032 	eorseq	r0, ip, r2, lsr r0

00011040 <d3>:
   11040:	3c32281e 	ldccc	8, cr2, [r2], #-120	; 0xffffff88

00011044 <s>:
   11044:	61207325 	teqvs	r0, r5, lsr #6
   11048:	25203d20 	strcs	r3, [r0, #-3360]!	; 0xd20
   1104c:	25000a64 	strcs	r0, [r0, #-2660]	; 0xa64
   11050:	20612073 	rsbcs	r2, r1, r3, ror r0
   11054:	6425203d 	strtvs	r2, [r5], #-61	; 0x3d
   11058:	68696e0a 	stmdavs	r9!, {r1, r3, r9, sl, fp, sp, lr}^

00011059 <ss>:
   11059:	6168696e 	cmnvs	r8, lr, ror #18
   1105d:	Address 0x0001105d is out of bounds.


Disassembly of section .bss:

0001105e <completed.5796>:
	...

Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003341 	andeq	r3, r0, r1, asr #6
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000029 	andeq	r0, r0, r9, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	36373131 	undefined instruction 0x36373131
  18:	2d465a4a 	vstrcs	s11, [r6, #-296]	; 0xfffffed8
  1c:	09060053 	stmdbeq	r6, {r0, r1, r4, r6}
  20:	01090108 	tsteq	r9, r8, lsl #2
  24:	0412020a 	ldreq	r0, [r2], #-522	; 0x20a
  28:	01150114 	tsteq	r5, r4, lsl r1
  2c:	01180317 	tsteq	r8, r7, lsl r3
  30:	031b021a 	tsteq	fp, #-1610612735	; 0xa0000001

Disassembly of section .comment:

00000000 <.comment>:
   0:	3a434347 	bcc	10d0d24 <__bss_end__+0x10bfcc4>
   4:	74632820 	strbtvc	r2, [r3], #-2080	; 0x820
   8:	312d676e 	teqcc	sp, lr, ror #14
   c:	312e382e 	teqcc	lr, lr, lsr #16
  10:	2941462d 	stmdbcs	r1, {r0, r2, r3, r5, r9, sl, lr}^
  14:	352e3420 	strcc	r3, [lr, #-1056]!	; 0x420
  18:	Address 0x00000018 is out of bounds.

