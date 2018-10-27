#ifndef __NRF_H__
#define __NRF_H__

#include <asm/io.h>	//u8

#define EXYNOS4_PA_NRF24L01     0x11400000
#define EXYNOS4_SZ_NRF24L01     SZ_4K
#define GPA1CON                 0x0020
#define GPA1DAT                 0x0024
#define GPBCON                  0x0040
#define GPBDAT                  0x0044

#define TIMEOUT			100

#define SUCCESS 		1
#define ERROR 			0

//字节宽度
#define TX_ADR_WIDTH    	5
//#define TX_PLOAD_WIDTH  	4

#define RX_ADR_WIDTH  		5
//#define RX_PLOAD_WIDTH	4

//#define CHANAL 		40    

// SPI(nRF24L01) commands
#define NRF_READ_REG    0x00  // Define read command to register
#define NRF_WRITE_REG   0x20  // Define write command to register
#define RD_RX_PLOAD 0x61  // Define RX payload register address
#define WR_TX_PLOAD 0xA0  // Define TX payload register address
#define FLUSH_TX    0xE1  // Define flush TX register command
#define FLUSH_RX    0xE2  // Define flush RX register command
#define REUSE_TX_PL 0xE3  // Define reuse TX payload register command
#define NOP         0xFF  // Define No Operation, might be used to read status register

// SPI(nRF24L01) registers(addresses)
#define CONFIG      0x00  // 'Config' register address
#define EN_AA       0x01  // 'Enable Auto Acknowledgment' register address
#define EN_RXADDR   0x02  // 'Enabled RX addresses' register address
#define SETUP_AW    0x03  // 'Setup address width' register address
#define SETUP_RETR  0x04  // 'Setup Auto. Retrans' register address
#define RF_CH       0x05  // 'RF channel' register address
#define RF_SETUP    0x06  // 'RF setup' register address
#define STATUS      0x07  // 'Status' register address
#define OBSERVE_TX  0x08  // 'Observe TX' register address
#define CD          0x09  // 'Carrier Detect' register address
#define RX_ADDR_P0  0x0A  // 'RX address pipe0' register address
#define RX_ADDR_P1  0x0B  // 'RX address pipe1' register address
#define RX_ADDR_P2  0x0C  // 'RX address pipe2' register address
#define RX_ADDR_P3  0x0D  // 'RX address pipe3' register address
#define RX_ADDR_P4  0x0E  // 'RX address pipe4' register address
#define RX_ADDR_P5  0x0F  // 'RX address pipe5' register address
#define TX_ADDR     0x10  // 'TX address' register address
#define RX_PW_P0    0x11  // 'RX payload width, pipe0' register address
#define RX_PW_P1    0x12  // 'RX payload width, pipe1' register address
#define RX_PW_P2    0x13  // 'RX payload width, pipe2' register address
#define RX_PW_P3    0x14  // 'RX payload width, pipe3' register address
#define RX_PW_P4    0x15  // 'RX payload width, pipe4' register address
#define RX_PW_P5    0x16  // 'RX payload width, pipe5' register address
#define FIFO_STATUS 0x17  // 'FIFO Status Register' register address

#define MAX_RT		0x10
#define TX_DS		0x20
#define RX_DR		0x40

void SPI_NRF_Init(void);
u8 SPI_NRF_RW(u8 dat);
u8 SPI_NRF_ReadReg(u8 reg);
u8 SPI_NRF_WriteReg(u8 reg, u8 dat);
u8 SPI_NRF_ReadBuf(u8 reg, u8 *pBuf, u8 bytes);
u8 SPI_NRF_WriteBuf(u8 reg, u8 *pBuf, u8 bytes);
void NRF_TX_Mode(u8 channel, u8 *txaddr);
void NRF_RX_Mode(u8 channel, u8 *rxaddr, u8 pipesize);
u8 NRF_Rx_Dat(u8 *rxbuf);
u8 NRF_Tx_Dat(u8 *txbuf, u8 len);
u8 NRF_Check(void);

int get_v(void);
void put_v(void);

#endif /* __NRF_H__ */

