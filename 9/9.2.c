//  Create An New Procees which Writes all file names in a file

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
    int Capital = 0;
    
    Ret = fork();
    if ( Ret == 0 )
    {
        execl ("./CountCapital" , "&Capital" , NULL);
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