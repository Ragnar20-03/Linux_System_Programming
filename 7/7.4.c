// Library which loads another library

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<stdbool.h>


int main( int argc , char * argv[])
{
    void * ptr  = NULL;
    int ( *fptr)(int);
    int iValue = 0 ;

    ptr = dlopen("./so_files/First.so" , RTLD_LAZY);
    if ( ptr == NULL)
    {
        printf("Unable to Load First Library\n");
        return -1;
    }


    fptr = dlsym(ptr , "main");
    if ( fptr == NULL)
    {
        printf("Unable to Load The Address of main function\n");
        return -1;
    }

    scanf("%d",&iValue);

    printf("Factorial of A Number is  : %d  \n" , fptr(iValue));

    printf("End of Main \n");
    
    return 0;
}