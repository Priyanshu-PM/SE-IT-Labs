/**
 * Assignment 2 : Addition of an array of integers
 * Name : Priyanshu
*/

//  including the header files

#include <xc.h>
#include <pic18f458.h>

void main(void)
{

    // bank select register (0 selected by default)
    BSR = 0x00;

    // creating an array of integers
    int arr[100];
    int sum = 0;

    for(int i = 0; i< 100; i++)
    {
        //  storing the numbers in sum variable
        arr[i] = 1;
        sum += arr[i];
    }
    
    //  For demonstration purpose
    BSR = 0x01;

    //  initializing the TMR0 with sum
    TMR0 = sum;

    //  reinitializing the sum variable
    sum = 100;

    //  end of program
    return;
}