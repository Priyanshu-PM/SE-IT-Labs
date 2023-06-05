/**
 * Assignment 1 additon or subtraction of two numbers
 * Name : Priyanshu PM
*/

#include <xc.h>
#include <pic18f458.h>

void main(void)
{
    TMR0 = 0x09;    //  initializing the registers
    TMR1 = 0x05;

    TMR2 = TMR0 + TMR1; //  performing the addition of two registers

    TRISA = 0;  //  setting port A as output

    PORTA = TMR2;   //  displaying at port A
    return;
}