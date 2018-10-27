
int main(void)
{
	__asm__ __volatile__(
		//r0=*nihao
		"ldr r1, =nihao\n"
		"ldr r0, [r1]\n"
		"b end\n"
		"nihao:\n"
		".word 0x10, 0x20\n"
		"end:\n"
		:::"r1", "r0"
	);

	/*
	__asm__ __volatile__(
		//r0=*nihao
		"ldr r0, nihao\n"
		"b end\n"
		"nihao:\n"
		".word 0x10, 0x20\n"
		"end:\n"
		:::"r0"
	);
	*/
	return 0;
}
