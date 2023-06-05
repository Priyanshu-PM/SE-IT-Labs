/**
 * Assignment 3 : Write a program to perform multiplication or addition of two numbers
 * 
 * choice should be given in the file register
 * Name : Priyanshu PM
*/

#include <xc.h>
#include <pic18f458.h>

void main(void)
{

    TRISB = 0;
    TRISC = 0;
    

    TMR1 = 0xA;
    TMR2 = 0x04;

    int choice = 0xF;
    while(1)
    {
        if(choice == 1)
        {
            TMR0 = TMR1 * TMR2;
            PORTB = TMR0L;
            PORTC = TMR0H;
        }
        else if(choice == 2)
        {
            PORTB = TMR1 / TMR2;
            PORTC = TMR1 % TMR2;
        }
    }
    return;
}