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
    int ExitStatus = 0 ;
    Ret = fork();
    if ( Ret == 0 )
    {
        execl ("./Child" , "../.." , NULL);
    }
    else 
    {
        wait ( &ExitStatus);
    }
    if ( ExitStatus == 0 )
    {
        printf("Succesfully Created\n");
    }
    return 0;
}