#include "nrf.h"
#include <asm/io.h>		//ioread32
#include <linux/delay.h>	//mdelay()

//类似C++中的类,类中有私有属性,提供public方法,get_v()和put_v()
void __iomem *v;

int get_v(void)
{
	v = ioremap(EXYNOS4_PA_NRF24L01, EXYNOS4_SZ_NRF24L01);
	if (!v) {
		return -1;
	}

	return 0;
}

void put_v(void)
{
	iounmap(v);
}

//在第一次发送时,MOSI每发送一位,MISO就会收到一位数据
//Master Input Slave Output 

//读MISO引脚
int NFR_MISO_STATUS(void)
{
	//GPBDAT[2]: 对应的就是GPBCON[2]位,就是MISO引脚
	return (ioread32(v + GPBDAT) >> 2) & 1;
}

//发送1
void NFR_MOSI_HIGH(void)
{
	u32 val;

	val = ioread32(v + GPBDAT);
	val |= 1 << 3;
	iowrite32(val, v + GPBDAT);
}

//发送0
void NFR_MOSI_LOW(void)
{
	u32 val;

	val = ioread32(v + GPBDAT);
	val &= ~(1 << 3);
	iowrite32(val, v + GPBDAT);
}

//时钟高
void NRF_SCK_HIGH(void)
{
	u32 val;

	val = ioread32(v + GPBDAT);
	val |= 1;
	iowrite32(val, v + GPBDAT);
}

//时钟低
void NRF_SCK_LOW(void)
{
	u32 val;

	val = ioread32(v + GPBDAT);
	val &= ~(1 << 0);
	iowrite32(val, v + GPBDAT);
}

//片选高
void NRF_CSN_HIGH(void)
{
	u32 val;

	val = ioread32(v + GPBDAT);
	val |= 1 << 1;
	iowrite32(val, v + GPBDAT);
}

//片选低有效
void NRF_CSN_LOW(void)
{
	u32 val;

	val = ioread32(v + GPBDAT);
	val &= ~(1 << 1);
	iowrite32(val, v + GPBDAT);
}

void NRF_CE_LOW(void)
{
	u32 val;

	val = ioread32(v + GPA1DAT);
	val &= ~(1 << 1);
	iowrite32(val, v + GPA1DAT);
}

//CE为高电平时，结合其他状态，来使能发射或者接收
//4412与nrf24l01交互时,不需要打开CE,nrf24l01与nrf24l01通信时才需要
void NRF_CE_HIGH(void)
{
	u32 val;

	val = ioread32(v + GPA1DAT);
	val |= (1 << 1);
	iowrite32(val, v +  GPA1DAT);
}

//读取irq的值,当为0时,表示数据发送完成
//就是用的一个GPIO引脚
int NRF_Read_IRQ(void)
{
	//GPA1DAT[0]的值
	return ioread32(v + GPA1DAT) & 1;
}

//硬件初始化,配置各个引脚
void Gpio_For_Nrf24l01(void)
{
	//CE IRQ 
	u32 val;

	val = ioread32(v + GPA1CON);
	val &= ~0xff;
	val |= 1 << 4; 
	iowrite32(val, v + GPA1CON);

	//miso mosi csn clk     
	val = ioread32(v + GPBCON);
	val &= ~0xffff; 
	val |= (1 << 4) | (1 << 12) | 1;
	iowrite32(val, v + GPBCON);
}


/***************************************************/
//初始化
void SPI_NRF_Init(void)
{
	//配置4412引脚
	Gpio_For_Nrf24l01();
	//不选中
	NRF_CSN_HIGH(); 
	//yun
	mdelay(100);
}

//MOSI发,MISO收
u8 SPI_NRF_RW(u8 dat)
{  	
	int count = 0;

	for (count = 0; count < 8; count++){
		//时钟低电平放数据
		NRF_SCK_LOW();	
		if (dat & 0x80) {
			NFR_MOSI_HIGH();
		} else {
			NFR_MOSI_LOW();
		}
		dat <<= 1;
		//时钟高电平发送
		NRF_SCK_HIGH();
		//每发送一位,就收一位
		dat |= NFR_MISO_STATUS();	
	}
	//拉低复位
	NRF_SCK_LOW();	
	return dat;
}

