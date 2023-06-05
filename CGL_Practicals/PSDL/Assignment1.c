/**
 * Assignment 1 additon or subtraction of two numbers
 * Name : Priyanshu PM
*/

#include <xc.h>
#include <pic18f458.h>

void main(void)
{
    TMR0 = 0x09;
    TMR1 = 0x05;
    TMR2 = TMR0 + TMR1;

    TRISA = 0;
    PORTA = TMR2;
    return;
}