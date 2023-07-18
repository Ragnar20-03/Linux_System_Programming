#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/dir.h>
#include<sys/stat.h>
#include<dirent.h>


#pragma pack (1)
struct FileInfo
{
    char FileName[256];
    int size ; 

};


int main(int argc , char * argv [])
{
    struct dirent * entry = NULL;
    DIR * dp = NULL;
    int fd = 0 ;
    struct stat sobj;
    struct FileInfo fobj;
    char name[256];

    dp = opendir(argv[1]);
    if ( dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }

    fd = creat("InformationRegural" , 0777);
    if ( fd == -1)
    {
        printf("Unable to create file \n");
        return -1;
    }

    while ( (entry = readdir(dp)) != NULL)
    {
        sprintf(name , "%s/%s" , argv[1] , entry->d_name);
        stat ( name , &sobj);
        if ( S_ISREG(sobj.st_mode))
        {
            strcpy(fobj.FileName , entry->d_name);
            fobj.size = sobj.st_size;
            write(fd , &fobj , sizeof(fobj));
        }
    }

char Buffer[1024];
    fd = open ("InformationRegural" , O_RDWR);
    if (fd == -1)
    {
                printf("Unable to open Filesss \n");
        return -1;
    }
        int ret = 0 ;

    while ( (ret = read(fd , Buffer , sizeof(Buffer))) != 0 )
    {
        printf("Read\n");
        write(1 , Buffer ,  ret);
    }

    closedir(dp);
    close(fd);

    return 0 ;
}