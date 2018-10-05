//#include <iostm8l151f3.h>
//#include "stm8l15x.h"
#include "macro.h"
#include "lis331.h"

volatile uint8_t tmp, x, y, z;
uint8_t buf[64];   
  
int main( void )
{
    // System clock config
  
    CLK_HSEConfig(CLK_HSE_ON);
    CLK_SYSCLKSourceSwitchCmd(ENABLE);
    CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);
    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSE);
    
    // GPIO config
    
    GPIO_DeInit(SPI_CS_PORT); 
    
    SET(SPI_CS_PORT, SPI_CS_PIN);
    GPIO_Init(SPI_CS_PORT, SPI_CS_PIN, GPIO_Mode_Out_PP_High_Fast);
    
    GPIO_Init(SPI_SCK_PORT, SPI_SCK_PIN, GPIO_Mode_Out_PP_High_Fast);
    
    GPIO_Init(SPI_MOSI_PORT, SPI_MOSI_PIN, GPIO_Mode_Out_PP_High_Fast);
    
    GPIO_Init(SPI_MISO_PORT, SPI_MISO_PIN, GPIO_Mode_In_FL_No_IT);
        
    // SPI config
    
    CLK_PeripheralClockConfig( CLK_Peripheral_SPI1, ENABLE );
    
    SPI_DeInit(SPI1);
    SPI_Init( SPI1,
              SPI_FirstBit_MSB,
              SPI_BaudRatePrescaler_16,
              SPI_Mode_Master,
              SPI_CPOL_High,
              SPI_CPHA_2Edge,
              SPI_Direction_2Lines_FullDuplex,
              SPI_NSS_Soft,
              0x00 ); 
    SPI_Cmd( SPI1, ENABLE );
    
    CLK_PeripheralClockConfig( CLK_Peripheral_USART1, ENABLE );
    
    USART_DeInit(USART1);
    USART_Init(USART1, (uint32_t)115200, USART_WordLength_8b, USART_StopBits_1, USART_Parity_No, USART_Mode_RxTx);
    USART_HalfDuplexCmd(USART1, ENABLE);
    
    tmp = acc_read_reg(0x10);
    acc_write_reg(0x20, 0x40);  
    
    while(1)
    {
        while(!(USART1->SR & USART_FLAG_RXNE));
        if( USART1->DR != 0x02 ) continue;     
      
        x = acc_read_reg(0x29);
        y = acc_read_reg(0x2b); 
        z = acc_read_reg(0x2d);
        
        USART1->DR = x;
        while( !(USART1->SR & USART_FLAG_TC) );
        USART1->DR = y;
        while( !(USART1->SR & USART_FLAG_TC) );
        USART1->DR = z;
        while( !(USART1->SR & USART_FLAG_TC) );
    }    
}
 