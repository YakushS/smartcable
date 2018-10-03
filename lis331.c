#include "lis331.h"

#define SINGLE_READ    0x80
#define MULTIPLE_READ  0xC0
#define SINGLE_WRITE   0x00
#define MULTIPLE_WRITE 0x40

static uint8_t  spi_rw(uint8_t byte) 
{ 
  while ((SPI1->SR & (u8)SPI_FLAG_TXE) == RESET);
  SPI1->DR = byte; 
  while ((SPI1->SR & (u8)SPI_FLAG_RXNE) == RESET);
 
  return (uint8_t)SPI1->DR; 
}

uint8_t acc_read_reg(uint8_t adr)
{
    uint8_t ret = 0;
  
    RESET(SPI_CS_PORT, SPI_CS_PIN);
    spi_rw(SINGLE_READ|adr);
    ret = spi_rw(0x00);
    SET(SPI_CS_PORT, SPI_CS_PIN);
    
    return ret;
}  

void acc_write_reg(uint8_t adr, uint8_t val)
{
    RESET(SPI_CS_PORT, SPI_CS_PIN);
    spi_rw(SINGLE_WRITE|adr);
    spi_rw(val);
    SET(SPI_CS_PORT, SPI_CS_PIN);
}  

/*
    RESET(SPI_CS_PORT, SPI_CS_PIN);
    spi_rw(MULTIPLE_READ|0x00);
    for(uint16_t i=0; i<64; i++)
    {  
        buf[i] = spi_rw(0x00);
    }    
    SET(SPI_CS_PORT, SPI_CS_PIN);
*/