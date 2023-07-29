#include <stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
    int iRet = 0 ; 
    int cpid = 0 ;
    int ES = 0 ; 
    printf("Before Creating Process\n");
    iRet = fork();
    if ( iRet == 0 )
    {
        execl("./Child" , "Null" , NULL);   
    }
    else 
    {

    printf(" Value of iret : %d\n" , iRet);
    cpid = wait(&ES);
    printf("Procees Terminates Scuccesfuly of id : %d  With Return Status : %d \n" , cpid , ES);
    }

    return 0; 
}