#include <common.h>
#include <button.h>

void button_init(void)
{
	//GPX3 [2,3,4,5] input
	GPX3CON &= ~(0xffff << 8);
}

int button_state(void)
{
	int flag;
	//read state
	// [2,3,4,5]
	switch ((GPX3DAT >> 2) & 0xf) {
		//0b1110
		case 0xe:
			flag = 0;
			break;
		//0b1101
		case 0xd:
			flag = 1;
			break;
		//0b1011
		case 0xb:
			flag = 2;
			break;
		//0x0111
		case 7:
			flag = 3;
			break;
		//0b1111
		default:
			flag = 4;
			break;
		
	}

	return flag;
}







