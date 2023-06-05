/**
 * Assignment 6 :  Write an Embedded C program for External interrupt input switch press, output at relay.
 * Name : Priyanshu PM
*/

#include <xc.h>
#include <pic18f4550.h>


//  defining the ISR routine
void __interrupt() relay()
{
    if(INTCON3bits.INT1IF == 1)
    {
    // if interrupt is occur, then disable the global interrupt enable and blink the LED
        INTCONbits.GIE = 0;
        PORTAbits.RA4 = 1;
        for(int i = 0; i < 1000; i++)
        {
            for(int i = 0; i < 1000; i++)
            {
                // some delay uptil which the LED will glow
            }
        }

    }

    PORTAbits.RA4 = 0;      //  turn the LED off, turn the global interrupt enable on
    INTCONbits.GIE = 1;
    
    INTCON3bits.INT1IF = 0;     //  reset the interrupt flag

}

void main(void)
{
    TRISBbits.TRISB1 = 1;       // input at switch

    TRISAbits.TRISA4 = 0;       //  output ad PORTA.RA4
    PORTAbits.RA4 = 0;

    INTCON3bits.INT1IE = 1;     // interrupt enable
    INTCON3bits.INT1IF = 0;

    INTCON2bits.INTEDG1 = 0;    // interrupt on high to low transition

    INTCONbits.GIE = 1;     // enabling the interrupt enables
    INTCONbits.PEIE = 1;

    while(1);
    return;
}