#include<string.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>


//  cp Command 

#define BLOCK_SIZE 1024

int main(int argc , char * argv[])
{
    if ( argc != 3)
    {
        printf("Invalid number of arguments \n");
        return -1;
    }

    int fdSource = 0 , fdDest = 0  , iRet = 0  ;
    char Buffer [ BLOCK_SIZE];

    fdSource = open(argv[1] , O_RDONLY);
    if ( fdSource == -1)
    {
        printf("Unable to ope given file \n");
        return -1;
    }

    fdDest = creat(argv[2] , 0777);
    if ( fdDest == -1)
    {
        printf("Unable to Create new File \n");
        return -1;
    }

    while ((iRet = read (fdSource ,Buffer , BLOCK_SIZE ) ) !=  0)
    {
        write(fdDest , Buffer , iRet);
    }

    close(fdSource);
    close(fdDest);

    return 0;
}