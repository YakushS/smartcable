#ifndef __MACRO_H
#define __MACRO_H

#include "stm8l15x_conf.h"

#define SET(a,b) 		(a)->ODR|=(b)
#define RESET(a,b)		(a)->ODR&=~(b)
#define TOGGLE(a,b) 	        (a)->ODR^=(b)

#define TEST_PORT	        GPIOB
#define TEST_PIN		GPIO_Pin_5

#endif