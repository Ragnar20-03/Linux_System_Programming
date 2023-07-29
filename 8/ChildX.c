#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    printf("Inside Second  Process\n");
    printf("PID of Seconf Process is %d And PID of Parent Process of Second is  %d \n" , getpid() , getppid());
return 0 ; 
}