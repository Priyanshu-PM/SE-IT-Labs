/**
 * Assignment 4 : LED blinking with specific delay
 * Name : Priyanshu PM
*/

#include<xc.h>
#include <pic18f4550.h>


//  delay function
void delay(void)
{

    T0CON = 0x07;   //  prescaler of 1:256
    TMR0 = 18720;   //  calculated delay
    
    T0CONbits.TMR0ON = 1;   //  turning the Timer 0 on

    INTCONbits.TMR0IF = 0;  //  turning of the TMR0 interrupt flag

    while(INTCONbits.TMR0IF == 0);  //  counting till the interrupt occurs or TMR0IF is not set to 1

    T0CONbits.TMR0ON = 0;   //  turning the timer off

    INTCONbits.TMR0IF = 0;  //  turning the interrupt flag off after the interrupt has occured
    return;
}
void main(void)
{

    
    TRISB = 0;  //  setting PORT B as output

    PORTB = 0x00000001; //  changing the values of PORTB accordingly to generate specific pattern
    while(1)
    {
        delay();
        PORTB = 0x00000001;
        delay();
        PORTB = 0x00000010;
        delay();
        PORTB = 0x00000100;
        delay();
        PORTB = 0x00001000;
        delay();
        PORTB = 0x00010000;
        delay();
        PORTB = 0x00100000;
        delay();
        PORTB = 0x01000000;
        delay();
        PORTB = 0x10000000;
        delay();
        PORTB = 0x00000001;

    }

    

    return;
}