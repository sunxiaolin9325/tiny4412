
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
50000018:	e24dd010 	sub	sp, sp, #16
5000001c:	eb000194 	bl	50000674 <lcd_init>
50000020:	e3a03000 	mov	r3, #0
50000024:	e50b3008 	str	r3, [fp, #-8]
50000028:	ea00001e 	b	500000a8 <main+0x98>
5000002c:	e3a03000 	mov	r3, #0
50000030:	e50b300c 	str	r3, [fp, #-12]
50000034:	ea000014 	b	5000008c <main+0x7c>
50000038:	e3a03000 	mov	r3, #0
5000003c:	e58d3000 	str	r3, [sp]
50000040:	e3a03000 	mov	r3, #0
50000044:	e58d3004 	str	r3, [sp, #4]
50000048:	e3a00000 	mov	r0, #0
5000004c:	e51b1008 	ldr	r1, [fp, #-8]
50000050:	e51b200c 	ldr	r2, [fp, #-12]
50000054:	e3a03000 	mov	r3, #0
50000058:	eb00018d 	bl	50000694 <draw_point>
5000005c:	e3a03000 	mov	r3, #0
50000060:	e58d3000 	str	r3, [sp]
50000064:	e3a03000 	mov	r3, #0
50000068:	e58d3004 	str	r3, [sp, #4]
5000006c:	e3a00001 	mov	r0, #1
50000070:	e51b1008 	ldr	r1, [fp, #-8]
50000074:	e51b200c 	ldr	r2, [fp, #-12]
50000078:	e3a03000 	mov	r3, #0
5000007c:	eb000184 	bl	50000694 <draw_point>
50000080:	e51b300c 	ldr	r3, [fp, #-12]
50000084:	e2833001 	add	r3, r3, #1
50000088:	e50b300c 	str	r3, [fp, #-12]
5000008c:	e51b200c 	ldr	r2, [fp, #-12]
50000090:	e59f30c8 	ldr	r3, [pc, #200]	; 50000160 <main+0x150>
50000094:	e1520003 	cmp	r2, r3
50000098:	daffffe6 	ble	50000038 <main+0x28>
5000009c:	e51b3008 	ldr	r3, [fp, #-8]
500000a0:	e2833001 	add	r3, r3, #1
500000a4:	e50b3008 	str	r3, [fp, #-8]
500000a8:	e51b2008 	ldr	r2, [fp, #-8]
500000ac:	e59f30b0 	ldr	r3, [pc, #176]	; 50000164 <main+0x154>
500000b0:	e1520003 	cmp	r2, r3
500000b4:	daffffdc 	ble	5000002c <main+0x1c>
500000b8:	e3a03064 	mov	r3, #100	; 0x64
500000bc:	e50b3008 	str	r3, [fp, #-8]
500000c0:	ea00001e 	b	50000140 <main+0x130>
500000c4:	e3a03064 	mov	r3, #100	; 0x64
500000c8:	e50b300c 	str	r3, [fp, #-12]
500000cc:	ea000014 	b	50000124 <main+0x114>
500000d0:	e3a03000 	mov	r3, #0
500000d4:	e58d3000 	str	r3, [sp]
500000d8:	e3a03000 	mov	r3, #0
500000dc:	e58d3004 	str	r3, [sp, #4]
500000e0:	e3a00000 	mov	r0, #0
500000e4:	e51b1008 	ldr	r1, [fp, #-8]
500000e8:	e51b200c 	ldr	r2, [fp, #-12]
500000ec:	e3a030ff 	mov	r3, #255	; 0xff
500000f0:	eb000167 	bl	50000694 <draw_point>
500000f4:	e3a030ff 	mov	r3, #255	; 0xff
500000f8:	e58d3000 	str	r3, [sp]
500000fc:	e3a03000 	mov	r3, #0
50000100:	e58d3004 	str	r3, [sp, #4]
50000104:	e3a00001 	mov	r0, #1
50000108:	e51b1008 	ldr	r1, [fp, #-8]
5000010c:	e51b200c 	ldr	r2, [fp, #-12]
50000110:	e3a03000 	mov	r3, #0
50000114:	eb00015e 	bl	50000694 <draw_point>
50000118:	e51b300c 	ldr	r3, [fp, #-12]
5000011c:	e2833001 	add	r3, r3, #1
50000120:	e50b300c 	str	r3, [fp, #-12]
50000124:	e51b200c 	ldr	r2, [fp, #-12]
50000128:	e59f3038 	ldr	r3, [pc, #56]	; 50000168 <main+0x158>
5000012c:	e1520003 	cmp	r2, r3
50000130:	daffffe6 	ble	500000d0 <main+0xc0>
50000134:	e51b3008 	ldr	r3, [fp, #-8]
50000138:	e2833001 	add	r3, r3, #1
5000013c:	e50b3008 	str	r3, [fp, #-8]
50000140:	e51b2008 	ldr	r2, [fp, #-8]
50000144:	e59f3020 	ldr	r3, [pc, #32]	; 5000016c <main+0x15c>
50000148:	e1520003 	cmp	r2, r3
5000014c:	daffffdc 	ble	500000c4 <main+0xb4>
50000150:	e3a03000 	mov	r3, #0
50000154:	e1a00003 	mov	r0, r3
50000158:	e24bd004 	sub	sp, fp, #4
5000015c:	e8bd8800 	pop	{fp, pc}
50000160:	000001df 	ldrdeq	r0, [r0], -pc
50000164:	0000031f 	andeq	r0, r0, pc, lsl r3
50000168:	0000017b 	andeq	r0, r0, fp, ror r1
5000016c:	000002bb 	undefined instruction 0x000002bb

50000170 <clock_for_lcd>:
50000170:	e92d4800 	push	{fp, lr}
50000174:	e28db004 	add	fp, sp, #4
50000178:	e59f30bc 	ldr	r3, [pc, #188]	; 5000023c <clock_for_lcd+0xcc>
5000017c:	e5932000 	ldr	r2, [r3]
50000180:	e59f30b8 	ldr	r3, [pc, #184]	; 50000240 <clock_for_lcd+0xd0>
50000184:	e59f00b8 	ldr	r0, [pc, #184]	; 50000244 <clock_for_lcd+0xd4>
50000188:	e1a01002 	mov	r1, r2
5000018c:	e12fff33 	blx	r3
50000190:	e59f30a4 	ldr	r3, [pc, #164]	; 5000023c <clock_for_lcd+0xcc>
50000194:	e59f20a0 	ldr	r2, [pc, #160]	; 5000023c <clock_for_lcd+0xcc>
50000198:	e5922000 	ldr	r2, [r2]
5000019c:	e3c2200f 	bic	r2, r2, #15
500001a0:	e5832000 	str	r2, [r3]
500001a4:	e59f3090 	ldr	r3, [pc, #144]	; 5000023c <clock_for_lcd+0xcc>
500001a8:	e59f208c 	ldr	r2, [pc, #140]	; 5000023c <clock_for_lcd+0xcc>
500001ac:	e5922000 	ldr	r2, [r2]
500001b0:	e3822006 	orr	r2, r2, #6
500001b4:	e5832000 	str	r2, [r3]
500001b8:	e59f3088 	ldr	r3, [pc, #136]	; 50000248 <clock_for_lcd+0xd8>
500001bc:	e59f2084 	ldr	r2, [pc, #132]	; 50000248 <clock_for_lcd+0xd8>
500001c0:	e5922000 	ldr	r2, [r2]
500001c4:	e3c2200f 	bic	r2, r2, #15
500001c8:	e5832000 	str	r2, [r3]
500001cc:	e59f3074 	ldr	r3, [pc, #116]	; 50000248 <clock_for_lcd+0xd8>
500001d0:	e59f2070 	ldr	r2, [pc, #112]	; 50000248 <clock_for_lcd+0xd8>
500001d4:	e5922000 	ldr	r2, [r2]
500001d8:	e3822007 	orr	r2, r2, #7
500001dc:	e5832000 	str	r2, [r3]
500001e0:	e59f3064 	ldr	r3, [pc, #100]	; 5000024c <clock_for_lcd+0xdc>
500001e4:	e59f2060 	ldr	r2, [pc, #96]	; 5000024c <clock_for_lcd+0xdc>
500001e8:	e5922000 	ldr	r2, [r2]
500001ec:	e3822001 	orr	r2, r2, #1
500001f0:	e5832000 	str	r2, [r3]
500001f4:	e59f3054 	ldr	r3, [pc, #84]	; 50000250 <clock_for_lcd+0xe0>
500001f8:	e59f2050 	ldr	r2, [pc, #80]	; 50000250 <clock_for_lcd+0xe0>
500001fc:	e5922000 	ldr	r2, [r2]
50000200:	e3822001 	orr	r2, r2, #1
50000204:	e5832000 	str	r2, [r3]
50000208:	e59f3044 	ldr	r3, [pc, #68]	; 50000254 <clock_for_lcd+0xe4>
5000020c:	e59f2040 	ldr	r2, [pc, #64]	; 50000254 <clock_for_lcd+0xe4>
50000210:	e5922000 	ldr	r2, [r2]
50000214:	e3822002 	orr	r2, r2, #2
50000218:	e5832000 	str	r2, [r3]
5000021c:	e1a00000 	nop			; (mov r0, r0)
50000220:	e59f3030 	ldr	r3, [pc, #48]	; 50000258 <clock_for_lcd+0xe8>
50000224:	e5933000 	ldr	r3, [r3]
50000228:	e2033001 	and	r3, r3, #1
5000022c:	e6ef3073 	uxtb	r3, r3
50000230:	e3530000 	cmp	r3, #0
50000234:	1afffff9 	bne	50000220 <clock_for_lcd+0xb0>
50000238:	e8bd8800 	pop	{fp, pc}
5000023c:	1003c234 	andne	ip, r3, r4, lsr r2
50000240:	43e11a2c 	mvnmi	r1, #180224	; 0x2c000
50000244:	50000720 	andpl	r0, r0, r0, lsr #14
50000248:	1003c534 	andne	ip, r3, r4, lsr r5
5000024c:	1003c334 	andne	ip, r3, r4, lsr r3
50000250:	1003c934 	andne	ip, r3, r4, lsr r9
50000254:	10010210 	andne	r0, r1, r0, lsl r2
50000258:	1003c634 	andne	ip, r3, r4, lsr r6

5000025c <clock_for_uart0>:
5000025c:	e92d4800 	push	{fp, lr}
50000260:	e28db004 	add	fp, sp, #4
50000264:	e59f3074 	ldr	r3, [pc, #116]	; 500002e0 <clock_for_uart0+0x84>
50000268:	e5932000 	ldr	r2, [r3]
5000026c:	e59f3070 	ldr	r3, [pc, #112]	; 500002e4 <clock_for_uart0+0x88>
50000270:	e59f0070 	ldr	r0, [pc, #112]	; 500002e8 <clock_for_uart0+0x8c>
50000274:	e1a01002 	mov	r1, r2
50000278:	e12fff33 	blx	r3
5000027c:	e59f3068 	ldr	r3, [pc, #104]	; 500002ec <clock_for_uart0+0x90>
50000280:	e5932000 	ldr	r2, [r3]
50000284:	e59f3058 	ldr	r3, [pc, #88]	; 500002e4 <clock_for_uart0+0x88>
50000288:	e59f0060 	ldr	r0, [pc, #96]	; 500002f0 <clock_for_uart0+0x94>
5000028c:	e1a01002 	mov	r1, r2
50000290:	e12fff33 	blx	r3
50000294:	e59f3058 	ldr	r3, [pc, #88]	; 500002f4 <clock_for_uart0+0x98>
50000298:	e5932000 	ldr	r2, [r3]
5000029c:	e59f3040 	ldr	r3, [pc, #64]	; 500002e4 <clock_for_uart0+0x88>
500002a0:	e59f0050 	ldr	r0, [pc, #80]	; 500002f8 <clock_for_uart0+0x9c>
500002a4:	e1a01002 	mov	r1, r2
500002a8:	e12fff33 	blx	r3
500002ac:	e59f3048 	ldr	r3, [pc, #72]	; 500002fc <clock_for_uart0+0xa0>
500002b0:	e5932000 	ldr	r2, [r3]
500002b4:	e59f3028 	ldr	r3, [pc, #40]	; 500002e4 <clock_for_uart0+0x88>
500002b8:	e59f0040 	ldr	r0, [pc, #64]	; 50000300 <clock_for_uart0+0xa4>
500002bc:	e1a01002 	mov	r1, r2
500002c0:	e12fff33 	blx	r3
500002c4:	e59f3038 	ldr	r3, [pc, #56]	; 50000304 <clock_for_uart0+0xa8>
500002c8:	e5932000 	ldr	r2, [r3]
500002cc:	e59f3010 	ldr	r3, [pc, #16]	; 500002e4 <clock_for_uart0+0x88>
500002d0:	e59f0030 	ldr	r0, [pc, #48]	; 50000308 <clock_for_uart0+0xac>
500002d4:	e1a01002 	mov	r1, r2
500002d8:	e12fff33 	blx	r3
500002dc:	e8bd8800 	pop	{fp, pc}
500002e0:	1003c550 	andne	ip, r3, r0, asr r5
500002e4:	43e11a2c 	mvnmi	r1, #180224	; 0x2c000
500002e8:	50000734 	andpl	r0, r0, r4, lsr r7
500002ec:	1003c250 	andne	ip, r3, r0, asr r2
500002f0:	5000074c 	andpl	r0, r0, ip, asr #14
500002f4:	1003c214 	andne	ip, r3, r4, lsl r2
500002f8:	50000764 	andpl	r0, r0, r4, ror #14
500002fc:	10040200 	andne	r0, r4, r0, lsl #4
50000300:	50000778 	andpl	r0, r0, r8, ror r7
50000304:	10040108 	andne	r0, r4, r8, lsl #2
50000308:	5000078c 	andpl	r0, r0, ip, lsl #15

5000030c <gpio_for_lcd>:
5000030c:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
50000310:	e28db000 	add	fp, sp, #0
50000314:	e59f3058 	ldr	r3, [pc, #88]	; 50000374 <gpio_for_lcd+0x68>
50000318:	e59f2058 	ldr	r2, [pc, #88]	; 50000378 <gpio_for_lcd+0x6c>
5000031c:	e5832000 	str	r2, [r3]
50000320:	e59f3054 	ldr	r3, [pc, #84]	; 5000037c <gpio_for_lcd+0x70>
50000324:	e59f204c 	ldr	r2, [pc, #76]	; 50000378 <gpio_for_lcd+0x6c>
50000328:	e5832000 	str	r2, [r3]
5000032c:	e59f304c 	ldr	r3, [pc, #76]	; 50000380 <gpio_for_lcd+0x74>
50000330:	e59f2040 	ldr	r2, [pc, #64]	; 50000378 <gpio_for_lcd+0x6c>
50000334:	e5832000 	str	r2, [r3]
50000338:	e59f2044 	ldr	r2, [pc, #68]	; 50000384 <gpio_for_lcd+0x78>
5000033c:	e59f3040 	ldr	r3, [pc, #64]	; 50000384 <gpio_for_lcd+0x78>
50000340:	e5933000 	ldr	r3, [r3]
50000344:	e1a03823 	lsr	r3, r3, #16
50000348:	e1a03803 	lsl	r3, r3, #16
5000034c:	e5823000 	str	r3, [r2]
50000350:	e59f202c 	ldr	r2, [pc, #44]	; 50000384 <gpio_for_lcd+0x78>
50000354:	e59f3028 	ldr	r3, [pc, #40]	; 50000384 <gpio_for_lcd+0x78>
50000358:	e5933000 	ldr	r3, [r3]
5000035c:	e3833c22 	orr	r3, r3, #8704	; 0x2200
50000360:	e3833022 	orr	r3, r3, #34	; 0x22
50000364:	e5823000 	str	r3, [r2]
50000368:	e28bd000 	add	sp, fp, #0
5000036c:	e8bd0800 	pop	{fp}
50000370:	e12fff1e 	bx	lr
50000374:	11400180 	smlalbbne	r0, r0, r0, r1
50000378:	22222222 	eorcs	r2, r2, #536870914	; 0x20000002
5000037c:	114001a0 	smlaltbne	r0, r0, r0, r1
50000380:	114001c0 	smlalbtne	r0, r0, r0, r1
50000384:	114001e0 	smlalttne	r0, r0, r0, r1

50000388 <time_for_lcd>:
50000388:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
5000038c:	e28db000 	add	fp, sp, #0
50000390:	e3a03547 	mov	r3, #297795584	; 0x11c00000
50000394:	e3a02083 	mov	r2, #131	; 0x83
50000398:	e5832000 	str	r2, [r3]
5000039c:	e59f3034 	ldr	r3, [pc, #52]	; 500003d8 <time_for_lcd+0x50>
500003a0:	e3a020e0 	mov	r2, #224	; 0xe0
500003a4:	e5832000 	str	r2, [r3]
500003a8:	e59f302c 	ldr	r3, [pc, #44]	; 500003dc <time_for_lcd+0x54>
500003ac:	e59f202c 	ldr	r2, [pc, #44]	; 500003e0 <time_for_lcd+0x58>
500003b0:	e5832000 	str	r2, [r3]
500003b4:	e59f3028 	ldr	r3, [pc, #40]	; 500003e4 <time_for_lcd+0x5c>
500003b8:	e59f2028 	ldr	r2, [pc, #40]	; 500003e8 <time_for_lcd+0x60>
500003bc:	e5832000 	str	r2, [r3]
500003c0:	e59f3024 	ldr	r3, [pc, #36]	; 500003ec <time_for_lcd+0x64>
500003c4:	e59f2024 	ldr	r2, [pc, #36]	; 500003f0 <time_for_lcd+0x68>
500003c8:	e5832000 	str	r2, [r3]
500003cc:	e28bd000 	add	sp, fp, #0
500003d0:	e8bd0800 	pop	{fp}
500003d4:	e12fff1e 	bx	lr
500003d8:	11c00004 	bicne	r0, r0, r4
500003dc:	11c00010 	bicne	r0, r0, r0, lsl r0
500003e0:	000c1509 	andeq	r1, ip, r9, lsl #10
500003e4:	11c00014 	bicne	r0, r0, r4, lsl r0
500003e8:	0019d113 	andseq	sp, r9, r3, lsl r1
500003ec:	11c00018 	bicne	r0, r0, r8, lsl r0
500003f0:	000efb1f 	andeq	pc, lr, pc, lsl fp

500003f4 <lcd_win0_init>:
500003f4:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
500003f8:	e28db000 	add	fp, sp, #0
500003fc:	e59f30f0 	ldr	r3, [pc, #240]	; 500004f4 <lcd_win0_init+0x100>
50000400:	e59f20f0 	ldr	r2, [pc, #240]	; 500004f8 <lcd_win0_init+0x104>
50000404:	e5832000 	str	r2, [r3]
50000408:	e59f30ec 	ldr	r3, [pc, #236]	; 500004fc <lcd_win0_init+0x108>
5000040c:	e59f20ec 	ldr	r2, [pc, #236]	; 50000500 <lcd_win0_init+0x10c>
50000410:	e5832000 	str	r2, [r3]
50000414:	e59f30e8 	ldr	r3, [pc, #232]	; 50000504 <lcd_win0_init+0x110>
50000418:	e59f20e8 	ldr	r2, [pc, #232]	; 50000508 <lcd_win0_init+0x114>
5000041c:	e5832000 	str	r2, [r3]
50000420:	e59f30e4 	ldr	r3, [pc, #228]	; 5000050c <lcd_win0_init+0x118>
50000424:	e59f20e0 	ldr	r2, [pc, #224]	; 5000050c <lcd_win0_init+0x118>
50000428:	e5922000 	ldr	r2, [r2]
5000042c:	e3c22b01 	bic	r2, r2, #1024	; 0x400
50000430:	e5832000 	str	r2, [r3]
50000434:	e59f30d0 	ldr	r3, [pc, #208]	; 5000050c <lcd_win0_init+0x118>
50000438:	e59f20cc 	ldr	r2, [pc, #204]	; 5000050c <lcd_win0_init+0x118>
5000043c:	e5922000 	ldr	r2, [r2]
50000440:	e3c22020 	bic	r2, r2, #32
50000444:	e5832000 	str	r2, [r3]
50000448:	e59f30bc 	ldr	r3, [pc, #188]	; 5000050c <lcd_win0_init+0x118>
5000044c:	e59f20b8 	ldr	r2, [pc, #184]	; 5000050c <lcd_win0_init+0x118>
50000450:	e5922000 	ldr	r2, [r2]
50000454:	e3822001 	orr	r2, r2, #1
50000458:	e5832000 	str	r2, [r3]
5000045c:	e59f30ac 	ldr	r3, [pc, #172]	; 50000510 <lcd_win0_init+0x11c>
50000460:	e59f20a8 	ldr	r2, [pc, #168]	; 50000510 <lcd_win0_init+0x11c>
50000464:	e5922000 	ldr	r2, [r2]
50000468:	e3c22807 	bic	r2, r2, #458752	; 0x70000
5000046c:	e5832000 	str	r2, [r3]
50000470:	e59f3098 	ldr	r3, [pc, #152]	; 50000510 <lcd_win0_init+0x11c>
50000474:	e59f2094 	ldr	r2, [pc, #148]	; 50000510 <lcd_win0_init+0x11c>
50000478:	e5922000 	ldr	r2, [r2]
5000047c:	e3822801 	orr	r2, r2, #65536	; 0x10000
50000480:	e5832000 	str	r2, [r3]
50000484:	e59f3084 	ldr	r3, [pc, #132]	; 50000510 <lcd_win0_init+0x11c>
50000488:	e59f2080 	ldr	r2, [pc, #128]	; 50000510 <lcd_win0_init+0x11c>
5000048c:	e5922000 	ldr	r2, [r2]
50000490:	e3c22007 	bic	r2, r2, #7
50000494:	e5832000 	str	r2, [r3]
50000498:	e59f3070 	ldr	r3, [pc, #112]	; 50000510 <lcd_win0_init+0x11c>
5000049c:	e59f206c 	ldr	r2, [pc, #108]	; 50000510 <lcd_win0_init+0x11c>
500004a0:	e5922000 	ldr	r2, [r2]
500004a4:	e3822001 	orr	r2, r2, #1
500004a8:	e5832000 	str	r2, [r3]
500004ac:	e59f3060 	ldr	r3, [pc, #96]	; 50000514 <lcd_win0_init+0x120>
500004b0:	e3a02000 	mov	r2, #0
500004b4:	e5832000 	str	r2, [r3]
500004b8:	e59f3058 	ldr	r3, [pc, #88]	; 50000518 <lcd_win0_init+0x124>
500004bc:	e59f2058 	ldr	r2, [pc, #88]	; 5000051c <lcd_win0_init+0x128>
500004c0:	e5832000 	str	r2, [r3]
500004c4:	e59f3054 	ldr	r3, [pc, #84]	; 50000520 <lcd_win0_init+0x12c>
500004c8:	e3a02206 	mov	r2, #1610612736	; 0x60000000
500004cc:	e5832000 	str	r2, [r3]
500004d0:	e59f304c 	ldr	r3, [pc, #76]	; 50000524 <lcd_win0_init+0x130>
500004d4:	e59f2020 	ldr	r2, [pc, #32]	; 500004fc <lcd_win0_init+0x108>
500004d8:	e5922000 	ldr	r2, [r2]
500004dc:	e2822306 	add	r2, r2, #402653184	; 0x18000000
500004e0:	e1a02102 	lsl	r2, r2, #2
500004e4:	e5832000 	str	r2, [r3]
500004e8:	e28bd000 	add	sp, fp, #0
500004ec:	e8bd0800 	pop	{fp}
500004f0:	e12fff1e 	bx	lr
500004f4:	11c00020 	bicne	r0, r0, r0, lsr #32
500004f8:	0000802d 	andeq	r8, r0, sp, lsr #32
500004fc:	11c00048 	bicne	r0, r0, r8, asr #32
50000500:	0005dc00 	andeq	sp, r5, r0, lsl #24
50000504:	11c00100 	bicne	r0, r0, r0, lsl #2
50000508:	00638964 	rsbeq	r8, r3, r4, ror #18
5000050c:	11c00034 	bicne	r0, r0, r4, lsr r0
50000510:	11c0003c 	bicne	r0, r0, ip, lsr r0
50000514:	11c00040 	bicne	r0, r0, r0, asr #32
50000518:	11c00044 	bicne	r0, r0, r4, asr #32
5000051c:	0012c168 	andseq	ip, r2, r8, ror #2
50000520:	11c000a0 	bicne	r0, r0, r0, lsr #1
50000524:	11c000d0 	ldrdne	r0, [r0]

50000528 <lcd_win1_init>:
50000528:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
5000052c:	e28db000 	add	fp, sp, #0
50000530:	e59f30fc 	ldr	r3, [pc, #252]	; 50000634 <lcd_win1_init+0x10c>
50000534:	e59f20fc 	ldr	r2, [pc, #252]	; 50000638 <lcd_win1_init+0x110>
50000538:	e5832000 	str	r2, [r3]
5000053c:	e59f30f8 	ldr	r3, [pc, #248]	; 5000063c <lcd_win1_init+0x114>
50000540:	e59f20f8 	ldr	r2, [pc, #248]	; 50000640 <lcd_win1_init+0x118>
50000544:	e5832000 	str	r2, [r3]
50000548:	e59f30f4 	ldr	r3, [pc, #244]	; 50000644 <lcd_win1_init+0x11c>
5000054c:	e59f20f4 	ldr	r2, [pc, #244]	; 50000648 <lcd_win1_init+0x120>
50000550:	e5832000 	str	r2, [r3]
50000554:	e59f30f0 	ldr	r3, [pc, #240]	; 5000064c <lcd_win1_init+0x124>
50000558:	e59f20ec 	ldr	r2, [pc, #236]	; 5000064c <lcd_win1_init+0x124>
5000055c:	e5922000 	ldr	r2, [r2]
50000560:	e3c22b02 	bic	r2, r2, #2048	; 0x800
50000564:	e5832000 	str	r2, [r3]
50000568:	e59f30dc 	ldr	r3, [pc, #220]	; 5000064c <lcd_win1_init+0x124>
5000056c:	e59f20d8 	ldr	r2, [pc, #216]	; 5000064c <lcd_win1_init+0x124>
50000570:	e5922000 	ldr	r2, [r2]
50000574:	e3c22040 	bic	r2, r2, #64	; 0x40
50000578:	e5832000 	str	r2, [r3]
5000057c:	e59f30c8 	ldr	r3, [pc, #200]	; 5000064c <lcd_win1_init+0x124>
50000580:	e59f20c4 	ldr	r2, [pc, #196]	; 5000064c <lcd_win1_init+0x124>
50000584:	e5922000 	ldr	r2, [r2]
50000588:	e3822002 	orr	r2, r2, #2
5000058c:	e5832000 	str	r2, [r3]
50000590:	e59f30b8 	ldr	r3, [pc, #184]	; 50000650 <lcd_win1_init+0x128>
50000594:	e59f20b4 	ldr	r2, [pc, #180]	; 50000650 <lcd_win1_init+0x128>
50000598:	e5922000 	ldr	r2, [r2]
5000059c:	e3c2270e 	bic	r2, r2, #3670016	; 0x380000
500005a0:	e5832000 	str	r2, [r3]
500005a4:	e59f30a4 	ldr	r3, [pc, #164]	; 50000650 <lcd_win1_init+0x128>
500005a8:	e59f20a0 	ldr	r2, [pc, #160]	; 50000650 <lcd_win1_init+0x128>
500005ac:	e5922000 	ldr	r2, [r2]
500005b0:	e3822601 	orr	r2, r2, #1048576	; 0x100000
500005b4:	e5832000 	str	r2, [r3]
500005b8:	e59f3090 	ldr	r3, [pc, #144]	; 50000650 <lcd_win1_init+0x128>
500005bc:	e59f208c 	ldr	r2, [pc, #140]	; 50000650 <lcd_win1_init+0x128>
500005c0:	e5922000 	ldr	r2, [r2]
500005c4:	e3c22038 	bic	r2, r2, #56	; 0x38
500005c8:	e5832000 	str	r2, [r3]
500005cc:	e59f307c 	ldr	r3, [pc, #124]	; 50000650 <lcd_win1_init+0x128>
500005d0:	e59f2078 	ldr	r2, [pc, #120]	; 50000650 <lcd_win1_init+0x128>
500005d4:	e5922000 	ldr	r2, [r2]
500005d8:	e3822010 	orr	r2, r2, #16
500005dc:	e5832000 	str	r2, [r3]
500005e0:	e59f306c 	ldr	r3, [pc, #108]	; 50000654 <lcd_win1_init+0x12c>
500005e4:	e59f206c 	ldr	r2, [pc, #108]	; 50000658 <lcd_win1_init+0x130>
500005e8:	e5832000 	str	r2, [r3]
500005ec:	e59f3068 	ldr	r3, [pc, #104]	; 5000065c <lcd_win1_init+0x134>
500005f0:	e59f2068 	ldr	r2, [pc, #104]	; 50000660 <lcd_win1_init+0x138>
500005f4:	e5832000 	str	r2, [r3]
500005f8:	e59f3064 	ldr	r3, [pc, #100]	; 50000664 <lcd_win1_init+0x13c>
500005fc:	e59f2064 	ldr	r2, [pc, #100]	; 50000668 <lcd_win1_init+0x140>
50000600:	e5832000 	str	r2, [r3]
50000604:	e59f3060 	ldr	r3, [pc, #96]	; 5000066c <lcd_win1_init+0x144>
50000608:	e3a02207 	mov	r2, #1879048192	; 0x70000000
5000060c:	e5832000 	str	r2, [r3]
50000610:	e59f3058 	ldr	r3, [pc, #88]	; 50000670 <lcd_win1_init+0x148>
50000614:	e59f2020 	ldr	r2, [pc, #32]	; 5000063c <lcd_win1_init+0x114>
50000618:	e5922000 	ldr	r2, [r2]
5000061c:	e2822307 	add	r2, r2, #469762048	; 0x1c000000
50000620:	e1a02102 	lsl	r2, r2, #2
50000624:	e5832000 	str	r2, [r3]
50000628:	e28bd000 	add	sp, fp, #0
5000062c:	e8bd0800 	pop	{fp}
50000630:	e12fff1e 	bx	lr
50000634:	11c00024 	bicne	r0, r0, r4, lsr #32
50000638:	0000802d 	andeq	r8, r0, sp, lsr #32
5000063c:	11c0005c 	bicne	r0, r0, ip, asr r0
50000640:	0005dc00 	andeq	sp, r5, r0, lsl #24
50000644:	11c00104 	bicne	r0, r0, r4, lsl #2
50000648:	00c80640 	sbceq	r0, r8, r0, asr #12
5000064c:	11c00034 	bicne	r0, r0, r4, lsr r0
50000650:	11c0003c 	bicne	r0, r0, ip, lsr r0
50000654:	11c00050 	bicne	r0, r0, r0, asr r0
50000658:	000c80f0 	strdeq	r8, [ip], -r0
5000065c:	11c00054 	bicne	r0, r0, r4, asr r0
50000660:	0018f9df 	undefined instruction 0x0018f9df
50000664:	11c00058 	bicne	r0, r0, r8, asr r0
50000668:	00777000 	rsbseq	r7, r7, r0
5000066c:	11c000a8 	bicne	r0, r0, r8, lsr #1
50000670:	11c000d8 	ldrdne	r0, [r0, #8]

50000674 <lcd_init>:
50000674:	e92d4800 	push	{fp, lr}
50000678:	e28db004 	add	fp, sp, #4
5000067c:	ebffff22 	bl	5000030c <gpio_for_lcd>
50000680:	ebfffeba 	bl	50000170 <clock_for_lcd>
50000684:	ebffff3f 	bl	50000388 <time_for_lcd>
50000688:	ebffff59 	bl	500003f4 <lcd_win0_init>
5000068c:	ebffffa5 	bl	50000528 <lcd_win1_init>
50000690:	e8bd8800 	pop	{fp, pc}

50000694 <draw_point>:
50000694:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
50000698:	e28db000 	add	fp, sp, #0
5000069c:	e24dd01c 	sub	sp, sp, #28
500006a0:	e50b0010 	str	r0, [fp, #-16]
500006a4:	e50b1014 	str	r1, [fp, #-20]
500006a8:	e50b2018 	str	r2, [fp, #-24]
500006ac:	e50b301c 	str	r3, [fp, #-28]
500006b0:	e51b3010 	ldr	r3, [fp, #-16]
500006b4:	e3530000 	cmp	r3, #0
500006b8:	1a000002 	bne	500006c8 <draw_point+0x34>
500006bc:	e3a03206 	mov	r3, #1610612736	; 0x60000000
500006c0:	e50b3008 	str	r3, [fp, #-8]
500006c4:	ea000001 	b	500006d0 <draw_point+0x3c>
500006c8:	e3a03207 	mov	r3, #1879048192	; 0x70000000
500006cc:	e50b3008 	str	r3, [fp, #-8]
500006d0:	e51b3018 	ldr	r3, [fp, #-24]
500006d4:	e3a02e32 	mov	r2, #800	; 0x320
500006d8:	e0030392 	mul	r3, r2, r3
500006dc:	e1a02003 	mov	r2, r3
500006e0:	e51b3014 	ldr	r3, [fp, #-20]
500006e4:	e0823003 	add	r3, r2, r3
500006e8:	e1a03103 	lsl	r3, r3, #2
500006ec:	e51b2008 	ldr	r2, [fp, #-8]
500006f0:	e0823003 	add	r3, r2, r3
500006f4:	e51b201c 	ldr	r2, [fp, #-28]
500006f8:	e1a01802 	lsl	r1, r2, #16
500006fc:	e59b2004 	ldr	r2, [fp, #4]
50000700:	e1a02402 	lsl	r2, r2, #8
50000704:	e1811002 	orr	r1, r1, r2
50000708:	e59b2008 	ldr	r2, [fp, #8]
5000070c:	e1812002 	orr	r2, r1, r2
50000710:	e5832000 	str	r2, [r3]
50000714:	e28bd000 	add	sp, fp, #0
50000718:	e8bd0800 	pop	{fp}
5000071c:	e12fff1e 	bx	lr

Disassembly of section .rodata:

50000720 <.rodata>:
50000720:	5f4b4c43 	svcpl	0x004b4c43
50000724:	5f435253 	svcpl	0x00435253
50000728:	3044434c 	subcc	r4, r4, ip, asr #6
5000072c:	25203d20 	strcs	r3, [r0, #-3360]!	; 0xd20
50000730:	000a7823 	andeq	r7, sl, r3, lsr #16
50000734:	5f4b4c43 	svcpl	0x004b4c43
50000738:	5f564944 	svcpl	0x00564944
5000073c:	49524550 	ldmdbmi	r2, {r4, r6, r8, sl, lr}^
50000740:	3d20304c 	stccc	0, cr3, [r0, #-304]!	; 0xfffffed0
50000744:	78232520 	stmdavc	r3!, {r5, r8, sl, sp}
50000748:	0000000a 	andeq	r0, r0, sl
5000074c:	5f4b4c43 	svcpl	0x004b4c43
50000750:	5f435253 	svcpl	0x00435253
50000754:	49524550 	ldmdbmi	r2, {r4, r6, r8, sl, lr}^
50000758:	3d20304c 	stccc	0, cr3, [r0, #-304]!	; 0xfffffed0
5000075c:	78232520 	stmdavc	r3!, {r5, r8, sl, sp}
50000760:	0000000a 	andeq	r0, r0, sl
50000764:	5f4b4c43 	svcpl	0x004b4c43
50000768:	5f435253 	svcpl	0x00435253
5000076c:	31504f54 	cmpcc	r0, r4, asr pc
50000770:	25203d20 	strcs	r3, [r0, #-3360]!	; 0xd20
50000774:	000a7823 	andeq	r7, sl, r3, lsr #16
50000778:	5f4b4c43 	svcpl	0x004b4c43
5000077c:	5f435253 	svcpl	0x00435253
50000780:	20434d44 	subcs	r4, r3, r4, asr #26
50000784:	2325203d 	teqcs	r5, #61	; 0x3d
50000788:	00000a78 	andeq	r0, r0, r8, ror sl
5000078c:	4c4c504d 	mcrrmi	0, 4, r5, ip, cr13
50000790:	4e4f435f 	mcrmi	3, 2, r4, cr15, cr15, {2}
50000794:	203d2030 	eorscs	r2, sp, r0, lsr r0
50000798:	0a782325 	beq	51e09434 <__bss_end__+0x1e00c94>
5000079c:	00000000 	andeq	r0, r0, r0

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

