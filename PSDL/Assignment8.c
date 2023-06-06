/**
 * Assignment 8 : Write an Embedded C program for LCD interfacing with PIC 18FXXX.
 * Name : Priyanshu PM
*/
#include <xc.h>
#include <pic18f4550.h>

#define LCD_RS PORTAbits.RA0
#define LCD_EN PORTAbits.RA1


void delay(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 1000; j++);
    }
}
void sendInstruction(unsigned char command)
{

}

void sendData(unsigned char data)
{


}


void main(void)
{

    return;
}