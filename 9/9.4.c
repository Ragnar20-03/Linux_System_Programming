// Increase Priority

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/dir.h>
#include<dirent.h>
#include <sys/resource.h>

int main(int argc  , char * argv[])
{

    printf("Process Priority is %d\n" , getpriority(PRIO_PROCESS ,  0));
    nice (-5);

    printf("Process Priority After Increasing is %d\n" , getpriority(PRIO_PROCESS , 0));


    return 0;
}