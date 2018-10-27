
arm:     file format elf32-littlearm


Disassembly of section .text:

40008000 <_start>:
40008000:	ea000006 	b	40008020 <reset>
40008004:	ea00000b 	b	40008038 <dat_bot>
40008008:	ea00000a 	b	40008038 <dat_bot>
4000800c:	ea000009 	b	40008038 <dat_bot>
40008010:	ea000008 	b	40008038 <dat_bot>
40008014:	00000000 	andeq	r0, r0, r0
40008018:	ea000006 	b	40008038 <dat_bot>
4000801c:	ea00000c 	b	40008054 <start>

40008020 <reset>:
40008020:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
40008024:	ee110f10 	mrc	15, 0, r0, cr1, cr0, {0}
40008028:	e3800a02 	orr	r0, r0, #8192	; 0x2000
4000802c:	ee010f10 	mcr	15, 0, r0, cr1, cr0, {0}
40008030:	eb000009 	bl	4000805c <main>
40008034:	e8bd9fff 	pop	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}

40008038 <dat_bot>:
40008038:	e3a0d452 	mov	sp, #1375731712	; 0x52000000
4000803c:	e24ee004 	sub	lr, lr, #4
40008040:	e92d5fff 	push	{r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, lr}
40008044:	e1a0e00f 	mov	lr, pc
40008048:	e59ff000 	ldr	pc, [pc, #0]	; 40008050 <_do_irq>
4000804c:	e8fd9fff 	ldm	sp!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, pc}^

40008050 <_do_irq>:
40008050:	40008364 	andmi	r8, r0, r4, ror #6

40008054 <start>:
40008054:	40008000 	andmi	r8, r0, r0

40008058 <end>:
40008058:	40008054 	andmi	r8, r0, r4, asr r0