//寄存器的值或上读写命令,表示接下来要发数据还是收数据
//0x20  0010 0000 |3 = 0010 0011
//u8 SPI_NRF_WriteReg(0x3 | 0x20,5)
//写
u8 SPI_NRF_WriteReg(u8 reg,u8 dat)
{
	u8 status;

	//不使能射频
	NRF_CE_LOW();
	//片选选中
	NRF_CSN_LOW();
	//指定寄存器
	status = SPI_NRF_RW(reg);
	//写数据
	SPI_NRF_RW(dat); 
	//片选关闭
	NRF_CSN_HIGH();	

	return(status);
}

// 00000000  | 3 = 00000011
//读
u8 SPI_NRF_ReadReg(u8 reg)
{
	u8 reg_val;

	//不使能射频
	NRF_CE_LOW();
	//片选打开
	NRF_CSN_LOW();
	//指定寄存器
	SPI_NRF_RW(reg); 
	//随便写什么,就是为了读数据
	reg_val = SPI_NRF_RW(NOP);
	//片选关闭
	NRF_CSN_HIGH();		

	return reg_val;
}	

//从指定寄存器读取bytes字节
u8 SPI_NRF_ReadBuf(u8 reg,u8 *pBuf,u8 bytes)
{
	u8 status, byte_cnt;

	NRF_CE_LOW();
	NRF_CSN_LOW();
	//发8位地址,收到8位数
	status = SPI_NRF_RW(reg); 
	//循环读数据
	for(byte_cnt=0; byte_cnt<bytes; byte_cnt++)		  
		pBuf[byte_cnt] = SPI_NRF_RW(NOP);

	NRF_CSN_HIGH();	
	return status;		
}

//往指定寄存器写bytes字节
u8 SPI_NRF_WriteBuf(u8 reg, u8 *pBuf, u8 bytes)
{
	u8 status, byte_cnt;

	NRF_CE_LOW();
	NRF_CSN_LOW();			
	//发8位地址,收到8位数
	status = SPI_NRF_RW(reg); 
	//循环写数据
	for(byte_cnt=0; byte_cnt<bytes; byte_cnt++)
		SPI_NRF_RW(*pBuf++);

	NRF_CSN_HIGH();			
	return (status);
}

//设置nrf为读模式
void NRF_RX_Mode(u8 channel, u8 *rxaddr, u8 pipesize)
{
	NRF_CE_LOW();	

	//NRF_WRITE_REG+就是0x20 | 写命令或上寄存器地址
	//注意+和|有区别
	SPI_NRF_WriteBuf(NRF_WRITE_REG + RX_ADDR_P0,rxaddr, RX_ADR_WIDTH);
	SPI_NRF_WriteReg(NRF_WRITE_REG + EN_AA, 0x01); 
	SPI_NRF_WriteReg(NRF_WRITE_REG + EN_RXADDR, 0x01);
	SPI_NRF_WriteReg(NRF_WRITE_REG + SETUP_AW, 0x03);
	SPI_NRF_WriteReg(NRF_WRITE_REG + RF_CH, channel);  
	SPI_NRF_WriteReg(NRF_WRITE_REG + RX_PW_P0, pipesize);
	SPI_NRF_WriteReg(NRF_WRITE_REG + RF_SETUP, 0x0f); 
	SPI_NRF_WriteReg(NRF_WRITE_REG + CONFIG, 0x0f); 

	NRF_CE_HIGH();
	//yun
	mdelay(100);
}    

