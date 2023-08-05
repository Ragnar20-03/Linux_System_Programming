#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void * Thread_Proc (void * ptr)
{
    printf(" Thre Value from Main Thread is ::  %d \n" ,(int * ) ptr);
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID ; 
    int iRet = 0 ; 
    int i = 899;


    iRet = pthread_create(&TID , NULL , Thread_Proc ,(int * ) i);
    if ( iRet == -1)
    {
        printf("Unnable to create Thread\n");
        return -1;
    }

    pthread_join( TID , NULL);
    printf("End of Main ThreadXX\n");

    return 0;
}