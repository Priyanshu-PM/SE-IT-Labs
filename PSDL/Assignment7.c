/**
 * Assignment 7 : Write an Embedded C program for Generating PWM signal for servo motor/DC motor.
 * Name : Priyanshu PM
*/

#include <xc.h>
#include <pic18f4550.h>

// The motor speed is increased from minimum to maximum and then again it will
// be zero. This process is repeated continuously.
void main(void) {
    
    /*
    
    PR2 = 250;             // Set the period register for desired PWM frequency
    TRISCbits.TRISC2 = 0;  // Set RC2 pin as output for PWM signal
    T2CON = 0;             // Clear Timer2 control register
    TMR2 = 0;              // Clear Timer2 value
    CCP1CON = 12;          // Configure CCP1 module for PWM mode
    T2CONbits.TMR2ON = 1;  // Turn on Timer2

    while (1) {
        CCPR1L = 0;  // Start with motor speed at minimum

        // Increase motor speed from minimum to maximum
        for (int count = 0; count < 6; count++) {
            CCPR1L += 50;  // Increase motor speed by increasing duty cycle

            // Delay loop to control the speed change duration
            for (unsigned int i = 0; i < 1000; i++)
                for (unsigned int j = 0; j < 1000; j++)
                    ;
        }
    }
     * 
     * */
    
    unsigned int i;
    
    TRISCbits.TRISC2 = 0;   //  set as output where motor is connected
    CCP1CON = 0b00011100;   //  CCP1 calculated value
    
    T2CON = 0b00000010;     //  1:16 prescale value
    GIE = 1;                //  global interrupt enable
    
    TRISAbits.TRISA4  = 0;  //  led connected to RA4
    while(1)
    {
        TMR2 = 0;
        CCPR1L = 2;     //  CCPR1L calculated value (used for storing duty cycle)
        PR2 = 250;
        
        TMR2ON = 1; //  timer 2 is on
        TMR2IF = 0; //  interrupt flag disable
        for(int i = 2; i < 1000; i++)
        {
            CCPR1L = i;
            for(int j = 0; j < 10000; j++); //  this loop doesn't have a body
            
            PORTAbits.RA4 = ~PORTAbits.RA4; //  changing the LED mode to display the speed change of the motor
            
        }
    }
}