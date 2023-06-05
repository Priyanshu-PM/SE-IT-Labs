/**
 * Assignment 4 : LED blinking with specific delay
 * Name : Priyanshu PM
*/

#include<xc.h>
#include <pic18f4550.h>


//  delay function
void delay(void)
{

    //  prescaler of 1:256
    T0CON = 0x07;
    TMR0 = 18720;

    //  turning the Timer 0 on
    T0CONbits.TMR0ON = 1;

    //  turning of the TMR0 interrupt flag
    INTCONbits.TMR0IF = 0;

    //  counting till the interrupt occurs or TMR0IF is not set to 1
    while(INTCONbits.TMR0IF == 0);

    //  turning the timer off
    T0CONbits.TMR0ON = 0;

    //  turning the interrupt flag off after the interrupt has occured
    INTCONbits.TMR0IF = 0;
    return;
}
void main(void)
{

    //  setting PORT B as output
    TRISA = 0;

    //  changing the values of PORTB accordingly to generate specific pattern

    PORTB = 0x00000001;
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

    //  end of program

    return;
}