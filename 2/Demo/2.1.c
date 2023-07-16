#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


// writing the data of file on Console"


#define BLOCK_SIZE 1024

int main(int argc , char * argv[])
{
    char Buffer[BLOCK_SIZE];
    int iRet = 0 ;

    if ( argc != 2)
    {
        printf("Invalid Number of Arguments \n");
        return -1;
    }
    
    int fd = open ( argv[1] , O_RDONLY);
    if (fd == -1)
    {
        printf("Unable to Open given file \n");
        return -1;
    }

    while ( (iRet  = read(fd, Buffer , BLOCK_SIZE) ) != 0 )
    {
        write(1 , Buffer , iRet);
    }

    close(fd);

    return 0;
}