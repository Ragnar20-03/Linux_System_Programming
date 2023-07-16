#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

//Open file

int main( int argc , char * argv[])
{
    int fd = 0 ;

    if ( argc != 2)
    {
        printf("Invalid Atgumentd\n");
        return -1;
    }

    fd = open  (argv[1] , O_RDWR);
    if ( fd == -1)
    {
        printf("Unable to Open file \n");
        return -1;
    }
    else 
    {
        printf("File open Succesfully with File Descriptor : %d\n" , fd);
    }

    return 0;
}