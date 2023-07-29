#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{

    int Ret1  = 0 ; 
    int Ret2  = 0 ; 
    int Ret3  = 0 ; 
    
    Ret1 = fork();
    Ret2 = fork();
    Ret3 = fork();

    return 0;
}