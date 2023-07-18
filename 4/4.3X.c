#include <stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

#define BLOCK_SIZE 1024

int main(int argc  ,  char *argv[])
{
    char Buffer1 [ BLOCK_SIZE];
    char Buffer2 [ BLOCK_SIZE];
    int fd1 = 0  , fd2 = 0  , ret = 0 , retX = 0  ;
    struct stat sobj1;
    struct stat sobj2;

    fd1 = open(argv[1] , O_RDWR);
    fd2 = open ( argv[2] , O_RDWR);

    if (fd1 == -1 || fd2 == -1)
    {
        printf("Unbale to open Files \n");
        return -1;
    } 

    fstat ( fd1 , &sobj1);
    fstat ( fd2 , &sobj2);

    if(sobj1.st_size != sobj2.st_size )
    {
        printf("Files have different Sizes \n");
        return -1;
    }

        while (( ret = read ( fd1 , Buffer1 , sizeof(Buffer1)) ) != 0)
        {
            ret = read (fd2  ,  Buffer2 , sizeof(Buffer2));
            if ( memcmp ( Buffer1 , Buffer2 , retX) != 0 )
            {
                break;
            }
        }
    
        if ( retX == 0)
        {
            printf("Files are equal \n");
        }
        else 
        {
            printf("Files are Not equal \n");

        }
    return 0;
}