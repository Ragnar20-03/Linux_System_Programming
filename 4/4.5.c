#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc , char * argv[])
{
    int fd =  0; 
    char Arr[20];

    if ( argc != 3)
    {
        printf("Invalid number of arguments \n");
        return -1;
    }

    fd = open ( argv[1] , O_RDWR);
    if ( fd == -1)
    {
        printf("UNable to open given file \n");
        return -1;
    }

    lseek(fd , atoi(argv[2]) , 0);
    int ret = read (fd , Arr , sizeof(Arr) );
        write(1 , Arr , ret);

    return 0;
}