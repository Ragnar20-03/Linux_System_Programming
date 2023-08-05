#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void * Thread_Proc (void * ptr)
{
    printf(" Thre Value of  Thread is ::  %ld \n" ,  gettid());
    pthread_exit(NULL );
}

int main()
{
    pthread_t TID ; 
    int iRet = 0 ; 
    int i = 899;

    iRet = pthread_create(&TID , NULL , Thread_Proc ,(long int * ) TID);
    if ( iRet == -1)
    {
        printf("Unnable to create Thread\n");
        return -1;
    }
    printf(" Thre TID of  Thread is ::  %ld \n"  , TID);

    pthread_join( TID ,NULL );
    printf("End of Main Thread\n");

    return 0;
}