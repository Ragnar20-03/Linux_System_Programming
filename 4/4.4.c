#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/dir.h>
#include<dirent.h>


int main(int argc  , char * argv[])
{
    if ( argc != 2)
    {
        printf("Invalid number of arguments \n");
        return -1;
    }

    DIR * dp  = NULL;
    struct dirent * entry = NULL;
    int fd = 0 , ret = 0 , fdR = 0  ;
    char Buffer [ 10 ];

    dp = opendir(argv[1]);
    if ( dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }    

    fd = creat("newFile" , 0777);
    if ( fd== -1)
    {
        printf("unbale to create new file \n");
        return -1;
    }

    while (( entry   = readdir (dp  )) != NULL)
    {
        fdR = open (entry->d_name , O_RDWR);
        if ( fdR == -1)
        {
            printf("Unable to Open %s File  \n" , entry->d_name);
        }
        ret = read (fdR , Buffer , sizeof(Buffer) );
        write(fd , Buffer , ret);
        close(fdR);
    }


    return 0;
}