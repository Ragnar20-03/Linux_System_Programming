#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main( int argc, char * argv[])
{
    struct stat sobj;
    int fd = 0 ;

    if ( argc != 2)
    {
        printf("Invalid Arguments \n");
        return -1;
    }

    fd = open(argv[1] ,  O_RDWR);
    if (fd == -1)
    {
        printf("Unabe to open file \n");
        return -1;
    }

    fstat(fd , &sobj);
    printf("Name of File is : %s\n",argv[1]);
    printf("Size of File is %d \n" , sobj.st_size);
    printf("Number of Blocks  of File is %d \n" , sobj.st_blocks);
    printf("File System Number is %d \n" , sobj.st_dev);

    close(fd);

    return 0;
}