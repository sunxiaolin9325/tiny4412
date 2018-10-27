#include <common.h>
#include <rtc.h>
#include <irq.h>

void set_time(struct time_st *t)
{
	RTCCON = 1;

	BCDSEC = (t->second / 10 << 4) | (t->second % 10);	
	BCDMIN = (t->minute / 10 << 4) | (t->minute % 10);
	BCDHOUR = (t->hour / 10 << 4) | (t->hour % 10);
	BCDDAYWEEK = t->week;
	BCDDAY = (t->date / 10 << 4) | (t->date % 10);
	BCDMON = (t->month / 10 << 4) | (t->month % 10);
	BCDYEAR = (t->year / 10 << 4) | (t->year % 10);

	RTCCON = 0;
}

void get_time(struct time_st *t)
{
	t->year = (BCDYEAR >> 4) * 10 + (BCDYEAR & 0xf); 	
	t->month = (BCDMON >> 4) * 10 + (BCDMON & 0xf);
	t->date = (BCDDAY >> 4) * 10 + (BCDDAY & 0xf);
	t->week = BCDDAYWEEK;
	t->hour = (BCDHOUR >> 4) * 10 + (BCDHOUR & 0xf);
	t->minute = (BCDMIN >> 4) * 10 + (BCDMIN & 0xf);
	t->second = (BCDSEC >> 4) * 10 + (BCDSEC & 0xf);
}

void do_alarm(void)
{
	printf("------------do_alarm------------\n\r");
	
	INTP |= (1 << 1);
}

void set_alarm(struct time_st *t)
{
	RTCALM = (1 << 6) | 1;
	
	ALMSEC = (t->second / 10 << 4) | (t->second % 10);	
	ALMMIN = (t->minute / 10 << 4) | (t->minute % 10);
	ALMHOUR = (t->hour / 10 << 4) | (t->hour % 10);
	ALMDAY = (t->date / 10 << 4) | (t->date % 10);
	ALMMON = (t->month / 10 << 4) | (t->month % 10);
	ALMYEAR = (t->year / 10 << 4) | (t->year % 10);

}

void do_tic(void)
{
	printf("CURTICCNT = %d \n \r", CURTICCNT);

	INTP |= 1;
}
//要求：中断间隔为1s
void set_tic(void)
{
	RTCCON |= 1 << 8; 
	TICNT = 32767; 
	 	
        ICCICR_CPU0 = 1;
        ICCPMR_CPU0 = 255;
        ICDDCR = 1;
	ICDISER2_CPU0 |= (1 << (77-64));
        ICDIPR19_CPU0 &= ~(0xff << 8);
        ICDIPTR19_CPU0 |= (1 << 8);

        __asm__ __volatile__("cpsie i\n");
}











