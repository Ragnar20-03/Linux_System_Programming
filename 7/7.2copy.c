// Compare two files

#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>
#include<stdbool.h>

int main(int argc , char * argv[])
{
    if ( argc != 3 )
    {
        printf("Invalid Number of Arguments\n");
        return -1;
    }

    void *ptr = NULL;
    bool (*fptr) (char * , char* ) ;
    bool bRet = false;

    ptr = dlopen("./CompareFiles.so"  ,  RTLD_LAZY);
        if (ptr == NULL)
    {
        printf("Unable to Load Library\n");
        return -1;
    }

    fptr = dlsym(ptr , "CompareFiles");
    if ( fptr == NULL)
    {
        printf("Unable to Load Address of a function\n");
        return -1;
    }

    bRet = fptr(argv[1] , argv[2]);
    if (bRet == false)
    {
        printf("Files Are Different\n");
    }
    else 
    {
        printf("File Are Identical \n");
    }

    return 0;
}