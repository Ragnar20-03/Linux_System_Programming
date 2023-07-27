#include<sys/stat.h>
#include<stdio.h>

void Stat(char * FileName)
{
    struct stat sobj;
    stat ( FileName , &sobj);
    printf("File Name : %s\n",FileName);
    printf("File Type : %s\n",sobj.st_mode);
    printf("File Size : %d\n" , sobj.st_size);
    printf("Inode Number : %d\n" , sobj.st_ino);
}
