// Get Priority

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sched.h>
#include <sys/resource.h>

int main(int argc  , char * argv[])
{

    int Ret = 0 ;
    int RetX = 0 ;
    printf("......\n");
    Ret = fork();
    if ( Ret == 0 )
    {
        execl ("./Demo" , "NULL" , NULL);
    }
    RetX = fork();
    if ( Ret == 0 )
    {
        execl ("./DemoX" , "NULL" , NULL);
    }
    sched_yield();
// ///////////////
    return 0;

}