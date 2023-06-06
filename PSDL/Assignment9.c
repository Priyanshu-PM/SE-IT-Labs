/**
 * Assignment 9 : 
 * Name : Priyanshu PM
*/

#include <xc.h>
#include <pic18f4550.h>

#define LCD_RS LATAbits.LATA0
#define LCD_EN LATAbits.LATA1

unsigned char *ch[100];

void delay(unsigned int time)
{
    for(int i = 0; i < time; i++)
    {
        for(int i = 0; i < 1000; i++);
    }
}

void sendCommand(unsigned char command)
{
    LCD_RS = 0;
    PORTB = command;

    LCD_EN = 1;
    delay(10);

    LCD_EN = 0;
    delay(10);
}

void sendData(unsigned char data)
{
    LCD_RS = 1;
    PORTB = data;

    LCD_EN = 1;
    delay(10);

    LCD_EN = 0;
    delay(10);
}

void InitLCD()
{
    ADCON0 = 0x0f;
    TRISB = 0;

    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;

    sendCommand(0x38);
    sendCommand(0x06);
    sendCommand(0x0C);
    sendCommand(0x01);
    sendCommand(0x80);

}


void ADCInit(void)
{
    TRISEbits.RE2 = 1;
    ADCON1 = 0b00000111;
    ADCON2 = 0b10101110;
}

void lcd_display(unsigned int row, unsigned int pos, unsigned char *ch)
{
    if(row == 1)
    {
        sendCommand(0x80 | (pos-1));
    }
    else if(ch == 2)
    {
        sendCommand(0xC0 | (pos-1));
    }
    while(*ch)
        sendData(*ch++);
}

unsigned int read_temp()
{
    ADCON0 = 0b00011101;
    GODONE = 1;
    while(GO_DONE == 1);

    return ADRES;
}

int main(void)
{   
    unsigned int temp;
    InitLCD();
    ADCInit();
    lcd_display(1, 1, "Temperature");
    while(1)
    {
        temp = read_temp();
        temp = (temp*500)/1023;
        //  sprintf(str, "%d C", temp);
        lcd_display(2, 1, temp);
        delay(9000);
        
    }

    return 0;
}