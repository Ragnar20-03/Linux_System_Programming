#include<stdio.h>


int Factorial(int No)
{
    printf("Inside the Factorial Function in Second Library\n");
        int iFact = 1 ; 
    for (int iCnt = 1; iCnt <= No  ; iCnt++)
    {
        iFact = iFact * iCnt ;
    }
    return iFact;
}