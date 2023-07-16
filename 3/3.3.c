#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/dir.h>

// Incomplete
// move from source directory to Destination Directory

int main(int argc , char * argv[])
{
    if ( argc != 3)
    {
        printf("Invalid Number of arguments \n");
        return -1;
    }

    struct dirent * entry = NULL;
    DIR * dp = NULL;
    char oldname[256];
    char newname[256];

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }

    while ( (entry = (readdir ( dp))) != NULL)
    {
        sprintf(oldname , "%s/%s" , argv[1] , entry->d_name);
        sprintf(newname , "%s/%s" , argv[2] , entry->d_name);

        rename(oldname , newname);
    }
    
        // sprintf(oldname , "%s/%s" , argv[1] , entry->d_name);

    return 0;
}