//发送方发送数据需要指定接收方地址,然后立马把发送发地址设置为与接收方地址一致,用于接收数据.
//设置nrf为写模式
void NRF_TX_Mode(u8 channel, u8 *txaddr)
{  
	NRF_CE_LOW();		

	SPI_NRF_WriteBuf(NRF_WRITE_REG+TX_ADDR, txaddr, TX_ADR_WIDTH);  
	//发送方的地址设置成与接收方的地址一样,用于接收
	SPI_NRF_WriteBuf(NRF_WRITE_REG+RX_ADDR_P0,txaddr, RX_ADR_WIDTH);
	SPI_NRF_WriteReg(NRF_WRITE_REG + EN_AA, 0x01);    
	SPI_NRF_WriteReg(NRF_WRITE_REG + EN_RXADDR, 0x01); 
	SPI_NRF_WriteReg(NRF_WRITE_REG + SETUP_AW, 0x03);
	SPI_NRF_WriteReg(NRF_WRITE_REG + SETUP_RETR, 0x1a);
	SPI_NRF_WriteReg(NRF_WRITE_REG + RF_CH, channel);  
	SPI_NRF_WriteReg(NRF_WRITE_REG + RF_SETUP, 0x0f); 
	SPI_NRF_WriteReg(NRF_WRITE_REG + CONFIG, 0x0e);  

	NRF_CE_HIGH();
	mdelay(100);
}

//用于测试4412与nrf24l01物理连接是否正确
u8 NRF_Check(void)
{
	u8 buf[5] = {0xC2, 0xC2, 0xC2, 0xC2, 0xC2};
	u8 buf1[5];
	u8 i; 

	//往TX_ADDR写5个字节数据
	SPI_NRF_WriteBuf(NRF_WRITE_REG + TX_ADDR, buf, 5);
	//再从TX_ADDR读出来
	SPI_NRF_ReadBuf(TX_ADDR, buf1, 5); 
	//判断是否相等
	for (i=0; i<5; i++) {
		if (buf1[i] != 0xC2)
			break;
	} 

	if (i == 5){
		return SUCCESS;  
	} else {
		return ERROR;   
	}
}

//发送数据,校验状态
//nrf24l01与nrf24l01之间的收发数据
u8 NRF_Tx_Dat(u8 *txbuf, u8 len)
{
	u8 state;
	int count = 0;

	NRF_CE_LOW();
	SPI_NRF_WriteBuf(WR_TX_PLOAD, txbuf, len);
	//使能CE位配合其他引脚,配置为发送模式,开始发送
	NRF_CE_HIGH();
	//等待数据发送结束
	while (NRF_Read_IRQ() != 0 && count < TIMEOUT) {
		mdelay(10);
		count++;
	}
	if (count >= TIMEOUT) {
		return TIMEOUT;
	}

	state = SPI_NRF_ReadReg(STATUS);
	SPI_NRF_WriteReg(NRF_WRITE_REG + STATUS, state); 	
	SPI_NRF_WriteReg(FLUSH_TX, NOP); 

	//返回STATUS的状态
	if (state & MAX_RT) {              
		return MAX_RT; 
	} else if (state&TX_DS) {        
		return TX_DS;
	} else {						  
		return ERROR;        
	}
} 

u8 NRF_Rx_Dat(u8 *rxbuf)
{
	u8 len;
	u8 state; 
	int count = 0;

	//射频打开,接收模式
	NRF_CE_HIGH();
	//等待接收完成
	while (NRF_Read_IRQ() != 0 && count < TIMEOUT) {
		mdelay(10);
		count++;
	}
	if (count >= TIMEOUT) {
		return TIMEOUT;
	}

	NRF_CE_LOW();  
	state = SPI_NRF_ReadReg(STATUS);
	SPI_NRF_WriteReg(NRF_WRITE_REG + STATUS, state);

	if (state & RX_DR){ 
		len = SPI_NRF_ReadReg(RX_PW_P0);
		//数据读到rxbuf
		SPI_NRF_ReadBuf(RD_RX_PLOAD, rxbuf, len);
		SPI_NRF_WriteReg(FLUSH_RX, NOP);         
		return RX_DR; 
	} else {    
		return ERROR; 
	}
}






