#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

//  Incomplete

#pragma pack (1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc , char * argv[])
{
    int fd = 0 ;
    char name [256];



    printf("Enter the file Name \n");
    scanf("%s" , Name);

    fd = open(name , O_RDWR);
    if ( fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }   


    return 0;
}