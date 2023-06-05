/**
 * Assignment 2 : Addition of an array of integers
 * Name : Priyanshu
*/

#include <xc.h>
#include <pic18f458.h>

void main(void)
{
    BSR = 0x00;
    int arr[100];
    int sum = 0;

    for(int i = 0; i< 100; i++)
    {
        arr[i] = 1;
        sum += arr[i];
    }

    TMR0 = sum;
    BSR = 0x01;
    sum = 100;
    return;
}