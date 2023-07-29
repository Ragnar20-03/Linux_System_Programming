
#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sched.h>

int main()
{
    sched_yield();
    printf("Inside Yeild Process\n");


    return 0; 
}