#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdio.h>

// Create a Hole in File 

int main(int argc , char * argv[])
{

    int fd = 0 , iRet = 0 ; ;
    char Buffer[1024];
    fd = open ( argv[1] , O_RDWR);

   iRet =  lseek(fd , 0 , SEEK_END);
    printf("%d\n" , iRet);

    write(fd , Buffer , sizeof(Buffer));

       iRet =  lseek(fd , 0 , SEEK_END);
    printf("After Hole :%d\n" , iRet);



    return 0;
}