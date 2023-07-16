#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/dir.h>
#include<dirent.h>


//  Check File is Present or Not

int main(int argc , char * argv[])
{
    if ( argc != 3)
    {
        printf("Invalid number of arguments \n");
        return -1;
    }

    DIR * dp = NULL;
    struct dirent * entry = NULL;

    dp = opendir(argv[1]);
    if ( dp == NULL)
    {
        printf("Unable to Load directory \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {

        if (strcmp ( argv[2] , entry -> d_name) == 0 )
        {
            break;
        }
    }

    if (entry == NULL)
    {
        printf("Not Present\n");
    }
    else{
        printf("Present\n");
    }
    return 0;
}