#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

void * ptr = NULL;
int ( *fptr) (int);

int main( int No )
{


ptr = dlopen("./so_files/Factorial.so" , RTLD_LAZY);
if ( ptr == NULL)
{
    printf("Unable to Load Factorial Library\n");
    return -1;
}

fptr = dlsym(ptr , "Factorial");
if (fptr == NULL)
{
    printf("Unable to Factorial Function Address\n");
}

    printf("Inside First Library which calls the Factorial Function from another Library\n");
    return (fptr ( No));

}