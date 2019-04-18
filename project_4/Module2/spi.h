#ifndef _SPI_H
#define _SPI_H

typedef enum { 
  SPI_MSBFIRST, ///< Most significant bit first
  SPI_LSBFIRST  ///< Least significant bit first
} SPI_bit_order;

uint8_t fd;
/* Macros definition */
#define TX_ADDR_SIZE (5)
#define NRF_CONFIG_REG	(0x00)
#define NRF_TXADDR_REG	(0x10)
#define NRF_EN_AA_REG	(0x01)
#define NRF_EN_RXADDR_REG	(0x02)
#define NRF_SETUP_AW_REG	(0x03)
#define NRF_SETUP_RETR_REG	(0x04)
#define NRF_RF_CH_REG	(0x05)
#define NRF_RF_SETUP_REG	(0x06)
#define NRF_STATUS_REG	(0x07)
#define RX_ADDR_P0_REG	(0x0A)
#define NRF_TX_ADDR	(0x10)
#define NRF_FIFO_STATUS_REG	(0x17)
#define NRF_PIPESIZE	(0X11)
#define NRF_ENRXADDR	(0x02)
#define W_TXPAYLOAD	(0xA0)
#define R_RXPAYLOAD	(0x61)

#define NRF_R_REGISTER	(0x00)		
#define NRF_W_REGISTER	(0x20) 
#define NRF_NOP	(0xFF) 
#define NRF_FLUSH_TX	(0xE1)
#define NRF_FLUSH_RX	(0xE2)

/* CONFIG Register Bits */
#define NRF_CONFIG_MASK_RX_DR(x)	(uint8_t)((uint8_t)(x)<<6) /* Mask interrupt caused by RX_DR 1: Interrupt not reflected on the IRQ pin 0: Reflect RX_DR as active low interrupt on the IRQ pin */
#define NRF_CONFIG_MASK_TX_DS(x)	(uint8_t)((uint8_t)(x)<<5) /* Mask interrupt caused by TX_DS 1: Interrupt not reflected on the IRQ pin 0: Reflect TX_DS as active low interrupt on the IRQ pin */
#define NRF_CONFIG_MASK_MAX_RT(x)	(uint8_t)((uint8_t)(x)<<4) /* Mask interrupt caused by MAX_RT 1: Interrupt not reflected on the IRQ pin. 0: Reflect MAX_RT as active low interrupt on the IRQ pin */
#define NRF_CONFIG_EN_CRC(x)	(uint8_t)((uint8_t)(x)<<3) 	   /* Enable CRC. Forced high if one of the bits in EN_AA is high
#define NRF_CONFIG_CRCO_1	(0x00) 							   /* CRC encoding scheme for 1 byte */
#define NORDIC_CONFIG_CRCO_2	(0x04) 
#define NRF_CONFIG_POWER_UP	(0x02) 							   /* 1: Power up */
#define NRF_CONFIG_POWER_DOWN	(0x00)						   /* 0: Power down */
#define NRF_CONFIG_PRIM_RX	(0x01) 						       /* 1: PRX */
#define NRF_CONFIG_PRIM_TX	(0x00) 							   /* 0: PTX */

/* RF Setup Register Bits */
#define NORDIC_PLL_LOCK(x)					(uint8_t)((uint8_t)(x)<<4) 	/* Force PLL lock signal */
#define NORDIC_RF_DR_ONE					(0x00)						/* Air data rate of 1Mbps */
#define NORDIC_RF_DR_TWO					(0x08)						/* Air data rate of 2Mbps */
#define NORDIC_RF_PWR_NEGATIVE_EIGHTEEN		(0x00)						/* RF output power in TX mode of -18dBm */
#define NORDIC_RF_PWR_NEGATIVE_TWELVE		(0x02)						/* RF output power in TX mode of -12dBm */
#define NORDIC_RF_PWR_NEGATIVE_SIX			(0x04)						/* RF output power in TX mode of -6dBm */
#define NORDIC_RF_PWR_ZERO					(0x06)						/* RF output power in TX mode of 0dBm */
#define NORDIC_LNA_HCURR(x) (uint8_t)((uint8_t)(x)<<0) 					/* Setup LNA gain */


/// Buffer size at least large enough to fit the max length of "/dev/spidevX.Y"
#define SPIDEV_PATH_LEN 20
 /// Maximum transfer size set to standard page size of 4096 bytes
#define MAX_TRANSFER_SIZE 4096



int SPI_open(uint8_t bus, uint8_t cs);

int SPI_setMode(int spidev_fd, uint8_t mode);

void SPI_close(int spidev_fd);

int SPI_read(int spidev_fd, void *rx_buffer, int n_words);

int SPI_write(int spidev_fd, void *tx_buffer, int n_words);

int SPI_transaction(int spidev_fd, void *tx_buffer, int n_tx_words, 
                    void *rx_buffer, int n_rx_words);

int SPI_transfer(int spidev_fd, void *tx_buffer, void *rx_buffer, int n_words);

int SPI_setBitOrder(int spidev_fd, SPI_bit_order bit_order);

int SPI_setBitsPerWord(int spidev_fd, uint8_t bits_per_word);

int SPI_getBitsPerWord(int spidev_fd);

int SPI_setMaxFrequency(int spidev_fd, uint32_t frequency);

int SPI_getMaxFrequency(int spidev_fd);

int SPI_setClockMode(int spidev_fd, uint8_t clock_mode);

int SPI_getClockMode(int spidev_fd);

int SPI_setCSActiveLow(int spidev_fd);

int SPI_setCSActiveHigh(int spidev_fd);

int SPI_enableCS(int spidev_fd);

int SPI_disableCS(int spidev_fd);

int SPI_enableLoopback(int spidev_fd);

int SPI_disableLoopback(int spidev_fd);

int SPI_enable3Wire(int spidev_fd);

int SPI_disable3Wire(int spidev_fd);

int SPI_getMode(int spidev_fd);


void spi_init();


#endif // _SPI_H
