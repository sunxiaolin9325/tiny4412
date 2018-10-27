
22location:     file format elf32-littlearm


Disassembly of section .text:
ear

60000000 <main>:
60000000:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
60000004:	e28db000 	add	fp, sp, #0
60000008:	e59f1020 	ldr	r1, [pc, #32]	; 50000030 <end+0x14>
6000000c:	e5910000 	ldr	r0, [r1]
60000010:	ea000001 	b	5000001c <end>

60000014 <nihao>:
60000014:	00000010 	andeq	r0, r0, r0, lsl r0
60000018:	00000020 	andeq	r0, r0, r0, lsr #32

6000001c <end>:
6000001c:	e3a03000 	mov	r3, #0
60000020:	e1a00003 	mov	r0, r3
60000024:	e28bd000 	add	sp, fp, #0
60000028:	e8bd0800 	pop	{fp}
6000002c:	e12fff1e 	bx	lr
60000030:	50000014 	andpl	r0, r0, r4, lsl r0

6isassembly of section .ARM.attributes:

60000000 <.ARM.attributes>:
6  0:	00003741 	andeq	r3, r0, r1, asr #14
6  4:	61656100 	cmnvs	r5, r0, lsl #2
6  8:	01006962 	tsteq	r0, r2, ror #18
   c:	0000002d 	andeq	r0, r0, sp, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	36373131 	undefined instruction 0x36373131
  18:	2d465a4a 	vstrcs	s11, [r6, #-296]	; 0xfffffed8
  1c:	09060053 	stmdbeq	r6, {r0, r1, r4, r6}
  20:	01090108 	tsteq	r9, r8, lsl #2
  24:	0412020a 	ldreq	r0, [r2], #-522	; 0x20a
  28:	01150114 	tsteq	r5, r4, lsl r1
  2c:	01180317 	tsteq	r8, r7, lsl r3
  30:	021a0119 	andseq	r0, sl, #1073741830	; 0x40000006
  34:	061e031b 	undefined instruction 0x061e031b

Disassembly of section .comment:

00000000 <.comment>:
   0:	3a434347 	bcc	10d0d24 <main-0x4ef2f2dc>
   4:	74632820 	strbtvc	r2, [r3], #-2080	; 0x820
   8:	312d676e 	teqcc	sp, lr, ror #14
   c:	312e382e 	teqcc	lr, lr, lsr #16
  10:	2941462d 	stmdbcs	r1, {r0, r2, r3, r5, r9, sl, lr}^
  14:	352e3420 	strcc	r3, [lr, #-1056]!	; 0x420
  18:	Address 0x00000018 is out of bounds.

