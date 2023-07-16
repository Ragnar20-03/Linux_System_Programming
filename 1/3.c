#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

// Check Acces of specifc File 
int main( int argc , char * argv[])
{
    int mode = 0 ;

    if (argc != 3)
    {
        printf("Invalid Arguments\n");
        return -1;
    }
    if ( strcmp ( argv[1] , "read") == 0 )
    {
        mode = R_OK;
    }
    else if (strcmp ( argv[1] , "write") == 0 )
    {
        mode = W_OK;
    }
    else if ( strcmp ( argv[1] , "execute") == 0 )
    {
        mode = X_OK;
    }
    else 
    {
        printf("Invalid Permission \n");
        return -1;
    }

    if (access (argv[1] , mode) < 0)
    {
        printf("Unable to access %s file with %s permission \n" , argv[1] , argv[2]);
        return -1;
    }
    else 
    {
        printf("Succesfully to access %s file with %s permission \n" , argv[1] , argv[2]);
    }


    return 0;
}