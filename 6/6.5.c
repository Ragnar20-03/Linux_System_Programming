#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc , char * argv[])
{
    char  Buffer[1024];
    int fd = 0 , ret = 0 ; ;

    fd = open ( argv[1] , O_RDWR);
    if ( fd == -1 )
    {
        printf("Unable to open given file\n");
        return -1;
    }


    ftruncate(fd , atoi(argv[2]));
    

    return 0;
}