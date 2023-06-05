/**
 * Assignment 3 : Write a program to perform multiplication or addition of two numbers
 * choice should be given in the file register
 * Name : Priyanshu PM
*/

#include <xc.h>
#include <pic18f458.h>

void main(void)
{
    TRISB = 0;  //  setting port b and port c as output port
    TRISC = 0;
    
    TMR1 = 0xA; //  initializing the register values
    TMR2 = 0x04;

    int choice = 0xF;   //  choice to be given in the file register, initialize it with any value

    while(1)
    {
        if(choice == 1)
        {
            //  multiplication stored in 16 bit TMR0, lower and higher bits displayed in PORTB and PORTC respectively
            TMR0 = TMR1 * TMR2;
            PORTB = TMR0L;
            PORTC = TMR0H;
        }
        else if(choice == 2)
        {
            PORTB = TMR1 / TMR2;     //  Quotient is displayed on PORTB
            PORTC = TMR1 % TMR2;    //  Remainder is displayed on PORTC
        }
    }
    return;
}