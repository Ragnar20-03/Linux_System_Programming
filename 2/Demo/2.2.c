#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>


// Writing String in FIle 

int main(int argc  , char * argv[])
{
    int fd = 0 ;
    if ( argc != 2)
    {
        printf("Invalid numbe rof Arguments \n");
        return -1;
    }

    fd = open(argv[1] , O_RDWR);
        int iRet = write (fd , "Hello World" , 11 );
        if ( iRet == -1)
        {
            printf("Unable to write in the File \n");
            return -1;
        }   
        else
        {
            printf("Writing in file is done !!\n");
        } 

    close(fd);

    return 0 ; 
}