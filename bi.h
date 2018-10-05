#ifndef __BININTERFACE_H
#define __BININTERFACE

#define BI_UART USART1
// Timeout for 115200
//#define RX_BYTE_TIMEOUT 1500
// Timeout for 9600
#define RX_BYTE_TIMEOUT 18000

void bi_write_byte(unsigned char byte);
unsigned char bi_read_byte(void);
bool bi_read_cmd(unsigned char *p_Buf);
void bi_write(unsigned char *buf, unsigned short n);

#endif