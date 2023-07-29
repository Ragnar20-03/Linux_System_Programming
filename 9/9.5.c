// Get Priority

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sched.h>
#include <sys/resource.h>

int main(int argc  , char * argv[])
{

    sched_yield();

    return 0;

}