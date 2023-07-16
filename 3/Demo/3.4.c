#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/dir.h>
#include<dirent.h>

//  Delete All Empty Files From Directory

int main(int argc , char * argv[])
{
    if ( argc != 2)
    {
        printf("Invalid Number of Arguments \n");
        return -1;
    }

    struct dirent * entry = NULL;
    struct stat sobj;
    DIR * dp = NULL;
    char name[256];

    dp = opendir(argv[1]);
    if ( dp == NULL)
    {
        printf("Unable to Load Directory \n");
        return -1;
    }

    while ( ( entry = readdir(dp)) != NULL)
    {
        sprintf(name , "%s/%s" , argv[1] , entry-> d_name);
        stat(name , &sobj);
        
            remove(name);
        
    }

    closedir(dp);

    return 0 ;
}