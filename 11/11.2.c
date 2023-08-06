#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


void * ThreadProc1(void * ptr)
{
    printf("Inside Thread\n");
    pthread_exit(NULL);
}



int main(int argc , char * argv[])
{
    pthread_t TID1 = 0   ;
    int iret = 0 ;
    int value1 = 0 ;


    iret = pthread_create(&TID1 , NULL , ThreadProc1 , NULL);
    pthread_join( TID1 , NULL);
    printf("end of main Thread\n");
    return 0;
}