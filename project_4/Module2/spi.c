#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
#include"spi.h"

int SPI_open(uint8_t bus, uint8_t cs) {
  char device[SPIDEV_PATH_LEN];
  sprintf(device, "/dev/spidev%d.%d", bus, cs);
  return open(device, O_RDWR, 0);
}

int SPI_setMode(int spidev_fd, uint8_t mode) {
  if (ioctl(spidev_fd, SPI_IOC_WR_MODE, &mode) < 0) return -1;
  return 0;
}

void SPI_close(int spidev_fd) {
  close(spidev_fd);
}

int SPI_read(int spidev_fd, void *rx_buffer, int n_words) {
  uint8_t bits_per_word;
  uint32_t n_bytes;
  struct spi_ioc_transfer transfer;
  bits_per_word = SPI_getBitsPerWord(spidev_fd);
  if (bits_per_word < 0) return bits_per_word;
  // Round up to the next biggest number of bytes:
  n_bytes = (uint32_t) (((float) (bits_per_word * n_words)) / 8.0 + 0.5);
  if (!n_bytes) return 0;
  if (n_bytes > MAX_TRANSFER_SIZE) n_bytes = MAX_TRANSFER_SIZE;

  memset((void *) &transfer, 0, sizeof(struct spi_ioc_transfer));
  transfer.tx_buf = 0;
  transfer.rx_buf = (uintptr_t) rx_buffer;
  transfer.len = n_bytes;
  transfer.speed_hz = 0;
  transfer.delay_usecs = 0;
  transfer.bits_per_word = bits_per_word;
  transfer.cs_change = 0;
  if (ioctl(spidev_fd, SPI_IOC_MESSAGE(1), &transfer) < 0) return -1;
  return (n_bytes<<3) / bits_per_word;
}

int SPI_write(int spidev_fd, void *tx_buffer, int n_words) {
  uint8_t bits_per_word;
  uint32_t n_bytes;
  struct spi_ioc_transfer transfer;
  bits_per_word = SPI_getBitsPerWord(spidev_fd);
  if (bits_per_word < 0) return bits_per_word;
  n_bytes = (uint32_t) (((float) (bits_per_word * n_words)) / 8.0 + 0.5);
  if (!n_bytes) return 0;
  if (n_bytes > MAX_TRANSFER_SIZE) n_bytes = MAX_TRANSFER_SIZE;

  memset((void *) &transfer, 0, sizeof(struct spi_ioc_transfer));
  transfer.tx_buf = (uintptr_t) tx_buffer;
  transfer.rx_buf = 0;
  transfer.len = n_bytes;
  transfer.speed_hz = 0;
  transfer.delay_usecs = 0;
  transfer.bits_per_word = bits_per_word;
  transfer.cs_change = 0;
  if (ioctl(spidev_fd, SPI_IOC_MESSAGE(1), &transfer) < 0) return -1;
  return (n_bytes<<3) / bits_per_word;
}

int SPI_transaction(int spidev_fd, void *tx_buffer, int n_tx_words, 
                    void *rx_buffer, int n_rx_words) {
  uint8_t bits_per_word;
  uint32_t n_tx_bytes, n_rx_bytes;
  struct spi_ioc_transfer transfers[2];
  int n_transfers;
  bits_per_word = SPI_getBitsPerWord(spidev_fd);
  if (bits_per_word < 0) return bits_per_word;
  // Round up to the next biggest number of bytes:
  n_tx_bytes = (uint32_t) (((float) (bits_per_word * n_tx_words)) / 8.0 + 0.5);
  n_rx_bytes = (uint32_t) (((float) (bits_per_word * n_rx_words)) / 8.0 + 0.5);
  if (!n_rx_bytes && !n_tx_bytes) return 0;
  if (n_rx_bytes > MAX_TRANSFER_SIZE) n_rx_bytes = MAX_TRANSFER_SIZE;
  if (n_tx_bytes > MAX_TRANSFER_SIZE) n_tx_bytes = MAX_TRANSFER_SIZE;

  n_transfers = 0;
  if (n_tx_bytes) {
      memset((void *) &transfers[n_transfers], 0, 
             sizeof(struct spi_ioc_transfer));

      transfers[n_transfers].tx_buf = (uintptr_t) tx_buffer;
      transfers[n_transfers].rx_buf = 0;
      transfers[n_transfers].len = n_tx_bytes;
      transfers[n_transfers].speed_hz = 0;
      transfers[n_transfers].delay_usecs = 0;
      transfers[n_transfers].bits_per_word = bits_per_word;
      transfers[n_transfers].cs_change = 0;

      ++n_transfers;
  }

  if (n_rx_bytes) {
      memset((void *) &transfers[n_transfers], 0, 
             sizeof(struct spi_ioc_transfer));

      transfers[n_transfers].tx_buf = 0;
      transfers[n_transfers].rx_buf = (uintptr_t) rx_buffer;
      transfers[n_transfers].len = n_rx_bytes + 1;
      transfers[n_transfers].speed_hz = 0;
      transfers[n_transfers].delay_usecs = 0;
      transfers[n_transfers].bits_per_word = bits_per_word;
      transfers[n_transfers].cs_change = 0;

      ++n_transfers;
  }

  if (ioctl(spidev_fd, SPI_IOC_MESSAGE(n_transfers), transfers) < 0) return -1;
  return (n_rx_bytes << 3) / bits_per_word;
}

