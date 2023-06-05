/**
 * Assignment 5 : Write an embedded C program for timer programming ISR based buzzer on or off
 * Name : Priyanshu PM
*/

#include <xc.h>
#include <pic18f458.h>

int buzzer_on = 0, count = 0;

void __interrrupt() buzzgobeep()
{
    if(PIR1bits.TMR1IF == 1)
    {
        if(buzzer_on && count==10)
        {
            buzzer_on = 0;
            PORTAbits.RA5 = 0;
            count = 0;
        }
        else if(!buzzer_on && count==20)
        {
            buzzer_on = 1;
            PORTAbits.RA5 = 1;
            count = 0;
        }
    }
    count++;
    TMR1 = 28038;
    PIR1bits.TMR1If = 0;

}

void main(void)
{

    T1CON = 0xB0;
    TRISAbits.RA5 = 0;
    PORTAbits.RA5 = 0;

    //  interrupts enable and interrupt flag disable

    PIE1bits.TMR1IE = 1;
    PIR1bits.TMR1IF = 0;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;

    T1CONbits.TMR1ON = 1;

    return;
}