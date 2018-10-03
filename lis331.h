#ifndef __LIS331_H
#define __LIS331_H

#include "macro.h"

uint8_t acc_read_reg(uint8_t adr);
void acc_write_reg(uint8_t adr, uint8_t val);

#endif