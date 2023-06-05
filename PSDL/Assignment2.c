/**
 * Assignment 2 : Addition of an array of integers
 * Name : Priyanshu
*/

//  including the header files

#include <xc.h>
#include <pic18f458.h>

void main(void)
{
    BSR = 0x00; // bank select register (0 selected by default)

    int arr[100]; // creating an array of integers
    int sum = 0;

    for(int i = 0; i< 100; i++)
    {
        arr[i] = 1; //  storing the numbers in sum variable
        sum += arr[i];
    }

    BSR = 0x01; //  BSR change
    TMR0 = sum; //  initializing the TMR0 with sum

    sum = 100;   //  reinitializing the sum variable
    return;
}