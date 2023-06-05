/**
 * Assignment 1 additon or subtraction of two numbers
 * Name : Priyanshu PM
*/

#include <xc.h>
#include <pic18f458.h>

void main(void)
{

    //  initializing the registers
    TMR0 = 0x09;
    TMR1 = 0x05;

    //  performing the addition of two registers
    TMR2 = TMR0 + TMR1;

    //  setting port A as output
    TRISA = 0;

    //  displaying at port A
    PORTA = TMR2;

    //  end of program
    return;
}