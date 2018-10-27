
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	eaffffff 	b	50000004 <reset>

50000004 <reset>:
50000004:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000008:	eb000000 	bl	50000010 <main>
5000000c:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

50000010 <main>:
50000010:	e92d4800 	push	{fp, lr}
50000014:	e28db004 	add	fp, sp, #4
50000018:	e24dd008 	sub	sp, sp, #8
5000001c:	e59f3074 	ldr	r3, [pc, #116]	; 50000098 <main+0x88>
50000020:	e50b3008 	str	r3, [fp, #-8]
50000024:	e51b3008 	ldr	r3, [fp, #-8]
50000028:	e3a02064 	mov	r2, #100	; 0x64
5000002c:	e5832000 	str	r2, [r3]
50000030:	e59f3064 	ldr	r3, [pc, #100]	; 5000009c <main+0x8c>
50000034:	e59f0064 	ldr	r0, [pc, #100]	; 500000a0 <main+0x90>
50000038:	e12fff33 	blx	r3
5000003c:	e3a00207 	mov	r0, #1879048192	; 0x70000000
50000040:	e3a01472 	mov	r1, #1912602624	; 0x72000000
50000044:	eb000028 	bl	500000ec <create_table>
50000048:	e59f0054 	ldr	r0, [pc, #84]	; 500000a4 <main+0x94>
5000004c:	e59f1044 	ldr	r1, [pc, #68]	; 50000098 <main+0x88>
50000050:	eb000060 	bl	500001d8 <my_mmap>
50000054:	eb000014 	bl	500000ac <mmu_enable>
50000058:	e59f3038 	ldr	r3, [pc, #56]	; 50000098 <main+0x88>
5000005c:	e5932000 	ldr	r2, [r3]
50000060:	e59f3034 	ldr	r3, [pc, #52]	; 5000009c <main+0x8c>
50000064:	e59f003c 	ldr	r0, [pc, #60]	; 500000a8 <main+0x98>
50000068:	e1a01002 	mov	r1, r2
5000006c:	e12fff33 	blx	r3
50000070:	e59f302c 	ldr	r3, [pc, #44]	; 500000a4 <main+0x94>
50000074:	e5932000 	ldr	r2, [r3]
50000078:	e59f301c 	ldr	r3, [pc, #28]	; 5000009c <main+0x8c>
5000007c:	e59f0024 	ldr	r0, [pc, #36]	; 500000a8 <main+0x98>
50000080:	e1a01002 	mov	r1, r2
50000084:	e12fff33 	blx	r3
50000088:	e3a03000 	mov	r3, #0
5000008c:	e1a00003 	mov	r0, r3
50000090:	e24bd004 	sub	sp, fp, #4
50000094:	e8bd8800 	pop	{fp, pc}
50000098:	62345678 	eorsvs	r5, r4, #125829120	; 0x7800000
5000009c:	43e11a2c 	mvnmi	r1, #180224	; 0x2c000
500000a0:	500002b4 	undefined instruction 0x500002b4
500000a4:	12345678 	eorsne	r5, r4, #125829120	; 0x7800000
500000a8:	500002c0 	andpl	r0, r0, r0, asr #5

500000ac <mmu_enable>:
500000ac:	e92d0810 	push	{r4, fp}
500000b0:	e28db004 	add	fp, sp, #4
500000b4:	ee114f10 	mrc	15, 0, r4, cr1, cr0, {0}
500000b8:	e3844001 	orr	r4, r4, #1
500000bc:	ee014f10 	mcr	15, 0, r4, cr1, cr0, {0}
500000c0:	e24bd004 	sub	sp, fp, #4
500000c4:	e8bd0810 	pop	{r4, fp}
500000c8:	e12fff1e 	bx	lr

500000cc <mmu_disable>:
500000cc:	e92d0810 	push	{r4, fp}
500000d0:	e28db004 	add	fp, sp, #4
500000d4:	ee114f10 	mrc	15, 0, r4, cr1, cr0, {0}
500000d8:	e3c44001 	bic	r4, r4, #1
500000dc:	ee014f10 	mcr	15, 0, r4, cr1, cr0, {0}
500000e0:	e24bd004 	sub	sp, fp, #4
500000e4:	e8bd0810 	pop	{r4, fp}
500000e8:	e12fff1e 	bx	lr

500000ec <create_table>:
500000ec:	e92d0810 	push	{r4, fp}
500000f0:	e28db004 	add	fp, sp, #4
500000f4:	e24dd018 	sub	sp, sp, #24
500000f8:	e50b0018 	str	r0, [fp, #-24]
500000fc:	e50b101c 	str	r1, [fp, #-28]
50000100:	e3a03000 	mov	r3, #0
50000104:	e50b3008 	str	r3, [fp, #-8]
50000108:	ea000027 	b	500001ac <create_table+0xc0>
5000010c:	e51b3008 	ldr	r3, [fp, #-8]
50000110:	e1a03a23 	lsr	r3, r3, #20
50000114:	e1a03103 	lsl	r3, r3, #2
50000118:	e51b2018 	ldr	r2, [fp, #-24]
5000011c:	e0822003 	add	r2, r2, r3
50000120:	e51b301c 	ldr	r3, [fp, #-28]
50000124:	e3c33fff 	bic	r3, r3, #1020	; 0x3fc
50000128:	e3c33003 	bic	r3, r3, #3
5000012c:	e3833001 	orr	r3, r3, #1
50000130:	e5823000 	str	r3, [r2]
50000134:	e51b3008 	ldr	r3, [fp, #-8]
50000138:	e50b300c 	str	r3, [fp, #-12]
5000013c:	ea00000f 	b	50000180 <create_table+0x94>
50000140:	e51b300c 	ldr	r3, [fp, #-12]
50000144:	e50b3010 	str	r3, [fp, #-16]
50000148:	e51b300c 	ldr	r3, [fp, #-12]
5000014c:	e1a03623 	lsr	r3, r3, #12
50000150:	e20330ff 	and	r3, r3, #255	; 0xff
50000154:	e1a03103 	lsl	r3, r3, #2
50000158:	e51b201c 	ldr	r2, [fp, #-28]
5000015c:	e0822003 	add	r2, r2, r3
50000160:	e51b3010 	ldr	r3, [fp, #-16]
50000164:	e3c33eff 	bic	r3, r3, #4080	; 0xff0
50000168:	e3c3300f 	bic	r3, r3, #15
5000016c:	e3833002 	orr	r3, r3, #2
50000170:	e5823000 	str	r3, [r2]
50000174:	e51b300c 	ldr	r3, [fp, #-12]
50000178:	e2833a01 	add	r3, r3, #4096	; 0x1000
5000017c:	e50b300c 	str	r3, [fp, #-12]
50000180:	e51b3008 	ldr	r3, [fp, #-8]
50000184:	e2832601 	add	r2, r3, #1048576	; 0x100000
50000188:	e51b300c 	ldr	r3, [fp, #-12]
5000018c:	e1520003 	cmp	r2, r3
50000190:	8affffea 	bhi	50000140 <create_table+0x54>
50000194:	e51b301c 	ldr	r3, [fp, #-28]
50000198:	e2833b01 	add	r3, r3, #1024	; 0x400
5000019c:	e50b301c 	str	r3, [fp, #-28]
500001a0:	e51b3008 	ldr	r3, [fp, #-8]
500001a4:	e2833601 	add	r3, r3, #1048576	; 0x100000
500001a8:	e50b3008 	str	r3, [fp, #-8]
500001ac:	e51b3008 	ldr	r3, [fp, #-8]
500001b0:	e3530000 	cmp	r3, #0
500001b4:	aaffffd4 	bge	5000010c <create_table+0x20>
500001b8:	ee134f10 	mrc	15, 0, r4, cr3, cr0, {0}
500001bc:	e3844003 	orr	r4, r4, #3
500001c0:	ee034f10 	mcr	15, 0, r4, cr3, cr0, {0}
500001c4:	e51b3018 	ldr	r3, [fp, #-24]
500001c8:	ee023f10 	mcr	15, 0, r3, cr2, cr0, {0}
500001cc:	e24bd004 	sub	sp, fp, #4
500001d0:	e8bd0810 	pop	{r4, fp}
500001d4:	e12fff1e 	bx	lr

500001d8 <my_mmap>:
500001d8:	e92d0810 	push	{r4, fp}
500001dc:	e28db004 	add	fp, sp, #4
500001e0:	e24dd018 	sub	sp, sp, #24
500001e4:	e50b0018 	str	r0, [fp, #-24]
500001e8:	e50b101c 	str	r1, [fp, #-28]
500001ec:	ee124f10 	mrc	15, 0, r4, cr2, cr0, {0}
500001f0:	e50b4008 	str	r4, [fp, #-8]
500001f4:	e51b3018 	ldr	r3, [fp, #-24]
500001f8:	e1a03a23 	lsr	r3, r3, #20
500001fc:	e1a03103 	lsl	r3, r3, #2
50000200:	e51b2008 	ldr	r2, [fp, #-8]
50000204:	e0823003 	add	r3, r2, r3
50000208:	e5933000 	ldr	r3, [r3]
5000020c:	e50b300c 	str	r3, [fp, #-12]
50000210:	e51b300c 	ldr	r3, [fp, #-12]
50000214:	e3c33fff 	bic	r3, r3, #1020	; 0x3fc
50000218:	e3c33003 	bic	r3, r3, #3
5000021c:	e50b3010 	str	r3, [fp, #-16]
50000220:	e51b3018 	ldr	r3, [fp, #-24]
50000224:	e1a03623 	lsr	r3, r3, #12
50000228:	e20330ff 	and	r3, r3, #255	; 0xff
5000022c:	e1a03103 	lsl	r3, r3, #2
50000230:	e51b2010 	ldr	r2, [fp, #-16]
50000234:	e0822003 	add	r2, r2, r3
50000238:	e51b3018 	ldr	r3, [fp, #-24]
5000023c:	e1a03623 	lsr	r3, r3, #12
50000240:	e20330ff 	and	r3, r3, #255	; 0xff
50000244:	e1a03103 	lsl	r3, r3, #2
50000248:	e51b1010 	ldr	r1, [fp, #-16]
5000024c:	e0813003 	add	r3, r1, r3
50000250:	e5933000 	ldr	r3, [r3]
50000254:	e1a03a03 	lsl	r3, r3, #20
50000258:	e1a03a23 	lsr	r3, r3, #20
5000025c:	e5823000 	str	r3, [r2]
50000260:	e51b3018 	ldr	r3, [fp, #-24]
50000264:	e1a03623 	lsr	r3, r3, #12
50000268:	e20330ff 	and	r3, r3, #255	; 0xff
5000026c:	e1a03103 	lsl	r3, r3, #2
50000270:	e51b2010 	ldr	r2, [fp, #-16]
50000274:	e0822003 	add	r2, r2, r3
50000278:	e51b3018 	ldr	r3, [fp, #-24]
5000027c:	e1a03623 	lsr	r3, r3, #12
50000280:	e20330ff 	and	r3, r3, #255	; 0xff
50000284:	e1a03103 	lsl	r3, r3, #2
50000288:	e51b1010 	ldr	r1, [fp, #-16]
5000028c:	e0813003 	add	r3, r1, r3
50000290:	e5931000 	ldr	r1, [r3]
50000294:	e51b301c 	ldr	r3, [fp, #-28]
50000298:	e3c33eff 	bic	r3, r3, #4080	; 0xff0
5000029c:	e3c3300f 	bic	r3, r3, #15
500002a0:	e1813003 	orr	r3, r1, r3
500002a4:	e5823000 	str	r3, [r2]
500002a8:	e24bd004 	sub	sp, fp, #4
500002ac:	e8bd0810 	pop	{r4, fp}
500002b0:	e12fff1e 	bx	lr

Disassembly of section .rodata:

500002b4 <.rodata>:
500002b4:	20756d6d 	rsbscs	r6, r5, sp, ror #26
500002b8:	72617473 	rsbvc	r7, r1, #1929379840	; 0x73000000
500002bc:	00000a74 	andeq	r0, r0, r4, ror sl
500002c0:	20756d6d 	rsbscs	r6, r5, sp, ror #26
500002c4:	76696c61 	strbtvc	r6, [r9], -r1, ror #24
500002c8:	64252065 	strtvs	r2, [r5], #-101	; 0x65
500002cc:	0000000a 	andeq	r0, r0, sl

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
   0:	3a434347 	bcc	10d0d24 <_start-0x4ef2f2dc>
   4:	74632820 	strbtvc	r2, [r3], #-2080	; 0x820
   8:	312d676e 	teqcc	sp, lr, ror #14
   c:	312e382e 	teqcc	lr, lr, lsr #16
  10:	2941462d 	stmdbcs	r1, {r0, r2, r3, r5, r9, sl, lr}^
  14:	352e3420 	strcc	r3, [lr, #-1056]!	; 0x420
  18:	Address 0x00000018 is out of bounds.

