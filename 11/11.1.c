#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void * ThreadProc1 ( void *ptr )
{
    printf("Inside ThreadProc \n");
    pthread_exit(NULL);
}
void * ThreadProc2 ( void *ptr )
{
    printf("Inside ThreadProc2 \n");
    pthread_exit(NULL);
    
}
void * ThreadProc3 ( void * ptr)
{
    printf("Inside ThreadProc3 \n");
    pthread_exit(NULL);
}
void * ThreadProc4 ( void * ptr )
{
    printf("Inside ThreadProc4 \n");
    pthread_exit(NULL);
    
}

int main()
{
    pthread_t TID[4] ; 
    int iret = 0 ; 
    int iCnt = 0 ;
    void * ( *fptr[4]) ( void *) = {ThreadProc1 , ThreadProc2 ,  ThreadProc3 , ThreadProc4};

    for ( iCnt = 0 ; iCnt < 4 ; iCnt++)
    {
        pthread_create(&TID[iCnt] , NULL , fptr[iCnt] , NULL);
    }
    iCnt = 0 ;
    while (iCnt < 4)
    {
        pthread_join(TID[iCnt] , NULL);
        iCnt++;
    }

    printf("End Of main Thread\n");
    return  0;
}