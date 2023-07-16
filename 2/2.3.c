#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/dir.h>
#include<dirent.h>

int main(int argc , char * argv[])
{
    DIR * dp = NULL;
    struct dirent *temp = NULL;

    if ( argc != 2 )
    {
        printf("Invalid Number of Arguments \n");
        return-1;
    }

    dp = opendir(argv[1]);
    if ( dp == NULL)
    {
        printf("Unable to open Directoryb \n");
        return -1;
    }

    while ( (temp = readdir(dp) ) != NULL )
    {
        printf(" File Name is  \t : %s   \n",temp->d_name );
    }

    return 0;
}