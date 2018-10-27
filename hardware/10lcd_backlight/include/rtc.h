#ifndef LZY_RTC_H
#define LZY_RTC_H

struct time_st {
	int year;
	int month;
	int date;
	int week;
	int hour;
	int minute;
	int second;
};

extern void set_time(struct time_st *t);
extern void get_time(struct time_st *t);
extern void set_alarm(struct time_st *t);
extern void set_tic(void);
extern void do_alarm(void);
extern void do_tic(void);
extern void rtc_init(void);

#define RTC_BASE 0x10070000
#define INTP 	(*(volatile unsigned int *)(RTC_BASE + 0x0030)) 
#define RTCCON  (*(volatile unsigned int *)(RTC_BASE + 0x0040)) 
#define TICCNT  (*(volatile unsigned int *)(RTC_BASE + 0x0044)) 
#define RTCALM  (*(volatile unsigned int *)(RTC_BASE + 0x0050)) 
#define ALMSEC  (*(volatile unsigned int *)(RTC_BASE + 0x0054)) 
#define ALMMIN  (*(volatile unsigned int *)(RTC_BASE + 0x0058)) 
#define ALMHOUR (*(volatile unsigned int *)(RTC_BASE + 0x005C)) 
#define ALMDAY  (*(volatile unsigned int *)(RTC_BASE + 0x0060)) 
#define ALMMON  (*(volatile unsigned int *)(RTC_BASE + 0x0064)) 
#define ALMYEAR (*(volatile unsigned int *)(RTC_BASE + 0x0068)) 
#define BCDSEC  (*(volatile unsigned int *)(RTC_BASE + 0x0070)) 
#define BCDMIN  (*(volatile unsigned int *)(RTC_BASE + 0x0074)) 
#define BCDHOUR (*(volatile unsigned int *)(RTC_BASE + 0x0078)) 
#define BCDDAYWEEK 	(*(volatile unsigned int *)(RTC_BASE + 0x0080)) 
#define BCDDAY 		(*(volatile unsigned int *)(RTC_BASE + 0x007c)) 
#define BCDMON 		(*(volatile unsigned int *)(RTC_BASE + 0x0084)) 
#define BCDYEAR 	(*(volatile unsigned int *)(RTC_BASE + 0x0088))
#define CURTICCNT 	(*(volatile unsigned int *)(RTC_BASE + 0x0090))
#define TICNT 	(*(volatile unsigned int *)(RTC_BASE + 0x0044))

#endif
