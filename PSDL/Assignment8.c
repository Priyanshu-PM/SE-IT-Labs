/**
 * Assignment 8 : Write an Embedded C program for LCD interfacing with PIC 18FXXX.
 * Name : Priyanshu PM
 */

#include <xc.h>
#include <pic18f4550.h>

#define LCD_RS PORTAbits.RA0
#define LCD_EN PORTAbits.RA1

void delay(int n)   //  delay function
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 1000; j++);
    }
}

void sendCommand(unsigned char command)
{
    LCD_RS = 0;     //  instruction mode
    PORTB = command;
    
    LCD_EN = 1;
    delay(1);
    
    LCD_EN = 0;
    delay(1);
}

void sendData(unsigned char data)
{
    LCD_RS = 1;     //  data mode
    PORTB = data;
    
    LCD_EN = 1;
    delay(1);
    
    LCD_EN = 0;
    delay(1);
}

void main(void)
{
    ADCON1 = 0x0f;
    
    TRISAbits.TRISA0 = 0;   //setting the bits as output
    TRISAbits.TRISA1 = 0;
    
    sendCommand(0x38);  //  LCD 8 bit mode, 2 lines, 5 x 7 dots
    sendCommand(0x01);  //  clear display
    delay(100);
    
    sendCommand(0x80);  //  send data on line 1
    
    char *msg1 = "Welcome";
    while(*msg1 != '\0')
    {
        sendData(*msg1);
        msg1++;
    }
    
    delay(100);

    sendCommand(0xC0);  //  send data on line 2
    unsigned int i = 0;
    
    char *msg2 = "to PICT";
    while(msg2[i] != '\0')
    {
        sendData(msg2[i]);
        i++;
    }
    
    delay(100);
    
    while(1);
    return;
}