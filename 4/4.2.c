#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

//  Create Diectory

int  main( int argc , char * argv[])
{
    if ( argc != 2)
    {
        printf("Invalid number of arguments \n");
        return -1;
    }

    int dir = mkdir ( argv[1]);
    if ( dir == -1)
    {
        printf("Failed to Create Directory \n");
        return -1;
    }
    else 
    {
        printf("Directory Created Sucessfully\n");

    }

    return 0;
}