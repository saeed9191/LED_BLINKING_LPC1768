#include <lpc17xx.h>   

void delay_ms(unsigned int ms)
{
    unsigned int i,j;

    for(i=0;i<ms;i++)
        for(j=0;j<20000;j++);
}

/* start the main program */
int main() 
{
    SystemInit();                    //Clock and PLL configuration 
    LPC_PINCON->PINSEL4 = 0x00000000;  //Configure the PORT2 Pins as GPIO;
    LPC_GPIO2->FIODIR = 0xffffffff;  //Configure the PORT2 pins as OUTPUT;

    while(1)
    {
        LPC_GPIO2->FIOSET = 0x00000001;     // Make the PIN 2.0 as high------->> it mean's that you have to connect the Positive leg of LED on this PIN:)   
        delay_ms(100);

        LPC_GPIO2->FIOCLR = 0xffffffff;     // Make all the Port pins as low ------>> it can to be 0x00000001 but i do 0xffffffff because of Noise:)
        delay_ms(100);
    }
}


