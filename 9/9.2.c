//  Create An New Procees which  Counts Capital and Small

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/dir.h>
#include<dirent.h>

int main(int argc  , char * argv[])
{
    int Ret = 0 ; 
    int RetX = 0 ; 
    int ExitStatus = 0 ;
    
    Ret = fork();
    if ( Ret == 0 )
    {
        execl ("./CountCapital" , "NULL" , NULL);
    }
    else 
    {
        printf("%d Captail \n" , Capital);
        wait ( &ExitStatus);
    }
    RetX = fork();
    if ( Ret == 0 )
    {
        execl ("./CountSmall" , "NULL" , NULL);
    }
    else 
    {
        wait ( &ExitStatus);
    }

    return 0;
}