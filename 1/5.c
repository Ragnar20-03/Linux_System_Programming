#include<string.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main( int argc , char * argv[])
{
    int fd =  0; 
    char Buffer[atoi(argv[2])];

    if (argc != 3)
    {
        printf("Invalid Number of Arguments \n");
        return -1;
    }

    fd = open(argv[1] , O_RDWR);
    if (fd  == -1)
    {
        printf("Unable to open File \n");
        return -1;
    }

    int iRet = read(fd , Buffer , sizeof(Buffer));
        write(1 , Buffer , iRet);
        printf(" \n");

    close(fd);

    return 0;
}