int SPI_transfer(int spidev_fd, void *tx_buffer, void *rx_buffer, int n_words) {
  uint8_t bits_per_word;
  uint32_t n_bytes;
  struct spi_ioc_transfer transfer;
  bits_per_word = SPI_getBitsPerWord(spidev_fd);
  if (bits_per_word < 0) return bits_per_word;
  n_bytes = (uint32_t) (((float) (bits_per_word * n_words)) / 8.0 + 0.5);
  if (!n_bytes) return 0;
  if (n_bytes > MAX_TRANSFER_SIZE) n_bytes = MAX_TRANSFER_SIZE;

  memset((void *) &transfer, 0, sizeof(struct spi_ioc_transfer));
  transfer.tx_buf = (uintptr_t) tx_buffer;
  transfer.rx_buf = (uintptr_t) rx_buffer;
  transfer.len = n_bytes;
  transfer.speed_hz = 0;
  transfer.delay_usecs = 0;
  transfer.bits_per_word = bits_per_word;
  transfer.cs_change = 0;
  if (ioctl(spidev_fd, SPI_IOC_MESSAGE(1), &transfer) < 0) return -1;
  return (n_bytes<<3) / bits_per_word;
}

int SPI_setBitOrder(int spidev_fd, SPI_bit_order bit_order) {
  uint8_t order = (uint8_t) bit_order; // Just to be safe
  if (ioctl(spidev_fd, SPI_IOC_WR_LSB_FIRST, &order) < 0) return -1;
  return 0;
}

int SPI_setBitsPerWord(int spidev_fd, uint8_t bits_per_word) {
  if (ioctl(spidev_fd, SPI_IOC_WR_BITS_PER_WORD, &bits_per_word) < 0) {
    return -1;
  }
  return 0;
}

int SPI_getBitsPerWord(int spidev_fd) {
  uint8_t bits_per_word;
  if (ioctl(spidev_fd, SPI_IOC_RD_BITS_PER_WORD, &bits_per_word) < 0) {
    return -1;
  } 
  return bits_per_word == 0 ? 8 : bits_per_word;
}

int SPI_setMaxFrequency(int spidev_fd, uint32_t frequency) {
  if (ioctl(spidev_fd, SPI_IOC_WR_MAX_SPEED_HZ, &frequency) < 0) return -1;
  return 0;
}

int SPI_getMaxFrequency(int spidev_fd) {
  uint32_t frequency;
  if (ioctl(spidev_fd, SPI_IOC_RD_MAX_SPEED_HZ, &frequency) < 0) return -1;
  return frequency;
}

int SPI_setClockMode(int spidev_fd, uint8_t clock_mode) {
  uint8_t mode;
  mode = SPI_getMode(spidev_fd);
  if (mode < 0) return mode;
  mode &= ~0x3;
  mode |= clock_mode & 0x3;
  return SPI_setMode(spidev_fd, mode);
}

int SPI_getClockMode(int spidev_fd) {
  uint8_t clock_mode;
  clock_mode = SPI_getMode(spidev_fd);
  if (clock_mode < 0) return clock_mode;
  return clock_mode & 0x3;
}

int SPI_setCSActiveLow(int spidev_fd) {
  int mode = SPI_getMode(spidev_fd);
  if (mode < 0) return -1;
  return SPI_setMode(spidev_fd, mode & ~SPI_CS_HIGH);
}

int SPI_setCSActiveHigh(int spidev_fd) {
  int mode = SPI_getMode(spidev_fd);
  if (mode < 0) return -1;
  return SPI_setMode(spidev_fd, mode | SPI_CS_HIGH);
}

int SPI_enableCS(int spidev_fd) {
  int mode = SPI_getMode(spidev_fd);
  if (mode < 0) return -1;
  return SPI_setMode(spidev_fd, mode & ~SPI_NO_CS);
}

int SPI_disableCS(int spidev_fd) {
  int mode = SPI_getMode(spidev_fd);
  if (mode < 0) return -1;
  return SPI_setMode(spidev_fd, mode | SPI_NO_CS);
}

int SPI_enableLoopback(int spidev_fd) {
  int mode = SPI_getMode(spidev_fd);
  if (mode < 0) return -1;
  return SPI_setMode(spidev_fd, mode | SPI_LOOP);
}

int SPI_disableLoopback(int spidev_fd) {
  int mode = SPI_getMode(spidev_fd);
  if (mode < 0) return -1;
  return SPI_setMode(spidev_fd, mode & ~SPI_LOOP);
}

int SPI_enable3Wire(int spidev_fd) {
  int mode = SPI_getMode(spidev_fd);
  if (mode < 0) return -1;
  return SPI_setMode(spidev_fd, mode | SPI_3WIRE);
}

int SPI_disable3Wire(int spidev_fd) {
  int mode = SPI_getMode(spidev_fd);
  if (mode < 0) return -1;
  return SPI_setMode(spidev_fd, mode & ~SPI_3WIRE);
}



int SPI_getMode(int spidev_fd) {
  uint8_t mode;
  if (ioctl(spidev_fd, SPI_IOC_RD_MODE, &mode) < 0) return -1;
  return mode;
}

void spi_init()
{
fd = SPI_open(1,0);
        if (fd < 0)
        {       
                printf("can't open device");
        }
        SPI_setMaxFrequency(fd,1000000);
        SPI_setClockMode(fd,0);
        SPI_enable3Wire(fd);
        SPI_setBitOrder(fd,0);
        SPI_setBitsPerWord(fd,8);
}
