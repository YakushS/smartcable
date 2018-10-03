#ifndef __MACRO_H
#define __MACRO_H

#include "stm8l15x_conf.h"

#define SET(a,b) 		(a)->ODR|=(b)
#define RESET(a,b)		(a)->ODR&=~(b)
#define TOGGLE(a,b) 	        (a)->ODR^=(b)

//-- SPI

#define SPI_SCK_PORT	        GPIOB
#define SPI_SCK_PIN		GPIO_Pin_5

#define SPI_MOSI_PORT	        GPIOB
#define SPI_MOSI_PIN		GPIO_Pin_6

#define SPI_MISO_PORT	        GPIOB
#define SPI_MISO_PIN		GPIO_Pin_7

#define SPI_CS_PORT	        GPIOB
#define SPI_CS_PIN		GPIO_Pin_4

//-- USART

#define USART_TX_RX_PORT        GPIOC
#define USART_TX_RX_PIN		GPIO_Pin_5

#endif