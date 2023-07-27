#include<stdbool.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCK_SIZE 1024


//  //  7.2.c SO
bool CompareFiles(char * File1 , char * File2)
{
    struct stat sobj1;
    struct stat sobj2;
    bool bFlag = true;
    char Buffer[BLOCK_SIZE];
    char BufferX[BLOCK_SIZE];
    int Ret = 0 , fd1 = 0 , fd2 = 0  ;   

    stat (File1 , &sobj1);
    stat (File2 , &sobj2);

    if ( sobj1.st_size !=  sobj2.st_size)
    {   
        bFlag = false;
        return bFlag;
    }

    fd1 = open(File1 , O_RDWR);
    fd2 = open(File2 , O_RDWR);
    if (fd1 == -1 || fd2 == -1)
    {
        printf("Unable to Open Files\n");
        return -1;
    }

    while ( (Ret  = read(fd1 , Buffer , sizeof(Buffer))) != 0 )
    {
        Ret = read ( fd2 , BufferX , sizeof(BufferX));
        if (memcmp ( Buffer , BufferX , Ret) != 0)
        {
            bFlag = false;
            break;
        }
    }

        return bFlag;

}
