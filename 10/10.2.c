#include <stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * Thread_Proc1 (void *ptr)
{
    for (int iCnt = 500 ; iCnt > 0; iCnt --)
    {
        printf("%d\n", iCnt);
    }
    pthread_exit(NULL);
}

void * Thread_Proc(void *)
{
    for (int iCnt = 0 ; iCnt < 500 ; iCnt ++)
    {
        printf("%d\n" , iCnt);
    }
        pthread_exit(NULL);
}

int main()
{
    pthread_t TID1 ;
    pthread_t TID2 ;
    int ret = 0 ; 

    ret = pthread_create(&TID1  , NULL , Thread_Proc , NULL);
    if ( ret == -1 )
    {
        printf("Unable to create Thread\n");
        return -1;
    } 
    ret = pthread_create(&TID2  , NULL , Thread_Proc1 , NULL);
    if ( ret == -1 )
    {
        printf("Unable to create Thread\n");
        return -1;
    }

    pthread_join(TID1 , NULL);
    pthread_join(TID2 , NULL);
    printf("Ed of main Thraead \n");

    return 0 ; 
}