4000805c <main>:
4000805c:	e92d4800 	push	{fp, lr}
40008060:	e28db004 	add	fp, sp, #4
40008064:	e3a00206 	mov	r0, #1610612736	; 0x60000000
40008068:	eb0000a3 	bl	400082fc <ttb_init>
4000806c:	e3a00206 	mov	r0, #1610612736	; 0x60000000
40008070:	e59f104c 	ldr	r1, [pc, #76]	; 400080c4 <main+0x68>
40008074:	e3a02207 	mov	r2, #1879048192	; 0x70000000
40008078:	eb00008c 	bl	400082b0 <my_mmap>
4000807c:	eb00007b 	bl	40008270 <mmu_enable>
40008080:	e59f3040 	ldr	r3, [pc, #64]	; 400080c8 <main+0x6c>
40008084:	e5933000 	ldr	r3, [r3]
40008088:	e1a02003 	mov	r2, r3
4000808c:	e59f3038 	ldr	r3, [pc, #56]	; 400080cc <main+0x70>
40008090:	e5931000 	ldr	r1, [r3]
40008094:	e59f302c 	ldr	r3, [pc, #44]	; 400080c8 <main+0x6c>
40008098:	e5933000 	ldr	r3, [r3]
4000809c:	e0633001 	rsb	r3, r3, r1
400080a0:	e59f0028 	ldr	r0, [pc, #40]	; 400080d0 <main+0x74>
400080a4:	e1a01002 	mov	r1, r2
400080a8:	e1a02003 	mov	r2, r3
400080ac:	eb00004b 	bl	400081e0 <memcpy>
400080b0:	e3a0007f 	mov	r0, #127	; 0x7f
400080b4:	eb00021c 	bl	4000892c <set_backlight_start>
400080b8:	e3a03000 	mov	r3, #0
400080bc:	e1a00003 	mov	r0, r3
400080c0:	e8bd8800 	pop	{fp, pc}
400080c4:	fff00000 	undefined instruction 0xfff00000	; IMB
400080c8:	40008054 	andmi	r8, r0, r4, asr r0
400080cc:	40008058 	andmi	r8, r0, r8, asr r0
400080d0:	ffff0000 	undefined instruction 0xffff0000

400080d4 <delay>:
400080d4:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
400080d8:	e28db000 	add	fp, sp, #0
400080dc:	e24dd014 	sub	sp, sp, #20
400080e0:	e50b0010 	str	r0, [fp, #-16]
400080e4:	e3a03000 	mov	r3, #0
400080e8:	e50b3008 	str	r3, [fp, #-8]
400080ec:	ea00000c 	b	40008124 <delay+0x50>
400080f0:	e3a03000 	mov	r3, #0
400080f4:	e50b300c 	str	r3, [fp, #-12]
400080f8:	ea000002 	b	40008108 <delay+0x34>
400080fc:	e51b300c 	ldr	r3, [fp, #-12]
40008100:	e2833001 	add	r3, r3, #1
40008104:	e50b300c 	str	r3, [fp, #-12]
40008108:	e51b200c 	ldr	r2, [fp, #-12]
4000810c:	e59f302c 	ldr	r3, [pc, #44]	; 40008140 <delay+0x6c>
40008110:	e1520003 	cmp	r2, r3
40008114:	dafffff8 	ble	400080fc <delay+0x28>
40008118:	e51b3008 	ldr	r3, [fp, #-8]
4000811c:	e2833001 	add	r3, r3, #1
40008120:	e50b3008 	str	r3, [fp, #-8]
40008124:	e51b2008 	ldr	r2, [fp, #-8]
40008128:	e51b3010 	ldr	r3, [fp, #-16]
4000812c:	e1520003 	cmp	r2, r3
40008130:	baffffee 	blt	400080f0 <delay+0x1c>
40008134:	e28bd000 	add	sp, fp, #0
40008138:	e8bd0800 	pop	{fp}
4000813c:	e12fff1e 	bx	lr
40008140:	000003e7 	andeq	r0, r0, r7, ror #7

40008144 <strcmp>:
40008144:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
40008148:	e28db000 	add	fp, sp, #0
4000814c:	e24dd014 	sub	sp, sp, #20
40008150:	e50b0010 	str	r0, [fp, #-16]
40008154:	e50b1014 	str	r1, [fp, #-20]
40008158:	ea000000 	b	40008160 <strcmp+0x1c>
4000815c:	e1a00000 	nop			; (mov r0, r0)
40008160:	e51b3010 	ldr	r3, [fp, #-16]
40008164:	e5d33000 	ldrb	r3, [r3]
40008168:	e54b3005 	strb	r3, [fp, #-5]
4000816c:	e51b3010 	ldr	r3, [fp, #-16]
40008170:	e2833001 	add	r3, r3, #1
40008174:	e50b3010 	str	r3, [fp, #-16]
40008178:	e51b3014 	ldr	r3, [fp, #-20]
4000817c:	e5d33000 	ldrb	r3, [r3]
40008180:	e54b3006 	strb	r3, [fp, #-6]
40008184:	e51b3014 	ldr	r3, [fp, #-20]
40008188:	e2833001 	add	r3, r3, #1
4000818c:	e50b3014 	str	r3, [fp, #-20]
40008190:	e55b2005 	ldrb	r2, [fp, #-5]
40008194:	e55b3006 	ldrb	r3, [fp, #-6]
40008198:	e1520003 	cmp	r2, r3
4000819c:	0a000007 	beq	400081c0 <strcmp+0x7c>
400081a0:	e55b2005 	ldrb	r2, [fp, #-5]
400081a4:	e55b3006 	ldrb	r3, [fp, #-6]
400081a8:	e1520003 	cmp	r2, r3
400081ac:	2a000001 	bcs	400081b8 <strcmp+0x74>
400081b0:	e3e03000 	mvn	r3, #0
400081b4:	ea000000 	b	400081bc <strcmp+0x78>
400081b8:	e3a03001 	mov	r3, #1
400081bc:	ea000003 	b	400081d0 <strcmp+0x8c>
400081c0:	e55b3005 	ldrb	r3, [fp, #-5]
400081c4:	e3530000 	cmp	r3, #0
400081c8:	1affffe3 	bne	4000815c <strcmp+0x18>
400081cc:	e3a03000 	mov	r3, #0
400081d0:	e1a00003 	mov	r0, r3
400081d4:	e28bd000 	add	sp, fp, #0
400081d8:	e8bd0800 	pop	{fp}
400081dc:	e12fff1e 	bx	lr

400081e0 <memcpy>:
400081e0:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
400081e4:	e28db000 	add	fp, sp, #0
400081e8:	e24dd01c 	sub	sp, sp, #28
400081ec:	e50b0010 	str	r0, [fp, #-16]
400081f0:	e50b1014 	str	r1, [fp, #-20]
400081f4:	e50b2018 	str	r2, [fp, #-24]
400081f8:	e51b3010 	ldr	r3, [fp, #-16]
400081fc:	e50b3008 	str	r3, [fp, #-8]
40008200:	e51b3014 	ldr	r3, [fp, #-20]
40008204:	e50b300c 	str	r3, [fp, #-12]
40008208:	ea000009 	b	40008234 <memcpy+0x54>
4000820c:	e51b300c 	ldr	r3, [fp, #-12]
40008210:	e5d32000 	ldrb	r2, [r3]
40008214:	e51b3008 	ldr	r3, [fp, #-8]
40008218:	e5c32000 	strb	r2, [r3]
4000821c:	e51b3008 	ldr	r3, [fp, #-8]
40008220:	e2833001 	add	r3, r3, #1
40008224:	e50b3008 	str	r3, [fp, #-8]
40008228:	e51b300c 	ldr	r3, [fp, #-12]
4000822c:	e2833001 	add	r3, r3, #1
40008230:	e50b300c 	str	r3, [fp, #-12]
40008234:	e51b3018 	ldr	r3, [fp, #-24]
40008238:	e3530000 	cmp	r3, #0
4000823c:	03a03000 	moveq	r3, #0
40008240:	13a03001 	movne	r3, #1
40008244:	e6ef3073 	uxtb	r3, r3
40008248:	e51b2018 	ldr	r2, [fp, #-24]
4000824c:	e2422001 	sub	r2, r2, #1
40008250:	e50b2018 	str	r2, [fp, #-24]
40008254:	e3530000 	cmp	r3, #0
40008258:	1affffeb 	bne	4000820c <memcpy+0x2c>
4000825c:	e51b3010 	ldr	r3, [fp, #-16]
40008260:	e1a00003 	mov	r0, r3
40008264:	e28bd000 	add	sp, fp, #0
40008268:	e8bd0800 	pop	{fp}
4000826c:	e12fff1e 	bx	lr

40008270 <mmu_enable>:
40008270:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
40008274:	e28db000 	add	fp, sp, #0
40008278:	ee110f10 	mrc	15, 0, r0, cr1, cr0, {0}
4000827c:	e3800001 	orr	r0, r0, #1
40008280:	ee010f10 	mcr	15, 0, r0, cr1, cr0, {0}
40008284:	e28bd000 	add	sp, fp, #0
40008288:	e8bd0800 	pop	{fp}
4000828c:	e12fff1e 	bx	lr

40008290 <mmu_disable>:
40008290:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
40008294:	e28db000 	add	fp, sp, #0
40008298:	ee110f10 	mrc	15, 0, r0, cr1, cr0, {0}
4000829c:	e3c00001 	bic	r0, r0, #1
400082a0:	ee010f10 	mcr	15, 0, r0, cr1, cr0, {0}
400082a4:	e28bd000 	add	sp, fp, #0
400082a8:	e8bd0800 	pop	{fp}
400082ac:	e12fff1e 	bx	lr

400082b0 <my_mmap>:
400082b0:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
400082b4:	e28db000 	add	fp, sp, #0
400082b8:	e24dd014 	sub	sp, sp, #20
400082bc:	e50b0008 	str	r0, [fp, #-8]
400082c0:	e50b100c 	str	r1, [fp, #-12]
400082c4:	e50b2010 	str	r2, [fp, #-16]
400082c8:	e51b300c 	ldr	r3, [fp, #-12]
400082cc:	e1a03a23 	lsr	r3, r3, #20
400082d0:	e1a03103 	lsl	r3, r3, #2
400082d4:	e51b2008 	ldr	r2, [fp, #-8]
400082d8:	e0822003 	add	r2, r2, r3
400082dc:	e51b3010 	ldr	r3, [fp, #-16]
400082e0:	e1a03a23 	lsr	r3, r3, #20
400082e4:	e1a03a03 	lsl	r3, r3, #20
400082e8:	e3833002 	orr	r3, r3, #2
400082ec:	e5823000 	str	r3, [r2]
400082f0:	e28bd000 	add	sp, fp, #0
400082f4:	e8bd0800 	pop	{fp}
400082f8:	e12fff1e 	bx	lr

400082fc <ttb_init>:
400082fc:	e92d4800 	push	{fp, lr}
40008300:	e28db004 	add	fp, sp, #4
40008304:	e24dd010 	sub	sp, sp, #16
40008308:	e50b0010 	str	r0, [fp, #-16]
4000830c:	e3a03000 	mov	r3, #0
40008310:	e50b3008 	str	r3, [fp, #-8]
40008314:	ea000008 	b	4000833c <ttb_init+0x40>
40008318:	e51b3008 	ldr	r3, [fp, #-8]
4000831c:	e50b300c 	str	r3, [fp, #-12]
40008320:	e51b0010 	ldr	r0, [fp, #-16]
40008324:	e51b1008 	ldr	r1, [fp, #-8]
40008328:	e51b200c 	ldr	r2, [fp, #-12]
4000832c:	ebffffdf 	bl	400082b0 <my_mmap>
40008330:	e51b3008 	ldr	r3, [fp, #-8]
40008334:	e2833601 	add	r3, r3, #1048576	; 0x100000
40008338:	e50b3008 	str	r3, [fp, #-8]
4000833c:	e51b3008 	ldr	r3, [fp, #-8]
40008340:	e3530000 	cmp	r3, #0
40008344:	aafffff3 	bge	40008318 <ttb_init+0x1c>
40008348:	e51b3010 	ldr	r3, [fp, #-16]
4000834c:	ee023f10 	mcr	15, 0, r3, cr2, cr0, {0}
40008350:	ee130f10 	mrc	15, 0, r0, cr3, cr0, {0}
40008354:	e3800003 	orr	r0, r0, #3
40008358:	ee030f10 	mcr	15, 0, r0, cr3, cr0, {0}
4000835c:	e24bd004 	sub	sp, fp, #4
40008360:	e8bd8800 	pop	{fp, pc}

40008364 <do_irq>:
40008364:	e92d4800 	push	{fp, lr}
40008368:	e28db004 	add	fp, sp, #4
4000836c:	e24dd008 	sub	sp, sp, #8
40008370:	e59f30d0 	ldr	r3, [pc, #208]	; 40008448 <do_irq+0xe4>
40008374:	e5933000 	ldr	r3, [r3]
40008378:	e50b3008 	str	r3, [fp, #-8]
4000837c:	e51b3008 	ldr	r3, [fp, #-8]
40008380:	e1a03b03 	lsl	r3, r3, #22
40008384:	e1a03b23 	lsr	r3, r3, #22
40008388:	e243302a 	sub	r3, r3, #42	; 0x2a
4000838c:	e3530023 	cmp	r3, #35	; 0x23
40008390:	979ff103 	ldrls	pc, [pc, r3, lsl #2]
40008394:	ea000025 	b	40008430 <do_irq+0xcc>
40008398:	40008430 	andmi	r8, r0, r0, lsr r4
4000839c:	40008430 	andmi	r8, r0, r0, lsr r4
400083a0:	40008430 	andmi	r8, r0, r0, lsr r4
400083a4:	40008430 	andmi	r8, r0, r0, lsr r4
400083a8:	40008430 	andmi	r8, r0, r0, lsr r4
400083ac:	40008430 	andmi	r8, r0, r0, lsr r4
400083b0:	40008430 	andmi	r8, r0, r0, lsr r4
400083b4:	40008430 	andmi	r8, r0, r0, lsr r4
400083b8:	40008430 	andmi	r8, r0, r0, lsr r4
400083bc:	40008430 	andmi	r8, r0, r0, lsr r4
400083c0:	40008430 	andmi	r8, r0, r0, lsr r4
400083c4:	40008430 	andmi	r8, r0, r0, lsr r4
400083c8:	40008430 	andmi	r8, r0, r0, lsr r4
400083cc:	40008430 	andmi	r8, r0, r0, lsr r4
400083d0:	40008430 	andmi	r8, r0, r0, lsr r4
400083d4:	40008430 	andmi	r8, r0, r0, lsr r4
400083d8:	40008430 	andmi	r8, r0, r0, lsr r4
400083dc:	40008430 	andmi	r8, r0, r0, lsr r4
400083e0:	40008430 	andmi	r8, r0, r0, lsr r4
400083e4:	40008430 	andmi	r8, r0, r0, lsr r4
400083e8:	40008430 	andmi	r8, r0, r0, lsr r4
400083ec:	40008430 	andmi	r8, r0, r0, lsr r4
400083f0:	40008430 	andmi	r8, r0, r0, lsr r4
400083f4:	40008430 	andmi	r8, r0, r0, lsr r4
400083f8:	40008430 	andmi	r8, r0, r0, lsr r4
400083fc:	40008430 	andmi	r8, r0, r0, lsr r4
40008400:	40008430 	andmi	r8, r0, r0, lsr r4
40008404:	40008430 	andmi	r8, r0, r0, lsr r4
40008408:	40008428 	andmi	r8, r0, r8, lsr #8
4000840c:	40008430 	andmi	r8, r0, r0, lsr r4
40008410:	40008430 	andmi	r8, r0, r0, lsr r4
40008414:	40008430 	andmi	r8, r0, r0, lsr r4
40008418:	40008430 	andmi	r8, r0, r0, lsr r4
4000841c:	40008430 	andmi	r8, r0, r0, lsr r4
40008420:	40008430 	andmi	r8, r0, r0, lsr r4
40008424:	40008430 	andmi	r8, r0, r0, lsr r4
40008428:	eb000106 	bl	40008848 <do_timer1>
4000842c:	ea000000 	b	40008434 <do_irq+0xd0>
40008430:	e1a00000 	nop			; (mov r0, r0)
40008434:	e59f3010 	ldr	r3, [pc, #16]	; 4000844c <do_irq+0xe8>
40008438:	e51b2008 	ldr	r2, [fp, #-8]
4000843c:	e5832000 	str	r2, [r3]
40008440:	e24bd004 	sub	sp, fp, #4
40008444:	e8bd8800 	pop	{fp, pc}
40008448:	1048000c 	subne	r0, r8, ip
4000844c:	10480010 	subne	r0, r8, r0, lsl r0

40008450 <sgi_init>:
40008450:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
40008454:	e28db000 	add	fp, sp, #0
40008458:	e59f3068 	ldr	r3, [pc, #104]	; 400084c8 <sgi_init+0x78>
4000845c:	e3a02001 	mov	r2, #1
40008460:	e5832000 	str	r2, [r3]
40008464:	e59f3060 	ldr	r3, [pc, #96]	; 400084cc <sgi_init+0x7c>
40008468:	e3a020ff 	mov	r2, #255	; 0xff
4000846c:	e5832000 	str	r2, [r3]
40008470:	e59f3058 	ldr	r3, [pc, #88]	; 400084d0 <sgi_init+0x80>
40008474:	e3a02001 	mov	r2, #1
40008478:	e5832000 	str	r2, [r3]
4000847c:	e59f3050 	ldr	r3, [pc, #80]	; 400084d4 <sgi_init+0x84>
40008480:	e59f204c 	ldr	r2, [pc, #76]	; 400084d4 <sgi_init+0x84>
40008484:	e5922000 	ldr	r2, [r2]
40008488:	e3822001 	orr	r2, r2, #1
4000848c:	e5832000 	str	r2, [r3]
40008490:	e59f3040 	ldr	r3, [pc, #64]	; 400084d8 <sgi_init+0x88>
40008494:	e59f203c 	ldr	r2, [pc, #60]	; 400084d8 <sgi_init+0x88>
40008498:	e5922000 	ldr	r2, [r2]
4000849c:	e3c220ff 	bic	r2, r2, #255	; 0xff
400084a0:	e5832000 	str	r2, [r3]
400084a4:	e59f3030 	ldr	r3, [pc, #48]	; 400084dc <sgi_init+0x8c>
400084a8:	e59f202c 	ldr	r2, [pc, #44]	; 400084dc <sgi_init+0x8c>
400084ac:	e5922000 	ldr	r2, [r2]
400084b0:	e3822001 	orr	r2, r2, #1
400084b4:	e5832000 	str	r2, [r3]
400084b8:	f1080080 	cpsie	i
400084bc:	e28bd000 	add	sp, fp, #0
400084c0:	e8bd0800 	pop	{fp}
400084c4:	e12fff1e 	bx	lr
400084c8:	10480000 	subne	r0, r8, r0
400084cc:	10480004 	subne	r0, r8, r4
400084d0:	10490000 	subne	r0, r9, r0
400084d4:	10490100 	subne	r0, r9, r0, lsl #2
400084d8:	10490400 	subne	r0, r9, r0, lsl #8
400084dc:	10490800 	subne	r0, r9, r0, lsl #16

400084e0 <gen_sgi>:
400084e0:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
400084e4:	e28db000 	add	fp, sp, #0
400084e8:	e59f3010 	ldr	r3, [pc, #16]	; 40008500 <gen_sgi+0x20>
400084ec:	e3a02801 	mov	r2, #65536	; 0x10000
400084f0:	e5832000 	str	r2, [r3]
400084f4:	e28bd000 	add	sp, fp, #0
400084f8:	e8bd0800 	pop	{fp}
400084fc:	e12fff1e 	bx	lr
40008500:	10490f00 	subne	r0, r9, r0, lsl #30

40008504 <timer0_init>:
40008504:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
40008508:	e28db000 	add	fp, sp, #0
4000850c:	e24dd00c 	sub	sp, sp, #12
40008510:	e50b0008 	str	r0, [fp, #-8]
40008514:	e50b100c 	str	r1, [fp, #-12]
40008518:	e59f30d8 	ldr	r3, [pc, #216]	; 400085f8 <timer0_init+0xf4>
4000851c:	e59f20d4 	ldr	r2, [pc, #212]	; 400085f8 <timer0_init+0xf4>
40008520:	e5922000 	ldr	r2, [r2]
40008524:	e3c2200f 	bic	r2, r2, #15
40008528:	e5832000 	str	r2, [r3]
4000852c:	e59f30c4 	ldr	r3, [pc, #196]	; 400085f8 <timer0_init+0xf4>
40008530:	e59f20c0 	ldr	r2, [pc, #192]	; 400085f8 <timer0_init+0xf4>
40008534:	e5922000 	ldr	r2, [r2]
40008538:	e3822002 	orr	r2, r2, #2
4000853c:	e5832000 	str	r2, [r3]
40008540:	e59f30b4 	ldr	r3, [pc, #180]	; 400085fc <timer0_init+0xf8>
40008544:	e59f20b0 	ldr	r2, [pc, #176]	; 400085fc <timer0_init+0xf8>
40008548:	e5922000 	ldr	r2, [r2]
4000854c:	e3c220ff 	bic	r2, r2, #255	; 0xff
40008550:	e5832000 	str	r2, [r3]
40008554:	e59f30a0 	ldr	r3, [pc, #160]	; 400085fc <timer0_init+0xf8>
40008558:	e59f209c 	ldr	r2, [pc, #156]	; 400085fc <timer0_init+0xf8>
4000855c:	e5922000 	ldr	r2, [r2]
40008560:	e3822063 	orr	r2, r2, #99	; 0x63
40008564:	e5832000 	str	r2, [r3]
40008568:	e59f3090 	ldr	r3, [pc, #144]	; 40008600 <timer0_init+0xfc>
4000856c:	e59f208c 	ldr	r2, [pc, #140]	; 40008600 <timer0_init+0xfc>
40008570:	e5922000 	ldr	r2, [r2]
40008574:	e3c2200f 	bic	r2, r2, #15
40008578:	e5832000 	str	r2, [r3]
4000857c:	e59f307c 	ldr	r3, [pc, #124]	; 40008600 <timer0_init+0xfc>
40008580:	e59f2078 	ldr	r2, [pc, #120]	; 40008600 <timer0_init+0xfc>
40008584:	e5922000 	ldr	r2, [r2]
40008588:	e3822002 	orr	r2, r2, #2
4000858c:	e5832000 	str	r2, [r3]
40008590:	e59f306c 	ldr	r3, [pc, #108]	; 40008604 <timer0_init+0x100>
40008594:	e51b2008 	ldr	r2, [fp, #-8]
40008598:	e2422001 	sub	r2, r2, #1
4000859c:	e5832000 	str	r2, [r3]
400085a0:	e59f3060 	ldr	r3, [pc, #96]	; 40008608 <timer0_init+0x104>
400085a4:	e51b200c 	ldr	r2, [fp, #-12]
400085a8:	e2422001 	sub	r2, r2, #1
400085ac:	e5832000 	str	r2, [r3]
400085b0:	e59f3054 	ldr	r3, [pc, #84]	; 4000860c <timer0_init+0x108>
400085b4:	e59f2050 	ldr	r2, [pc, #80]	; 4000860c <timer0_init+0x108>
400085b8:	e5922000 	ldr	r2, [r2]
400085bc:	e3c2200f 	bic	r2, r2, #15
400085c0:	e5832000 	str	r2, [r3]
400085c4:	e59f3040 	ldr	r3, [pc, #64]	; 4000860c <timer0_init+0x108>
400085c8:	e59f203c 	ldr	r2, [pc, #60]	; 4000860c <timer0_init+0x108>
400085cc:	e5922000 	ldr	r2, [r2]
400085d0:	e382200b 	orr	r2, r2, #11
400085d4:	e5832000 	str	r2, [r3]
400085d8:	e59f302c 	ldr	r3, [pc, #44]	; 4000860c <timer0_init+0x108>
400085dc:	e59f2028 	ldr	r2, [pc, #40]	; 4000860c <timer0_init+0x108>
400085e0:	e5922000 	ldr	r2, [r2]
400085e4:	e3c22002 	bic	r2, r2, #2
400085e8:	e5832000 	str	r2, [r3]
400085ec:	e28bd000 	add	sp, fp, #0
400085f0:	e8bd0800 	pop	{fp}
400085f4:	e12fff1e 	bx	lr
400085f8:	114000a0 	smlaltbne	r0, r0, r0, r0
400085fc:	139d0000 	orrsne	r0, sp, #0
40008600:	139d0004 	orrsne	r0, sp, #4
40008604:	139d000c 	orrsne	r0, sp, #12
40008608:	139d0010 	orrsne	r0, sp, #16
4000860c:	139d0008 	orrsne	r0, sp, #8

40008610 <timer1_init>:
40008610:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
40008614:	e28db000 	add	fp, sp, #0
40008618:	e24dd00c 	sub	sp, sp, #12
4000861c:	e50b0008 	str	r0, [fp, #-8]
40008620:	e59f310c 	ldr	r3, [pc, #268]	; 40008734 <timer1_init+0x124>
40008624:	e59f2108 	ldr	r2, [pc, #264]	; 40008734 <timer1_init+0x124>
40008628:	e5922000 	ldr	r2, [r2]
4000862c:	e3c220ff 	bic	r2, r2, #255	; 0xff
40008630:	e5832000 	str	r2, [r3]
40008634:	e59f30f8 	ldr	r3, [pc, #248]	; 40008734 <timer1_init+0x124>
40008638:	e59f20f4 	ldr	r2, [pc, #244]	; 40008734 <timer1_init+0x124>
4000863c:	e5922000 	ldr	r2, [r2]
40008640:	e382200f 	orr	r2, r2, #15
40008644:	e5832000 	str	r2, [r3]
40008648:	e59f30e8 	ldr	r3, [pc, #232]	; 40008738 <timer1_init+0x128>
4000864c:	e59f20e4 	ldr	r2, [pc, #228]	; 40008738 <timer1_init+0x128>
40008650:	e5922000 	ldr	r2, [r2]
40008654:	e3c220f0 	bic	r2, r2, #240	; 0xf0
40008658:	e5832000 	str	r2, [r3]
4000865c:	e59f30d8 	ldr	r3, [pc, #216]	; 4000873c <timer1_init+0x12c>
40008660:	e59f20d8 	ldr	r2, [pc, #216]	; 40008740 <timer1_init+0x130>
40008664:	e5832000 	str	r2, [r3]
40008668:	e59f30d4 	ldr	r3, [pc, #212]	; 40008744 <timer1_init+0x134>
4000866c:	e59f20d4 	ldr	r2, [pc, #212]	; 40008748 <timer1_init+0x138>
40008670:	e5832000 	str	r2, [r3]
40008674:	e59f30d0 	ldr	r3, [pc, #208]	; 4000874c <timer1_init+0x13c>
40008678:	e59f20cc 	ldr	r2, [pc, #204]	; 4000874c <timer1_init+0x13c>
4000867c:	e5922000 	ldr	r2, [r2]
40008680:	e3c22c0f 	bic	r2, r2, #3840	; 0xf00
40008684:	e5832000 	str	r2, [r3]
40008688:	e59f30bc 	ldr	r3, [pc, #188]	; 4000874c <timer1_init+0x13c>
4000868c:	e59f20b8 	ldr	r2, [pc, #184]	; 4000874c <timer1_init+0x13c>
40008690:	e5922000 	ldr	r2, [r2]
40008694:	e3822c0b 	orr	r2, r2, #2816	; 0xb00
40008698:	e5832000 	str	r2, [r3]
4000869c:	e59f30a8 	ldr	r3, [pc, #168]	; 4000874c <timer1_init+0x13c>
400086a0:	e59f20a4 	ldr	r2, [pc, #164]	; 4000874c <timer1_init+0x13c>
400086a4:	e5922000 	ldr	r2, [r2]
400086a8:	e3c22c02 	bic	r2, r2, #512	; 0x200
400086ac:	e5832000 	str	r2, [r3]
400086b0:	e59f3098 	ldr	r3, [pc, #152]	; 40008750 <timer1_init+0x140>
400086b4:	e59f2094 	ldr	r2, [pc, #148]	; 40008750 <timer1_init+0x140>
400086b8:	e5922000 	ldr	r2, [r2]
400086bc:	e3822002 	orr	r2, r2, #2
400086c0:	e5832000 	str	r2, [r3]
400086c4:	e59f3088 	ldr	r3, [pc, #136]	; 40008754 <timer1_init+0x144>
400086c8:	e3a02001 	mov	r2, #1
400086cc:	e5832000 	str	r2, [r3]
400086d0:	e59f3080 	ldr	r3, [pc, #128]	; 40008758 <timer1_init+0x148>
400086d4:	e3a020ff 	mov	r2, #255	; 0xff
400086d8:	e5832000 	str	r2, [r3]
400086dc:	e59f3078 	ldr	r3, [pc, #120]	; 4000875c <timer1_init+0x14c>
400086e0:	e3a02001 	mov	r2, #1
400086e4:	e5832000 	str	r2, [r3]
400086e8:	e59f3070 	ldr	r3, [pc, #112]	; 40008760 <timer1_init+0x150>
400086ec:	e59f206c 	ldr	r2, [pc, #108]	; 40008760 <timer1_init+0x150>
400086f0:	e5922000 	ldr	r2, [r2]
400086f4:	e3822040 	orr	r2, r2, #64	; 0x40
400086f8:	e5832000 	str	r2, [r3]
400086fc:	e59f3060 	ldr	r3, [pc, #96]	; 40008764 <timer1_init+0x154>
40008700:	e59f205c 	ldr	r2, [pc, #92]	; 40008764 <timer1_init+0x154>
40008704:	e5922000 	ldr	r2, [r2]
40008708:	e3c228ff 	bic	r2, r2, #16711680	; 0xff0000
4000870c:	e5832000 	str	r2, [r3]
40008710:	e59f3050 	ldr	r3, [pc, #80]	; 40008768 <timer1_init+0x158>
40008714:	e59f204c 	ldr	r2, [pc, #76]	; 40008768 <timer1_init+0x158>
40008718:	e5922000 	ldr	r2, [r2]
4000871c:	e3822801 	orr	r2, r2, #65536	; 0x10000
40008720:	e5832000 	str	r2, [r3]
40008724:	f1080080 	cpsie	i
40008728:	e28bd000 	add	sp, fp, #0
4000872c:	e8bd0800 	pop	{fp}
40008730:	e12fff1e 	bx	lr
40008734:	139d0000 	orrsne	r0, sp, #0
40008738:	139d0004 	orrsne	r0, sp, #4
4000873c:	139d0018 	orrsne	r0, sp, #24
40008740:	0000028a 	andeq	r0, r0, sl, lsl #5
40008744:	139d0010 	orrsne	r0, sp, #16
40008748:	001e8480 	andseq	r8, lr, r0, lsl #9
4000874c:	139d0008 	orrsne	r0, sp, #8
40008750:	139d0044 	orrsne	r0, sp, #68	; 0x44
40008754:	10480000 	subne	r0, r8, r0
40008758:	10480004 	subne	r0, r8, r4
4000875c:	10490000 	subne	r0, r9, r0
40008760:	10490108 	subne	r0, r9, r8, lsl #2
40008764:	10490444 	subne	r0, r9, r4, asr #8
40008768:	10490844 	subne	r0, r9, r4, asr #16

4000876c <stop_timer1>:
4000876c:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
40008770:	e28db000 	add	fp, sp, #0
40008774:	e59f3018 	ldr	r3, [pc, #24]	; 40008794 <stop_timer1+0x28>
40008778:	e59f2014 	ldr	r2, [pc, #20]	; 40008794 <stop_timer1+0x28>
4000877c:	e5922000 	ldr	r2, [r2]
40008780:	e3c22c0f 	bic	r2, r2, #3840	; 0xf00
40008784:	e5832000 	str	r2, [r3]
40008788:	e28bd000 	add	sp, fp, #0
4000878c:	e8bd0800 	pop	{fp}
40008790:	e12fff1e 	bx	lr
40008794:	139d0008 	orrsne	r0, sp, #8

40008798 <set_gpx1_2_high>:
40008798:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
4000879c:	e28db000 	add	fp, sp, #0
400087a0:	e59f3040 	ldr	r3, [pc, #64]	; 400087e8 <set_gpx1_2_high+0x50>
400087a4:	e59f203c 	ldr	r2, [pc, #60]	; 400087e8 <set_gpx1_2_high+0x50>
400087a8:	e5922000 	ldr	r2, [r2]
400087ac:	e3c22c0f 	bic	r2, r2, #3840	; 0xf00
400087b0:	e5832000 	str	r2, [r3]
400087b4:	e59f302c 	ldr	r3, [pc, #44]	; 400087e8 <set_gpx1_2_high+0x50>
400087b8:	e59f2028 	ldr	r2, [pc, #40]	; 400087e8 <set_gpx1_2_high+0x50>
400087bc:	e5922000 	ldr	r2, [r2]
400087c0:	e3822c01 	orr	r2, r2, #256	; 0x100
400087c4:	e5832000 	str	r2, [r3]
400087c8:	e59f301c 	ldr	r3, [pc, #28]	; 400087ec <set_gpx1_2_high+0x54>
400087cc:	e59f2018 	ldr	r2, [pc, #24]	; 400087ec <set_gpx1_2_high+0x54>
400087d0:	e5922000 	ldr	r2, [r2]
400087d4:	e3822004 	orr	r2, r2, #4
400087d8:	e5832000 	str	r2, [r3]
400087dc:	e28bd000 	add	sp, fp, #0
400087e0:	e8bd0800 	pop	{fp}
400087e4:	e12fff1e 	bx	lr
400087e8:	11000c20 	tstne	r0, r0, lsr #24
400087ec:	11000c24 	tstne	r0, r4, lsr #24

400087f0 <set_gpx1_2_low>:
400087f0:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
400087f4:	e28db000 	add	fp, sp, #0
400087f8:	e59f3040 	ldr	r3, [pc, #64]	; 40008840 <set_gpx1_2_low+0x50>
400087fc:	e59f203c 	ldr	r2, [pc, #60]	; 40008840 <set_gpx1_2_low+0x50>
40008800:	e5922000 	ldr	r2, [r2]
40008804:	e3c22c0f 	bic	r2, r2, #3840	; 0xf00
40008808:	e5832000 	str	r2, [r3]
4000880c:	e59f302c 	ldr	r3, [pc, #44]	; 40008840 <set_gpx1_2_low+0x50>
40008810:	e59f2028 	ldr	r2, [pc, #40]	; 40008840 <set_gpx1_2_low+0x50>
40008814:	e5922000 	ldr	r2, [r2]
40008818:	e3822c01 	orr	r2, r2, #256	; 0x100
4000881c:	e5832000 	str	r2, [r3]
40008820:	e59f301c 	ldr	r3, [pc, #28]	; 40008844 <set_gpx1_2_low+0x54>
40008824:	e59f2018 	ldr	r2, [pc, #24]	; 40008844 <set_gpx1_2_low+0x54>
40008828:	e5922000 	ldr	r2, [r2]
4000882c:	e3c22004 	bic	r2, r2, #4
40008830:	e5832000 	str	r2, [r3]
40008834:	e28bd000 	add	sp, fp, #0
40008838:	e8bd0800 	pop	{fp}
4000883c:	e12fff1e 	bx	lr
40008840:	11000c20 	tstne	r0, r0, lsr #24
40008844:	11000c24 	tstne	r0, r4, lsr #24

40008848 <do_timer1>:
40008848:	e92d4800 	push	{fp, lr}
4000884c:	e28db004 	add	fp, sp, #4
40008850:	e59f30c4 	ldr	r3, [pc, #196]	; 4000891c <do_timer1+0xd4>
40008854:	e5933000 	ldr	r3, [r3]
40008858:	e3530001 	cmp	r3, #1
4000885c:	0a00000a 	beq	4000888c <do_timer1+0x44>
40008860:	e3530002 	cmp	r3, #2
40008864:	0a000021 	beq	400088f0 <do_timer1+0xa8>
40008868:	e3530000 	cmp	r3, #0
4000886c:	1a000021 	bne	400088f8 <do_timer1+0xb0>
40008870:	e59f30a8 	ldr	r3, [pc, #168]	; 40008920 <do_timer1+0xd8>
40008874:	e3a02010 	mov	r2, #16
40008878:	e5832000 	str	r2, [r3]
4000887c:	e59f3098 	ldr	r3, [pc, #152]	; 4000891c <do_timer1+0xd4>
40008880:	e3a02001 	mov	r2, #1
40008884:	e5832000 	str	r2, [r3]
40008888:	ea00001d 	b	40008904 <do_timer1+0xbc>
4000888c:	e59f3090 	ldr	r3, [pc, #144]	; 40008924 <do_timer1+0xdc>
40008890:	e5933000 	ldr	r3, [r3]
40008894:	e3530000 	cmp	r3, #0
40008898:	aa000001 	bge	400088a4 <do_timer1+0x5c>
4000889c:	ebffffbd 	bl	40008798 <set_gpx1_2_high>
400088a0:	ea000000 	b	400088a8 <do_timer1+0x60>
400088a4:	ebffffd1 	bl	400087f0 <set_gpx1_2_low>
400088a8:	e59f3074 	ldr	r3, [pc, #116]	; 40008924 <do_timer1+0xdc>
400088ac:	e5933000 	ldr	r3, [r3]
400088b0:	e1a02083 	lsl	r2, r3, #1
400088b4:	e59f3068 	ldr	r3, [pc, #104]	; 40008924 <do_timer1+0xdc>
400088b8:	e5832000 	str	r2, [r3]
400088bc:	e59f305c 	ldr	r3, [pc, #92]	; 40008920 <do_timer1+0xd8>
400088c0:	e5933000 	ldr	r3, [r3]
400088c4:	e2432001 	sub	r2, r3, #1
400088c8:	e59f3050 	ldr	r3, [pc, #80]	; 40008920 <do_timer1+0xd8>
400088cc:	e5832000 	str	r2, [r3]
400088d0:	e59f3048 	ldr	r3, [pc, #72]	; 40008920 <do_timer1+0xd8>
400088d4:	e5933000 	ldr	r3, [r3]
400088d8:	e3530000 	cmp	r3, #0
400088dc:	1a000007 	bne	40008900 <do_timer1+0xb8>
400088e0:	e59f3034 	ldr	r3, [pc, #52]	; 4000891c <do_timer1+0xd4>
400088e4:	e3a02002 	mov	r2, #2
400088e8:	e5832000 	str	r2, [r3]
400088ec:	ea000004 	b	40008904 <do_timer1+0xbc>
400088f0:	ebffff9d 	bl	4000876c <stop_timer1>
400088f4:	ea000002 	b	40008904 <do_timer1+0xbc>
400088f8:	e1a00000 	nop			; (mov r0, r0)
400088fc:	ea000000 	b	40008904 <do_timer1+0xbc>
40008900:	e1a00000 	nop			; (mov r0, r0)
40008904:	e59f301c 	ldr	r3, [pc, #28]	; 40008928 <do_timer1+0xe0>
40008908:	e59f2018 	ldr	r2, [pc, #24]	; 40008928 <do_timer1+0xe0>
4000890c:	e5922000 	ldr	r2, [r2]
40008910:	e3822040 	orr	r2, r2, #64	; 0x40
40008914:	e5832000 	str	r2, [r3]
40008918:	e8bd8800 	pop	{fp, pc}
4000891c:	40010ac0 	andmi	r0, r1, r0, asr #21
40008920:	40010ac4 	andmi	r0, r1, r4, asr #21
40008924:	40010ac8 	andmi	r0, r1, r8, asr #21
40008928:	139d0044 	orrsne	r0, sp, #68	; 0x44

4000892c <set_backlight_start>:
4000892c:	e92d4800 	push	{fp, lr}
40008930:	e28db004 	add	fp, sp, #4
40008934:	e24dd010 	sub	sp, sp, #16
40008938:	e50b0010 	str	r0, [fp, #-16]
4000893c:	e51b3010 	ldr	r3, [fp, #-16]
40008940:	e2833080 	add	r3, r3, #128	; 0x80
40008944:	e50b3010 	str	r3, [fp, #-16]
40008948:	e59f3064 	ldr	r3, [pc, #100]	; 400089b4 <set_backlight_start+0x88>
4000894c:	e3a02000 	mov	r2, #0
40008950:	e5832000 	str	r2, [r3]
40008954:	ebffff8f 	bl	40008798 <set_gpx1_2_high>
40008958:	e3e03053 	mvn	r3, #83	; 0x53
4000895c:	e54b3005 	strb	r3, [fp, #-5]
40008960:	e55b2005 	ldrb	r2, [fp, #-5]
40008964:	e51b3010 	ldr	r3, [fp, #-16]
40008968:	e0223003 	eor	r3, r2, r3
4000896c:	e59f2044 	ldr	r2, [pc, #68]	; 400089b8 <set_backlight_start+0x8c>
40008970:	e7d23003 	ldrb	r3, [r2, r3]
40008974:	e54b3005 	strb	r3, [fp, #-5]
40008978:	e51b3010 	ldr	r3, [fp, #-16]
4000897c:	e1a02403 	lsl	r2, r3, #8
40008980:	e55b3005 	ldrb	r3, [fp, #-5]
40008984:	e0822003 	add	r2, r2, r3
40008988:	e59f302c 	ldr	r3, [pc, #44]	; 400089bc <set_backlight_start+0x90>
4000898c:	e5832000 	str	r2, [r3]
40008990:	e59f3024 	ldr	r3, [pc, #36]	; 400089bc <set_backlight_start+0x90>
40008994:	e5933000 	ldr	r3, [r3]
40008998:	e1a02803 	lsl	r2, r3, #16
4000899c:	e59f3018 	ldr	r3, [pc, #24]	; 400089bc <set_backlight_start+0x90>
400089a0:	e5832000 	str	r2, [r3]
400089a4:	ebffff19 	bl	40008610 <timer1_init>
400089a8:	ebffff90 	bl	400087f0 <set_gpx1_2_low>
400089ac:	e24bd004 	sub	sp, fp, #4
400089b0:	e8bd8800 	pop	{fp, pc}
400089b4:	40010ac0 	andmi	r0, r1, r0, asr #21
400089b8:	400089c0 	andmi	r8, r0, r0, asr #19
400089bc:	40010ac8 	andmi	r0, r1, r8, asr #21

Disassembly of section .rodata:

400089c0 <crc8_tab>:
400089c0:	090e0700 	stmdbeq	lr, {r8, r9, sl}
400089c4:	15121b1c 	ldrne	r1, [r2, #-2844]	; 0xb1c
400089c8:	31363f38 	teqcc	r6, r8, lsr pc
400089cc:	2d2a2324 	stccs	3, cr2, [sl, #-144]!	; 0xffffff70
400089d0:	797e7770 	ldmdbvc	lr!, {r4, r5, r6, r8, r9, sl, ip, sp, lr}^
400089d4:	65626b6c 	strbvs	r6, [r2, #-2924]!	; 0xb6c
400089d8:	41464f48 	cmpmi	r6, r8, asr #30
400089dc:	5d5a5354 	ldclpl	3, cr5, [sl, #-336]	; 0xfffffeb0
400089e0:	e9eee7e0 	stmib	lr!, {r5, r6, r7, r8, r9, sl, sp, lr, pc}^
400089e4:	f5f2fbfc 	undefined instruction 0xf5f2fbfc
400089e8:	d1d6dfd8 	ldrsble	sp, [r6, #248]	; 0xf8
400089ec:	cdcac3c4 	stclgt	3, cr12, [sl, #784]	; 0x310
400089f0:	999e9790 	ldmibls	lr, {r4, r7, r8, r9, sl, ip, pc}
400089f4:	85828b8c 	strhi	r8, [r2, #2956]	; 0xb8c
400089f8:	a1a6afa8 	undefined instruction 0xa1a6afa8
400089fc:	bdbab3b4 	ldclt	3, cr11, [sl, #720]!	; 0x2d0
40008a00:	cec9c0c7 	cdpgt	0, 12, cr12, cr9, cr7, {6}
40008a04:	d2d5dcdb 	sbcsle	sp, r5, #56064	; 0xdb00
40008a08:	f6f1f8ff 	undefined instruction 0xf6f1f8ff
40008a0c:	eaede4e3 	b	3fb81da0 <_start-0x486260>
40008a10:	beb9b0b7 	mrclt	0, 5, fp, cr9, cr7, {5}
40008a14:	a2a5acab 	adcge	sl, r5, #43776	; 0xab00
40008a18:	8681888f 	strhi	r8, [r1], pc, lsl #17
40008a1c:	9a9d9493 	bls	3e76dc70 <_start-0x189a390>
40008a20:	2e292027 	cdpcs	0, 2, cr2, cr9, cr7, {1}
40008a24:	32353c3b 	eorscc	r3, r5, #15104	; 0x3b00
40008a28:	1611181f 	undefined instruction 0x1611181f
40008a2c:	0a0d0403 	beq	40349a40 <__bss_end__+0x338f74>
40008a30:	5e595057 	mrcpl	0, 2, r5, cr9, cr7, {2}
40008a34:	42454c4b 	submi	r4, r5, #19200	; 0x4b00
40008a38:	6661686f 	strbtvs	r6, [r1], -pc, ror #16
40008a3c:	7a7d7473 	bvc	41f65c10 <__bss_end__+0x1f55144>
40008a40:	80878e89 	addhi	r8, r7, r9, lsl #29
40008a44:	9c9b9295 	lfmls	f1, 1, [fp], {149}	; (ldcls 2, cr9, [fp], {149})	; 0x95
40008a48:	b8bfb6b1 	ldmlt	pc!, {r0, r4, r5, r7, r9, sl, ip, sp, pc}
40008a4c:	a4a3aaad 	strtge	sl, [r3], #2733	; 0xaad
40008a50:	f0f7fef9 	undefined instruction 0xf0f7fef9
40008a54:	ecebe2e5 	sfm	f6, 3, [fp], #916	; (stcl 2, cr14, [fp], #916)	; 0x394
40008a58:	c8cfc6c1 	stmiagt	pc, {r0, r6, r7, r9, sl, lr, pc}^
40008a5c:	d4d3dadd 	ldrble	sp, [r3], #2781	; 0xadd
40008a60:	60676e69 	rsbvs	r6, r7, r9, ror #28
40008a64:	7c7b7275 	lfmvc	f7, 2, [fp], #-468	; (ldclvc 2, cr7, [fp], #-468)	; 0xfffffe2c
40008a68:	585f5651 	ldmdapl	pc, {r0, r4, r6, r9, sl, ip, lr}^
40008a6c:	44434a4d 	strbmi	r4, [r3], #-2637	; 0xa4d
40008a70:	10171e19 	andsne	r1, r7, r9, lsl lr
40008a74:	0c0b0205 	sfmeq	f0, 4, [fp], {5}	; (stceq 2, cr0, [fp], {5})
40008a78:	282f2621 	stmdacs	pc!, {r0, r5, r9, sl, sp}
40008a7c:	34333a3d 	ldrtcc	r3, [r3], #-2621	; 0xa3d
40008a80:	4740494e 	strbmi	r4, [r0, -lr, asr #18]
40008a84:	5b5c5552 	blpl	4171dfd4 <__bss_end__+0x170d508>
40008a88:	7f787176 	svcvc	0x00787176
40008a8c:	63646d6a 	cmnvs	r4, #6784	; 0x1a80
40008a90:	3730393e 	undefined instruction 0x3730393e
40008a94:	2b2c2522 	blcs	40b11f24 <__bss_end__+0xb01458>
40008a98:	0f080106 	svceq	0x00080106
40008a9c:	13141d1a 	tstne	r4, #1664	; 0x680
40008aa0:	a7a0a9ae 	strge	sl, [r0, lr, lsr #19]!
40008aa4:	bbbcb5b2 	bllt	3ef36174 <_start-0x10d1e8c>
40008aa8:	9f989196 	svcls	0x00989196
40008aac:	83848d8a 	orrhi	r8, r4, #8832	; 0x2280
40008ab0:	d7d0d9de 	undefined instruction 0xd7d0d9de
40008ab4:	cbccc5c2 	blgt	3f33a1c4 <_start-0xccde3c>
40008ab8:	efe8e1e6 	svc	0x00e8e1e6
40008abc:	f3f4fdfa 	undefined instruction 0xf3f4fdfa

Disassembly of section .bss:

40010ac0 <one_wire_status>:
40010ac0:	00000000 	andeq	r0, r0, r0

40010ac4 <io_bit_count>:
40010ac4:	00000000 	andeq	r0, r0, r0

40010ac8 <io_data>:
40010ac8:	00000000 	andeq	r0, r0, r0

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
   0:	3a434347 	bcc	10d0d24 <_start-0x3ef372dc>
   4:	74632820 	strbtvc	r2, [r3], #-2080	; 0x820
   8:	312d676e 	teqcc	sp, lr, ror #14
   c:	312e382e 	teqcc	lr, lr, lsr #16
  10:	2941462d 	stmdbcs	r1, {r0, r2, r3, r5, r9, sl, lr}^
  14:	352e3420 	strcc	r3, [lr, #-1056]!	; 0x420
  18:	Address 0x00000018 is out of bounds.

