#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/dir.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

//  Largest File in Directory .. 

int main(int argc  , char * argv[])
{
    if ( argc != 2)
    {
        printf("Invalid number of arguments ..\n");
        return -1;
    }

    struct dirent * entry = NULL;
    DIR * dp = NULL;
    int iMax = 0 ;
    struct stat sobj;
    char name[30];
    char nameX[30];

    dp = opendir(argv[1]);
    if (dp  == NULL )
    {     
        printf("Unable to open Directory .. \n");
        return -1;
    }     

    while ( (entry = readdir(dp) ) != NULL)
    {
        sprintf(name , "%s/%s" , argv[1] , entry->d_name);
        stat(name , &sobj);
        if ( S_ISREG(sobj.st_mode))
        {
            if(iMax < sobj.st_size)
            {
                iMax = sobj.st_size;
                strcpy(nameX , name);
            }
        }
    }

    printf("the Largest File is %s Having number of %d bytes \n" , nameX , iMax);

    closedir(dp);
    return 0;
}