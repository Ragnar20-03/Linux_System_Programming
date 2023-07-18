#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>

// Delete Files having moret than 100 bytes;
int main(int argc , char * argv[])
{
    struct dirent * entry = NULL;
    DIR * dp = NULL;
    struct stat sobj;
    char name[256] = {'\0'};
    int iCount = 0 ;

    dp = opendir(argv[1]);
    if ( dp == NULL)
    {
        printf("Failed to Open directory \n");
        return -1;   
    }

    while ( (entry = readdir(dp)) != NULL)
    {
        sprintf ( name , "%s/%s" , argv[1] , entry -> d_name);
        stat ( name , &sobj);
        if ( sobj.st_size > 100)
        {
            remove(name);
            printf("%s File Deleted \n" , entry->d_name);
            iCount ++;
        }
    }
    printf("%d files Deleted \n" , iCount);

    closedir(dp);

    return 0;
}