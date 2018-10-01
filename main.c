//#include <iostm8l151f3.h>
//#include "stm8l15x.h"
#include "macro.h"

void delay(unsigned int n)
{
  while (n-- > 0);
}

int main( void )
{
    CLK_HSEConfig(CLK_HSE_ON);
    CLK_SYSCLKSourceSwitchCmd(ENABLE);
    CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);
    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSE);
    
    GPIO_DeInit(TEST_PORT); 
    GPIO_Init(TEST_PORT, TEST_PIN, GPIO_Mode_Out_PP_High_Fast);
    
    SET(TEST_PORT, TEST_PIN);
    RESET(TEST_PORT, TEST_PIN);
    
    while (1)
    {
        TOGGLE(TEST_PORT, TEST_PIN);
    }  
}
