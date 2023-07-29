#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    int Ret = 0;
    int RetX = 0 ;
    int ExitStatus = 0 ;
    Ret = fork();  
    if ( Ret == 0)
    {
        execl("./Child" , "NULL" , NULL);  
    }
    else 
    {
         wait (&ExitStatus);
    }

    RetX = fork();
    if ( RetX == 0)
    {
        execl("./Child" , "NULL" , NULL);  

    }
    else 
    {
        wait (&ExitStatus);
    }
    printf("End of Main\n");

    return 0;
}