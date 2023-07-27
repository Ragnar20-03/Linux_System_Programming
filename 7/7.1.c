#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int (*fptr)(int , int);

    ptr = dlopen("so_files/Arithmatic.so" , RTLD_LAZY);
    if ( ptr == NULL)
    {
        printf("unale to Load Library\n");
        return -1;
    }

    fptr = dlsym(ptr , "Addition");
    if (fptr == NULL)
    {
        printf("Unable to Load Address of a function\n");
        return -1;
    }

    printf("Addition is %d \n" ,fptr(10 , 11));
    fptr = dlsym(ptr , "Subtraction");

    printf("Subtraction is %d \n" ,fptr(10 , 11));

    fptr = dlsym(ptr , "Division");
    printf("Division is %d \n" ,fptr(10 , 11));

    fptr = dlsym(ptr , "Multiplication");
    printf("Multiplication is %d \n" ,fptr(10 , 11));


    return 0;
}