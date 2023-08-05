// Thread
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void * ThreadProc ( void * ptr)
{
    printf("Inside Thread \n");

    pthread_exit(NULL);
}


int main()
{
    pthread_t TID;
    int ret = 0 ; 

    printf("inside main \n");
    ret = pthread_create(&TID , NULL , ThreadProc , NULL);
    if ( ret == -1)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join( TID ,  NULL);
    printf("End of main thread\n");

    return 0; 
}