// OPen file in Specific Mode;

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc , char * argv[])
{
    int fd = 0 ;

    int mode = 0 ;

    if ( argc !=3 )
    {
        printf("Invalid Arguments \n");
        return -1;
    }

    if ( strcmp (argv[2] , "read") == 0 )
    {
        mode = O_RDONLY;
    }
    if ( strcmp (argv[2] , "write") == 0 )
    {
        mode = O_WRONLY;
    }
    if ( strcmp (argv[2] , "readwrite") == 0 )
    {
        mode = O_RDWR;
    }

    fd = open (argv[1] , mode);
    if ( fd == -1)
    {
        printf("Unable to open file \n");
        return -1;
    }
    else{
        printf("Succesfully open file \n");
    }

    close(fd);

    return 0 ;
}