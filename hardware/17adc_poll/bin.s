
arm:     file format elf32-littlearm


Disassembly of section .text:

50000000 <_start>:
50000000:	ea000008 	b	50000028 <reset>
50000004:	e59ff010 	ldr	pc, [pc, #16]	; 5000001c <unde_addr>
50000008:	e59ff010 	ldr	pc, [pc, #16]	; 50000020 <swi_addr>
5000000c:	e1a00000 	nop			; (mov r0, r0)
50000010:	e1a00000 	nop			; (mov r0, r0)
50000014:	e1a00000 	nop			; (mov r0, r0)
50000018:	e59ff004 	ldr	pc, [pc, #4]	; 50000024 <irq_addr>

5000001c <unde_addr>:
5000001c:	50000040 	andpl	r0, r0, r0, asr #32

50000020 <swi_addr>:
50000020:	50000050 	andpl	r0, r0, r0, asr r0

50000024 <irq_addr>:
50000024:	50000068 	andpl	r0, r0, r8, rrx

50000028 <reset>:
50000028:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
5000002c:	ee114f10 	mrc	15, 0, r4, cr1, cr0, {0}
50000030:	e3844a02 	orr	r4, r4, #8192	; 0x2000
50000034:	ee014f10 	mcr	15, 0, r4, cr1, cr0, {0}
50000038:	eb00000f 	bl	5000007c <main>
5000003c:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

50000040 <unde>:
50000040:	e3a0d473 	mov	sp, #1929379840	; 0x73000000
50000044:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000048:	e8bd5fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
5000004c:	e1b0f00e 	movs	pc, lr

50000050 <swi>:
50000050:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000054:	e51e0004 	ldr	r0, [lr, #-4]
50000058:	e3c004ff 	bic	r0, r0, #-16777216	; 0xff000000
5000005c:	eb0000e7 	bl	50000400 <do_swi>
50000060:	e8bd5fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000064:	e1b0f00e 	movs	pc, lr

50000068 <irq>:
50000068:	e3a0d475 	mov	sp, #1962934272	; 0x75000000
5000006c:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000070:	eb0000ef 	bl	50000434 <do_irq>
50000074:	e8bd5fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
50000078:	e25ef004 	subs	pc, lr, #4

5000007c <main>:
5000007c:	e92d4800 	push	{fp, lr}
50000080:	e28db004 	add	fp, sp, #4
50000084:	e3a00207 	mov	r0, #1879048192	; 0x70000000
50000088:	eb000029 	bl	50000134 <create_table>
5000008c:	e59f004c 	ldr	r0, [pc, #76]	; 500000e0 <main+0x64>
50000090:	e3a01472 	mov	r1, #1912602624	; 0x72000000
50000094:	eb000047 	bl	500001b8 <my_mmap>
50000098:	eb000015 	bl	500000f4 <mmu_enable>
5000009c:	e59f003c 	ldr	r0, [pc, #60]	; 500000e0 <main+0x64>
500000a0:	e3a01205 	mov	r1, #1342177280	; 0x50000000
500000a4:	e3a02028 	mov	r2, #40	; 0x28
500000a8:	eb000056 	bl	50000208 <memcpy>
500000ac:	eb0001ca 	bl	500007dc <adc_init>
500000b0:	eb0001d8 	bl	50000818 <adc_start>
500000b4:	eb0001e2 	bl	50000844 <wait_for_adc>
500000b8:	eb0001ed 	bl	50000874 <get_adc>
500000bc:	e1a02000 	mov	r2, r0
500000c0:	e59f301c 	ldr	r3, [pc, #28]	; 500000e4 <main+0x68>
500000c4:	e59f001c 	ldr	r0, [pc, #28]	; 500000e8 <main+0x6c>
500000c8:	e1a01002 	mov	r1, r2
500000cc:	e12fff33 	blx	r3
500000d0:	e59f3014 	ldr	r3, [pc, #20]	; 500000ec <main+0x70>
500000d4:	e59f0014 	ldr	r0, [pc, #20]	; 500000f0 <main+0x74>
500000d8:	e12fff33 	blx	r3
500000dc:	eafffff3 	b	500000b0 <main+0x34>
500000e0:	ffff0000 	undefined instruction 0xffff0000
500000e4:	43e11a2c 	mvnmi	r1, #180224	; 0x2c000
500000e8:	500008a0 	andpl	r0, r0, r0, lsr #17
500000ec:	43e26480 	mvnmi	r6, #-2147483648	; 0x80000000
500000f0:	0007a120 	andeq	sl, r7, r0, lsr #2

500000f4 <mmu_enable>:
500000f4:	e92d0810 	push	{r4, fp}
500000f8:	e28db004 	add	fp, sp, #4
500000fc:	ee114f10 	mrc	15, 0, r4, cr1, cr0, {0}
50000100:	e3844001 	orr	r4, r4, #1
50000104:	ee014f10 	mcr	15, 0, r4, cr1, cr0, {0}
50000108:	e24bd004 	sub	sp, fp, #4
5000010c:	e8bd0810 	pop	{r4, fp}
50000110:	e12fff1e 	bx	lr

50000114 <mmu_disable>:
50000114:	e92d0810 	push	{r4, fp}
50000118:	e28db004 	add	fp, sp, #4
5000011c:	ee114f10 	mrc	15, 0, r4, cr1, cr0, {0}
50000120:	e3c44001 	bic	r4, r4, #1
50000124:	ee014f10 	mcr	15, 0, r4, cr1, cr0, {0}
50000128:	e24bd004 	sub	sp, fp, #4
5000012c:	e8bd0810 	pop	{r4, fp}
50000130:	e12fff1e 	bx	lr

50000134 <create_table>:
50000134:	e92d0810 	push	{r4, fp}
50000138:	e28db004 	add	fp, sp, #4
5000013c:	e24dd010 	sub	sp, sp, #16
50000140:	e50b0010 	str	r0, [fp, #-16]
50000144:	e3a03000 	mov	r3, #0
50000148:	e50b3008 	str	r3, [fp, #-8]
5000014c:	ea00000e 	b	5000018c <create_table+0x58>
50000150:	e51b3008 	ldr	r3, [fp, #-8]
50000154:	e50b300c 	str	r3, [fp, #-12]
50000158:	e51b3008 	ldr	r3, [fp, #-8]
5000015c:	e1a03a23 	lsr	r3, r3, #20
50000160:	e1a03103 	lsl	r3, r3, #2
50000164:	e51b2010 	ldr	r2, [fp, #-16]
50000168:	e0822003 	add	r2, r2, r3
5000016c:	e51b300c 	ldr	r3, [fp, #-12]
50000170:	e1a03a23 	lsr	r3, r3, #20
50000174:	e1a03a03 	lsl	r3, r3, #20
50000178:	e3833002 	orr	r3, r3, #2
5000017c:	e5823000 	str	r3, [r2]
50000180:	e51b3008 	ldr	r3, [fp, #-8]
50000184:	e2833601 	add	r3, r3, #1048576	; 0x100000
50000188:	e50b3008 	str	r3, [fp, #-8]
5000018c:	e51b3008 	ldr	r3, [fp, #-8]
50000190:	e3530000 	cmp	r3, #0
50000194:	aaffffed 	bge	50000150 <create_table+0x1c>
50000198:	ee134f10 	mrc	15, 0, r4, cr3, cr0, {0}
5000019c:	e3844003 	orr	r4, r4, #3
500001a0:	ee034f10 	mcr	15, 0, r4, cr3, cr0, {0}
500001a4:	e51b3010 	ldr	r3, [fp, #-16]
500001a8:	ee023f10 	mcr	15, 0, r3, cr2, cr0, {0}
500001ac:	e24bd004 	sub	sp, fp, #4
500001b0:	e8bd0810 	pop	{r4, fp}
500001b4:	e12fff1e 	bx	lr

500001b8 <my_mmap>:
500001b8:	e92d0810 	push	{r4, fp}
500001bc:	e28db004 	add	fp, sp, #4
500001c0:	e24dd010 	sub	sp, sp, #16
500001c4:	e50b0010 	str	r0, [fp, #-16]
500001c8:	e50b1014 	str	r1, [fp, #-20]
500001cc:	ee124f10 	mrc	15, 0, r4, cr2, cr0, {0}
500001d0:	e50b4008 	str	r4, [fp, #-8]
500001d4:	e51b3010 	ldr	r3, [fp, #-16]
500001d8:	e1a03a23 	lsr	r3, r3, #20
500001dc:	e1a03103 	lsl	r3, r3, #2
500001e0:	e51b2008 	ldr	r2, [fp, #-8]
500001e4:	e0822003 	add	r2, r2, r3
500001e8:	e51b3014 	ldr	r3, [fp, #-20]
500001ec:	e1a03a23 	lsr	r3, r3, #20
500001f0:	e1a03a03 	lsl	r3, r3, #20
500001f4:	e3833002 	orr	r3, r3, #2
500001f8:	e5823000 	str	r3, [r2]
500001fc:	e24bd004 	sub	sp, fp, #4
50000200:	e8bd0810 	pop	{r4, fp}
50000204:	e12fff1e 	bx	lr

50000208 <memcpy>:
50000208:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
5000020c:	e28db000 	add	fp, sp, #0
50000210:	e24dd01c 	sub	sp, sp, #28
50000214:	e50b0010 	str	r0, [fp, #-16]
50000218:	e50b1014 	str	r1, [fp, #-20]
5000021c:	e50b2018 	str	r2, [fp, #-24]
50000220:	e51b3010 	ldr	r3, [fp, #-16]
50000224:	e50b3008 	str	r3, [fp, #-8]
50000228:	e51b3014 	ldr	r3, [fp, #-20]
5000022c:	e50b300c 	str	r3, [fp, #-12]
50000230:	ea000009 	b	5000025c <memcpy+0x54>
50000234:	e51b300c 	ldr	r3, [fp, #-12]
50000238:	e5d32000 	ldrb	r2, [r3]
5000023c:	e51b3008 	ldr	r3, [fp, #-8]
50000240:	e5c32000 	strb	r2, [r3]
50000244:	e51b3008 	ldr	r3, [fp, #-8]
50000248:	e2833001 	add	r3, r3, #1
5000024c:	e50b3008 	str	r3, [fp, #-8]
50000250:	e51b300c 	ldr	r3, [fp, #-12]
50000254:	e2833001 	add	r3, r3, #1
50000258:	e50b300c 	str	r3, [fp, #-12]
5000025c:	e51b3018 	ldr	r3, [fp, #-24]
50000260:	e3530000 	cmp	r3, #0
50000264:	03a03000 	moveq	r3, #0
50000268:	13a03001 	movne	r3, #1
5000026c:	e6ef3073 	uxtb	r3, r3
50000270:	e51b2018 	ldr	r2, [fp, #-24]
50000274:	e2422001 	sub	r2, r2, #1
50000278:	e50b2018 	str	r2, [fp, #-24]
5000027c:	e3530000 	cmp	r3, #0
50000280:	1affffeb 	bne	50000234 <memcpy+0x2c>
50000284:	e51b3010 	ldr	r3, [fp, #-16]
50000288:	e1a00003 	mov	r0, r3
5000028c:	e28bd000 	add	sp, fp, #0
50000290:	e8bd0800 	pop	{fp}
50000294:	e12fff1e 	bx	lr

50000298 <delay>:
50000298:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
5000029c:	e28db000 	add	fp, sp, #0
500002a0:	e24dd014 	sub	sp, sp, #20
500002a4:	e50b0010 	str	r0, [fp, #-16]
500002a8:	e3a03000 	mov	r3, #0
500002ac:	e50b3008 	str	r3, [fp, #-8]
500002b0:	ea00000c 	b	500002e8 <delay+0x50>
500002b4:	e3a03000 	mov	r3, #0
500002b8:	e50b300c 	str	r3, [fp, #-12]
500002bc:	ea000002 	b	500002cc <delay+0x34>
500002c0:	e51b300c 	ldr	r3, [fp, #-12]
500002c4:	e2833001 	add	r3, r3, #1
500002c8:	e50b300c 	str	r3, [fp, #-12]
500002cc:	e51b200c 	ldr	r2, [fp, #-12]
500002d0:	e59f302c 	ldr	r3, [pc, #44]	; 50000304 <delay+0x6c>
500002d4:	e1520003 	cmp	r2, r3
500002d8:	dafffff8 	ble	500002c0 <delay+0x28>
500002dc:	e51b3008 	ldr	r3, [fp, #-8]
500002e0:	e2833001 	add	r3, r3, #1
500002e4:	e50b3008 	str	r3, [fp, #-8]
500002e8:	e51b2008 	ldr	r2, [fp, #-8]
500002ec:	e51b3010 	ldr	r3, [fp, #-16]
500002f0:	e1520003 	cmp	r2, r3
500002f4:	baffffee 	blt	500002b4 <delay+0x1c>
500002f8:	e28bd000 	add	sp, fp, #0
500002fc:	e8bd0800 	pop	{fp}
50000300:	e12fff1e 	bx	lr
50000304:	0000270f 	andeq	r2, r0, pc, lsl #14

50000308 <add>:
50000308:	e92d4800 	push	{fp, lr}
5000030c:	e28db004 	add	fp, sp, #4
50000310:	e59f300c 	ldr	r3, [pc, #12]	; 50000324 <add+0x1c>
50000314:	e59f000c 	ldr	r0, [pc, #12]	; 50000328 <add+0x20>
50000318:	e59f100c 	ldr	r1, [pc, #12]	; 5000032c <add+0x24>
5000031c:	e12fff33 	blx	r3
50000320:	e8bd8800 	pop	{fp, pc}
50000324:	43e11a2c 	mvnmi	r1, #180224	; 0x2c000
50000328:	500008a4 	andpl	r0, r0, r4, lsr #17
5000032c:	500008b4 	undefined instruction 0x500008b4

50000330 <sub>:
50000330:	e92d4800 	push	{fp, lr}
50000334:	e28db004 	add	fp, sp, #4
50000338:	e59f300c 	ldr	r3, [pc, #12]	; 5000034c <sub+0x1c>
5000033c:	e59f000c 	ldr	r0, [pc, #12]	; 50000350 <sub+0x20>
50000340:	e59f100c 	ldr	r1, [pc, #12]	; 50000354 <sub+0x24>
50000344:	e12fff33 	blx	r3
50000348:	e8bd8800 	pop	{fp, pc}
5000034c:	43e11a2c 	mvnmi	r1, #180224	; 0x2c000
50000350:	500008a4 	andpl	r0, r0, r4, lsr #17
50000354:	500008b0 	undefined instruction 0x500008b0

50000358 <mul>:
50000358:	e92d4800 	push	{fp, lr}
5000035c:	e28db004 	add	fp, sp, #4
50000360:	e59f300c 	ldr	r3, [pc, #12]	; 50000374 <mul+0x1c>
50000364:	e59f000c 	ldr	r0, [pc, #12]	; 50000378 <mul+0x20>
50000368:	e59f100c 	ldr	r1, [pc, #12]	; 5000037c <mul+0x24>
5000036c:	e12fff33 	blx	r3
50000370:	e8bd8800 	pop	{fp, pc}
50000374:	43e11a2c 	mvnmi	r1, #180224	; 0x2c000
50000378:	500008a4 	andpl	r0, r0, r4, lsr #17
5000037c:	500008ac 	andpl	r0, r0, ip, lsr #17

50000380 <div>:
50000380:	e92d4800 	push	{fp, lr}
50000384:	e28db004 	add	fp, sp, #4
50000388:	e59f300c 	ldr	r3, [pc, #12]	; 5000039c <div+0x1c>
5000038c:	e59f000c 	ldr	r0, [pc, #12]	; 500003a0 <div+0x20>
50000390:	e59f100c 	ldr	r1, [pc, #12]	; 500003a4 <div+0x24>
50000394:	e12fff33 	blx	r3
50000398:	e8bd8800 	pop	{fp, pc}
5000039c:	43e11a2c 	mvnmi	r1, #180224	; 0x2c000
500003a0:	500008a4 	andpl	r0, r0, r4, lsr #17
500003a4:	500008a8 	andpl	r0, r0, r8, lsr #17

500003a8 <set_handler>:
500003a8:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
500003ac:	e28db000 	add	fp, sp, #0
500003b0:	e59f3034 	ldr	r3, [pc, #52]	; 500003ec <set_handler+0x44>
500003b4:	e59f2034 	ldr	r2, [pc, #52]	; 500003f0 <set_handler+0x48>
500003b8:	e5832000 	str	r2, [r3]
500003bc:	e59f3028 	ldr	r3, [pc, #40]	; 500003ec <set_handler+0x44>
500003c0:	e59f202c 	ldr	r2, [pc, #44]	; 500003f4 <set_handler+0x4c>
500003c4:	e5832004 	str	r2, [r3, #4]
500003c8:	e59f301c 	ldr	r3, [pc, #28]	; 500003ec <set_handler+0x44>
500003cc:	e59f2024 	ldr	r2, [pc, #36]	; 500003f8 <set_handler+0x50>
500003d0:	e5832008 	str	r2, [r3, #8]
500003d4:	e59f3010 	ldr	r3, [pc, #16]	; 500003ec <set_handler+0x44>
500003d8:	e59f201c 	ldr	r2, [pc, #28]	; 500003fc <set_handler+0x54>
500003dc:	e583200c 	str	r2, [r3, #12]
500003e0:	e28bd000 	add	sp, fp, #0
500003e4:	e8bd0800 	pop	{fp}
500003e8:	e12fff1e 	bx	lr
500003ec:	500088cc 	andpl	r8, r0, ip, asr #17
500003f0:	50000308 	andpl	r0, r0, r8, lsl #6
500003f4:	50000330 	andpl	r0, r0, r0, lsr r3
500003f8:	50000358 	andpl	r0, r0, r8, asr r3
500003fc:	50000380 	andpl	r0, r0, r0, lsl #7

50000400 <do_swi>:
50000400:	e92d4800 	push	{fp, lr}
50000404:	e28db004 	add	fp, sp, #4
50000408:	e24dd010 	sub	sp, sp, #16
5000040c:	e50b0010 	str	r0, [fp, #-16]
50000410:	e59f3018 	ldr	r3, [pc, #24]	; 50000430 <do_swi+0x30>
50000414:	e51b2010 	ldr	r2, [fp, #-16]
50000418:	e7933102 	ldr	r3, [r3, r2, lsl #2]
5000041c:	e50b3008 	str	r3, [fp, #-8]
50000420:	e51b3008 	ldr	r3, [fp, #-8]
50000424:	e12fff33 	blx	r3
50000428:	e24bd004 	sub	sp, fp, #4
5000042c:	e8bd8800 	pop	{fp, pc}
50000430:	500088cc 	andpl	r8, r0, ip, asr #17

50000434 <do_irq>:
50000434:	e92d4800 	push	{fp, lr}
50000438:	e28db004 	add	fp, sp, #4
5000043c:	e24dd008 	sub	sp, sp, #8
50000440:	e59f3030 	ldr	r3, [pc, #48]	; 50000478 <do_irq+0x44>
50000444:	e5933000 	ldr	r3, [r3]
50000448:	e50b3008 	str	r3, [fp, #-8]
5000044c:	e51b3008 	ldr	r3, [fp, #-8]
50000450:	e1a03b03 	lsl	r3, r3, #22
50000454:	e1a03b23 	lsr	r3, r3, #22
50000458:	e59f201c 	ldr	r2, [pc, #28]	; 5000047c <do_irq+0x48>
5000045c:	e7923103 	ldr	r3, [r2, r3, lsl #2]
50000460:	e12fff33 	blx	r3
50000464:	e59f3014 	ldr	r3, [pc, #20]	; 50000480 <do_irq+0x4c>
50000468:	e51b2008 	ldr	r2, [fp, #-8]
5000046c:	e5832000 	str	r2, [r3]
50000470:	e24bd004 	sub	sp, fp, #4
50000474:	e8bd8800 	pop	{fp, pc}
50000478:	1048000c 	subne	r0, r8, ip
5000047c:	500088dc 	ldrdpl	r8, [r0], -ip
50000480:	10480010 	subne	r0, r8, r0, lsl r0

50000484 <request_irq>:
50000484:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
50000488:	e28db000 	add	fp, sp, #0
5000048c:	e24dd00c 	sub	sp, sp, #12
50000490:	e50b0008 	str	r0, [fp, #-8]
50000494:	e50b100c 	str	r1, [fp, #-12]
50000498:	e59f3170 	ldr	r3, [pc, #368]	; 50000610 <request_irq+0x18c>
5000049c:	e3a02001 	mov	r2, #1
500004a0:	e5832000 	str	r2, [r3]
500004a4:	e59f3168 	ldr	r3, [pc, #360]	; 50000614 <request_irq+0x190>
500004a8:	e3a02001 	mov	r2, #1
500004ac:	e5832000 	str	r2, [r3]
500004b0:	e59f3160 	ldr	r3, [pc, #352]	; 50000618 <request_irq+0x194>
500004b4:	e3a020ff 	mov	r2, #255	; 0xff
500004b8:	e5832000 	str	r2, [r3]
500004bc:	e51b3008 	ldr	r3, [fp, #-8]
500004c0:	e283201f 	add	r2, r3, #31
500004c4:	e3530000 	cmp	r3, #0
500004c8:	b1a03002 	movlt	r3, r2
500004cc:	e1a032c3 	asr	r3, r3, #5
500004d0:	e1a02003 	mov	r2, r3
500004d4:	e1a03002 	mov	r3, r2
500004d8:	e1a01103 	lsl	r1, r3, #2
500004dc:	e59f3138 	ldr	r3, [pc, #312]	; 5000061c <request_irq+0x198>
500004e0:	e0813003 	add	r3, r1, r3
500004e4:	e1a01102 	lsl	r1, r2, #2
500004e8:	e59f212c 	ldr	r2, [pc, #300]	; 5000061c <request_irq+0x198>
500004ec:	e0812002 	add	r2, r1, r2
500004f0:	e5920000 	ldr	r0, [r2]
500004f4:	e51b1008 	ldr	r1, [fp, #-8]
500004f8:	e1a02fc1 	asr	r2, r1, #31
500004fc:	e1a02da2 	lsr	r2, r2, #27
50000500:	e0811002 	add	r1, r1, r2
50000504:	e201101f 	and	r1, r1, #31
50000508:	e0622001 	rsb	r2, r2, r1
5000050c:	e3a01001 	mov	r1, #1
50000510:	e1a02211 	lsl	r2, r1, r2
50000514:	e1802002 	orr	r2, r0, r2
50000518:	e5832000 	str	r2, [r3]
5000051c:	e51b3008 	ldr	r3, [fp, #-8]
50000520:	e2433020 	sub	r3, r3, #32
50000524:	e2832003 	add	r2, r3, #3
50000528:	e3530000 	cmp	r3, #0
5000052c:	b1a03002 	movlt	r3, r2
50000530:	e1a03143 	asr	r3, r3, #2
50000534:	e1a02003 	mov	r2, r3
50000538:	e1a03002 	mov	r3, r2
5000053c:	e1a01103 	lsl	r1, r3, #2
50000540:	e59f30d8 	ldr	r3, [pc, #216]	; 50000620 <request_irq+0x19c>
50000544:	e0813003 	add	r3, r1, r3
50000548:	e1a01102 	lsl	r1, r2, #2
5000054c:	e59f20cc 	ldr	r2, [pc, #204]	; 50000620 <request_irq+0x19c>
50000550:	e0812002 	add	r2, r1, r2
50000554:	e5920000 	ldr	r0, [r2]
50000558:	e51b1008 	ldr	r1, [fp, #-8]
5000055c:	e1a02fc1 	asr	r2, r1, #31
50000560:	e1a02f22 	lsr	r2, r2, #30
50000564:	e0811002 	add	r1, r1, r2
50000568:	e2011003 	and	r1, r1, #3
5000056c:	e0622001 	rsb	r2, r2, r1
50000570:	e1a02182 	lsl	r2, r2, #3
50000574:	e3a010ff 	mov	r1, #255	; 0xff
50000578:	e1a02211 	lsl	r2, r1, r2
5000057c:	e1e02002 	mvn	r2, r2
50000580:	e0002002 	and	r2, r0, r2
50000584:	e5832000 	str	r2, [r3]
50000588:	e51b3008 	ldr	r3, [fp, #-8]
5000058c:	e2433020 	sub	r3, r3, #32
50000590:	e2832003 	add	r2, r3, #3
50000594:	e3530000 	cmp	r3, #0
50000598:	b1a03002 	movlt	r3, r2
5000059c:	e1a03143 	asr	r3, r3, #2
500005a0:	e1a02003 	mov	r2, r3
500005a4:	e1a03002 	mov	r3, r2
500005a8:	e1a01103 	lsl	r1, r3, #2
500005ac:	e59f3070 	ldr	r3, [pc, #112]	; 50000624 <request_irq+0x1a0>
500005b0:	e0813003 	add	r3, r1, r3
500005b4:	e1a01102 	lsl	r1, r2, #2
500005b8:	e59f2064 	ldr	r2, [pc, #100]	; 50000624 <request_irq+0x1a0>
500005bc:	e0812002 	add	r2, r1, r2
500005c0:	e5920000 	ldr	r0, [r2]
500005c4:	e51b1008 	ldr	r1, [fp, #-8]
500005c8:	e1a02fc1 	asr	r2, r1, #31
500005cc:	e1a02f22 	lsr	r2, r2, #30
500005d0:	e0811002 	add	r1, r1, r2
500005d4:	e2011003 	and	r1, r1, #3
500005d8:	e0622001 	rsb	r2, r2, r1
500005dc:	e1a02182 	lsl	r2, r2, #3
500005e0:	e3a01001 	mov	r1, #1
500005e4:	e1a02211 	lsl	r2, r1, r2
500005e8:	e1802002 	orr	r2, r0, r2
500005ec:	e5832000 	str	r2, [r3]
500005f0:	e59f3030 	ldr	r3, [pc, #48]	; 50000628 <request_irq+0x1a4>
500005f4:	e51b2008 	ldr	r2, [fp, #-8]
500005f8:	e51b100c 	ldr	r1, [fp, #-12]
500005fc:	e7831102 	str	r1, [r3, r2, lsl #2]
50000600:	f1080080 	cpsie	i
50000604:	e28bd000 	add	sp, fp, #0
50000608:	e8bd0800 	pop	{fp}
5000060c:	e12fff1e 	bx	lr
50000610:	10480000 	subne	r0, r8, r0
50000614:	10490000 	subne	r0, r9, r0
50000618:	10480004 	subne	r0, r8, r4
5000061c:	10490100 	subne	r0, r9, r0, lsl #2
50000620:	10490420 	subne	r0, r9, r0, lsr #8
50000624:	10490820 	subne	r0, r9, r0, lsr #16
50000628:	500088dc 	ldrdpl	r8, [r0], -ip

5000062c <wdt_init>:
5000062c:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
50000630:	e28db000 	add	fp, sp, #0
50000634:	e24dd00c 	sub	sp, sp, #12
50000638:	e50b0008 	str	r0, [fp, #-8]
5000063c:	e59f3030 	ldr	r3, [pc, #48]	; 50000674 <wdt_init+0x48>
50000640:	e59f2030 	ldr	r2, [pc, #48]	; 50000678 <wdt_init+0x4c>
50000644:	e5832000 	str	r2, [r3]
50000648:	e59f302c 	ldr	r3, [pc, #44]	; 5000067c <wdt_init+0x50>
5000064c:	e51b2008 	ldr	r2, [fp, #-8]
50000650:	e1a02202 	lsl	r2, r2, #4
50000654:	e5832000 	str	r2, [r3]
50000658:	e59f3020 	ldr	r3, [pc, #32]	; 50000680 <wdt_init+0x54>
5000065c:	e51b2008 	ldr	r2, [fp, #-8]
50000660:	e1a02202 	lsl	r2, r2, #4
50000664:	e5832000 	str	r2, [r3]
50000668:	e28bd000 	add	sp, fp, #0
5000066c:	e8bd0800 	pop	{fp}
50000670:	e12fff1e 	bx	lr
50000674:	10060000 	andne	r0, r6, r0
50000678:	00006310 	andeq	r6, r0, r0, lsl r3
5000067c:	10060008 	andne	r0, r6, r8
50000680:	10060004 	andne	r0, r6, r4

50000684 <wdt_enable>:
50000684:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
50000688:	e28db000 	add	fp, sp, #0
5000068c:	e59f3018 	ldr	r3, [pc, #24]	; 500006ac <wdt_enable+0x28>
50000690:	e59f2014 	ldr	r2, [pc, #20]	; 500006ac <wdt_enable+0x28>
50000694:	e5922000 	ldr	r2, [r2]
50000698:	e3822020 	orr	r2, r2, #32
5000069c:	e5832000 	str	r2, [r3]
500006a0:	e28bd000 	add	sp, fp, #0
500006a4:	e8bd0800 	pop	{fp}
500006a8:	e12fff1e 	bx	lr
500006ac:	10060000 	andne	r0, r6, r0

500006b0 <wdt_disable>:
500006b0:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
500006b4:	e28db000 	add	fp, sp, #0
500006b8:	e59f3018 	ldr	r3, [pc, #24]	; 500006d8 <wdt_disable+0x28>
500006bc:	e59f2014 	ldr	r2, [pc, #20]	; 500006d8 <wdt_disable+0x28>
500006c0:	e5922000 	ldr	r2, [r2]
500006c4:	e3c22020 	bic	r2, r2, #32
500006c8:	e5832000 	str	r2, [r3]
500006cc:	e28bd000 	add	sp, fp, #0
500006d0:	e8bd0800 	pop	{fp}
500006d4:	e12fff1e 	bx	lr
500006d8:	10060000 	andne	r0, r6, r0

500006dc <do_wdt>:
500006dc:	e92d4800 	push	{fp, lr}
500006e0:	e28db004 	add	fp, sp, #4
500006e4:	e59f3014 	ldr	r3, [pc, #20]	; 50000700 <do_wdt+0x24>
500006e8:	e59f0014 	ldr	r0, [pc, #20]	; 50000704 <do_wdt+0x28>
500006ec:	e12fff33 	blx	r3
500006f0:	e59f3010 	ldr	r3, [pc, #16]	; 50000708 <do_wdt+0x2c>
500006f4:	e3a02001 	mov	r2, #1
500006f8:	e5832000 	str	r2, [r3]
500006fc:	e8bd8800 	pop	{fp, pc}
50000700:	43e11a2c 	mvnmi	r1, #180224	; 0x2c000
50000704:	500008b8 	undefined instruction 0x500008b8
50000708:	1006000c 	andne	r0, r6, ip

5000070c <wdt_irq_init>:
5000070c:	e92d4800 	push	{fp, lr}
50000710:	e28db004 	add	fp, sp, #4
50000714:	e24dd008 	sub	sp, sp, #8
50000718:	e50b0008 	str	r0, [fp, #-8]
5000071c:	e51b0008 	ldr	r0, [fp, #-8]
50000720:	ebffffc1 	bl	5000062c <wdt_init>
50000724:	e59f3038 	ldr	r3, [pc, #56]	; 50000764 <wdt_irq_init+0x58>
50000728:	e59f2034 	ldr	r2, [pc, #52]	; 50000764 <wdt_irq_init+0x58>
5000072c:	e5922000 	ldr	r2, [r2]
50000730:	e3c22007 	bic	r2, r2, #7
50000734:	e5832000 	str	r2, [r3]
50000738:	e59f3024 	ldr	r3, [pc, #36]	; 50000764 <wdt_irq_init+0x58>
5000073c:	e59f2020 	ldr	r2, [pc, #32]	; 50000764 <wdt_irq_init+0x58>
50000740:	e5922000 	ldr	r2, [r2]
50000744:	e3822004 	orr	r2, r2, #4
50000748:	e5832000 	str	r2, [r3]
5000074c:	e3a0004b 	mov	r0, #75	; 0x4b
50000750:	e59f1010 	ldr	r1, [pc, #16]	; 50000768 <wdt_irq_init+0x5c>
50000754:	ebffff4a 	bl	50000484 <request_irq>
50000758:	ebffffc9 	bl	50000684 <wdt_enable>
5000075c:	e24bd004 	sub	sp, fp, #4
50000760:	e8bd8800 	pop	{fp, pc}
50000764:	10060000 	andne	r0, r6, r0
50000768:	500006dc 	ldrdpl	r0, [r0], -ip

5000076c <wdt_reset_init>:
5000076c:	e92d4800 	push	{fp, lr}
50000770:	e28db004 	add	fp, sp, #4
50000774:	e24dd008 	sub	sp, sp, #8
50000778:	e50b0008 	str	r0, [fp, #-8]
5000077c:	e51b0008 	ldr	r0, [fp, #-8]
50000780:	ebffffa9 	bl	5000062c <wdt_init>
50000784:	e59f3044 	ldr	r3, [pc, #68]	; 500007d0 <wdt_reset_init+0x64>
50000788:	e59f2040 	ldr	r2, [pc, #64]	; 500007d0 <wdt_reset_init+0x64>
5000078c:	e5922000 	ldr	r2, [r2]
50000790:	e3c22007 	bic	r2, r2, #7
50000794:	e5832000 	str	r2, [r3]
50000798:	e59f3030 	ldr	r3, [pc, #48]	; 500007d0 <wdt_reset_init+0x64>
5000079c:	e59f202c 	ldr	r2, [pc, #44]	; 500007d0 <wdt_reset_init+0x64>
500007a0:	e5922000 	ldr	r2, [r2]
500007a4:	e3822001 	orr	r2, r2, #1
500007a8:	e5832000 	str	r2, [r3]
500007ac:	e59f3020 	ldr	r3, [pc, #32]	; 500007d4 <wdt_reset_init+0x68>
500007b0:	e3a02000 	mov	r2, #0
500007b4:	e5832000 	str	r2, [r3]
500007b8:	e59f3018 	ldr	r3, [pc, #24]	; 500007d8 <wdt_reset_init+0x6c>
500007bc:	e3a02000 	mov	r2, #0
500007c0:	e5832000 	str	r2, [r3]
500007c4:	ebffffae 	bl	50000684 <wdt_enable>
500007c8:	e24bd004 	sub	sp, fp, #4
500007cc:	e8bd8800 	pop	{fp, pc}
500007d0:	10060000 	andne	r0, r6, r0
500007d4:	10020408 	andne	r0, r2, r8, lsl #8
500007d8:	1002040c 	andne	r0, r2, ip, lsl #8

500007dc <adc_init>:
500007dc:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
500007e0:	e28db000 	add	fp, sp, #0
500007e4:	e59f301c 	ldr	r3, [pc, #28]	; 50000808 <adc_init+0x2c>
500007e8:	e59f201c 	ldr	r2, [pc, #28]	; 5000080c <adc_init+0x30>
500007ec:	e5832000 	str	r2, [r3]
500007f0:	e59f3018 	ldr	r3, [pc, #24]	; 50000810 <adc_init+0x34>
500007f4:	e59f2018 	ldr	r2, [pc, #24]	; 50000814 <adc_init+0x38>
500007f8:	e5832000 	str	r2, [r3]
500007fc:	e28bd000 	add	sp, fp, #0
50000800:	e8bd0800 	pop	{fp}
50000804:	e12fff1e 	bx	lr
50000808:	126c0000 	rsbne	r0, ip, #0
5000080c:	00014600 	andeq	r4, r1, r0, lsl #12
50000810:	126c0008 	rsbne	r0, ip, #8
50000814:	0000ffff 	strdeq	pc, [r0], -pc

50000818 <adc_start>:
50000818:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
5000081c:	e28db000 	add	fp, sp, #0
50000820:	e59f3018 	ldr	r3, [pc, #24]	; 50000840 <adc_start+0x28>
50000824:	e59f2014 	ldr	r2, [pc, #20]	; 50000840 <adc_start+0x28>
50000828:	e5922000 	ldr	r2, [r2]
5000082c:	e3822001 	orr	r2, r2, #1
50000830:	e5832000 	str	r2, [r3]
50000834:	e28bd000 	add	sp, fp, #0
50000838:	e8bd0800 	pop	{fp}
5000083c:	e12fff1e 	bx	lr
50000840:	126c0000 	rsbne	r0, ip, #0

50000844 <wait_for_adc>:
50000844:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
50000848:	e28db000 	add	fp, sp, #0
5000084c:	e1a00000 	nop			; (mov r0, r0)
50000850:	e59f3018 	ldr	r3, [pc, #24]	; 50000870 <wait_for_adc+0x2c>
50000854:	e5933000 	ldr	r3, [r3]
50000858:	e2033902 	and	r3, r3, #32768	; 0x8000
5000085c:	e3530000 	cmp	r3, #0
50000860:	0afffffa 	beq	50000850 <wait_for_adc+0xc>
50000864:	e28bd000 	add	sp, fp, #0
50000868:	e8bd0800 	pop	{fp}
5000086c:	e12fff1e 	bx	lr
50000870:	126c0000 	rsbne	r0, ip, #0

50000874 <get_adc>:
50000874:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
50000878:	e28db000 	add	fp, sp, #0
5000087c:	e59f3018 	ldr	r3, [pc, #24]	; 5000089c <get_adc+0x28>
50000880:	e5933000 	ldr	r3, [r3]
50000884:	e1a03a03 	lsl	r3, r3, #20
50000888:	e1a03a23 	lsr	r3, r3, #20
5000088c:	e1a00003 	mov	r0, r3
50000890:	e28bd000 	add	sp, fp, #0
50000894:	e8bd0800 	pop	{fp}
50000898:	e12fff1e 	bx	lr
5000089c:	126c000c 	rsbne	r0, ip, #12

Disassembly of section .rodata:

500008a0 <__FUNCTION__.1282-0x8>:
500008a0:	000a6425 	andeq	r6, sl, r5, lsr #8
500008a4:	000a7325 	andeq	r7, sl, r5, lsr #6

500008a8 <__FUNCTION__.1282>:
500008a8:	00766964 	rsbseq	r6, r6, r4, ror #18

500008ac <__FUNCTION__.1277>:
500008ac:	006c756d 	rsbeq	r7, ip, sp, ror #10

500008b0 <__FUNCTION__.1272>:
500008b0:	00627573 	rsbeq	r7, r2, r3, ror r5

500008b4 <__FUNCTION__.1267>:
500008b4:	00646461 	rsbeq	r6, r4, r1, ror #8
500008b8:	20746477 	rsbscs	r6, r4, r7, ror r4
500008bc:	20746477 	rsbscs	r6, r4, r7, ror r4
500008c0:	20746477 	rsbscs	r6, r4, r7, ror r4
500008c4:	0a2e2e2e 	beq	50b8c184 <__bss_end__+0xb828a8>
500008c8:	00000000 	andeq	r0, r0, r0

Disassembly of section .bss:

500088cc <arr>:
	...

500088dc <ias>:
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
   0:	3a434347 	bcc	10d0d24 <_start-0x4ef2f2dc>
   4:	74632820 	strbtvc	r2, [r3], #-2080	; 0x820
   8:	312d676e 	teqcc	sp, lr, ror #14
   c:	312e382e 	teqcc	lr, lr, lsr #16
  10:	2941462d 	stmdbcs	r1, {r0, r2, r3, r5, r9, sl, lr}^
  14:	352e3420 	strcc	r3, [lr, #-1056]!	; 0x420
  18:	Address 0x00000018 is out of bounds.

