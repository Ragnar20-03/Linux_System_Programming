#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/dir.h>
#include<sys/stat.h>
#include<dirent.h>


// Create a hole in a file if < 1kb else truncate reamaining data

int main(int argc , char * argv[])
{

    DIR  * dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    int fd = 0 ;
    char name [256];
    char Buffer[1024];

    dp = opendir(argv[1]);
    if ( dp == NULL)
    {
        printf("Unable to open a file \n");
        return -1;
    }

    while ( (entry = readdir(dp))  != NULL)
    {
        sprintf(name , "%s/%s" , argv[1] , entry -> d_name);
        stat ( name , &sobj);
        if ( S_ISREG( sobj.st_mode))
        {
            fd = open ( name , O_RDWR);
            write(fd , Buffer , sizeof(Buffer));
            if ( sobj.st_size > 1024)
            {
                truncate(name , 1024);
            }

        }
    }
 
    return 0;
}