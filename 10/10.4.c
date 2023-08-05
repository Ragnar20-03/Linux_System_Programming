#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void * Thread_Proc (void * ptr)
{
    printf(" Thre Value from Main Thread is ::  %d \n" ,(int * ) ptr);
    int c = 56;
    pthread_exit((int *)c );
}

int main()
{
    pthread_t TID ; 
    int iRet = 0 ; 
    int i = 899;
    int x = 0 ;

    iRet = pthread_create(&TID , NULL , Thread_Proc ,(int * ) i);
    if ( iRet == -1)
    {
        printf("Unnable to create Thread\n");
        return -1;
    }

    pthread_join( TID , &x);
    printf("%d is the string from thread \n" , x);
    printf("End of Main ThreadXX\n");

    return 0;
}