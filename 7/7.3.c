// 2  Shared Libraries  to Check Prime And Perfect NUmbers 


#include<dlfcn.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    void * ptr1 = NULL;
    void * ptr2 = NULL;
    bool (*fptr) (int );
    bool bRet = false;
    int No = 0;

    ptr1 = dlopen("./so_files/PrimeNumber.so" , RTLD_LAZY);
    ptr2 = dlopen("./so_files/PerfectNumber.so" , RTLD_LAZY);

    if ( ptr1 == NULL || ptr2 == NULL)
    {
        printf("unbale to Load Libraries \n");
        return -1;
    }


    fptr = dlsym(ptr1 , "CheckPrime");
    if (fptr == NULL)
    {
        printf("Unable to Load the address of a Function (Check Prime)\n");
        return -1;
    }

    printf("Enter A Number \n");
    scanf("%d",&No);
    bRet = fptr(No);
    if ( bRet == true)
    {
        printf("Number is Prime \n");
    }
    else 
    {
        printf("Number is Not Prime \n");
    }   
    
    // ///////////////////////////////


    fptr = dlsym(ptr2 , "CheckPerfect");
    if (fptr == NULL)
    {
        printf("Unable to Load the address of a Function (Check Prime)\n");
        return -1;
    }

    printf("Enter A Number \n");
    scanf("%d",&No);
    bRet = fptr(No);
    if ( bRet == true)
    {
        printf("Number is Perfect \n");
    }
    else 
    {
        printf("Number is Not Perfect \n");
    }

    return 0;
}