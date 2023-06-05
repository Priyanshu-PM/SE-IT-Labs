/**
 * Assignment 3 : Write a program to perform multiplication or addition of two numbers
 * 
 * choice should be given in the file register
 * Name : Priyanshu PM
*/


//  including the header files
#include <xc.h>
#include <pic18f458.h>

void main(void)
{

    //  setting port b and port c as output port
    TRISB = 0;
    TRISC = 0;
    
    //  initializing the register values
    TMR1 = 0xA;
    TMR2 = 0x04;

    //  choice to be given in the file register, initialize it with any value
    int choice = 0xF;

    //  loop for continuous running
    while(1)
    {
        if(choice == 1)
        {
            //  multiplication stored in 16 bit TMR0
            TMR0 = TMR1 * TMR2;

            //  lower 8 bits displayed in PORTB
            PORTB = TMR0L;

            //  higher 8 bits displayed in PORTC
            PORTC = TMR0H;
        }
        else if(choice == 2)
        {
            //  Quotient is displayed on PORTB
            PORTB = TMR1 / TMR2;

            //  Remainder is displayed on PORTC
            PORTC = TMR1 % TMR2;
        }
    }

    //  end of program
    return;
}