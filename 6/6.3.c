#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<sys/dir.h>

// Create a file in given directory 

int main(int argc , char * argv[])
{
    struct dirent * entry = NULL;
    DIR * dp = NULL;
    char path[256] ;

    int ret = mkdir(argv[1]  , 0777);

    // if ( ret != 0 )
    // {
    //     printf("Failed to Create directory \n");
    //     return -1;
    // }

    dp = opendir(argv[1]);
    if ( dp == NULL)
    {
        printf("Failed to Open directory \n");
        return -1;   
    }

    sprintf(path , "%s/%s" , argv[1] , argv[2]);
    creat(path , 0777);

    return 0;
}