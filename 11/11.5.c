#include<pthread.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>


void * ThreadProc1(void * ptr)
{
    printf("Inside Capital\n");
    char Buffer[1024];
    int iRet = 0 ;
    int Count  = 0 ;

    while ( (iRet = read((int *) ptr , Buffer , sizeof(Buffer))) != 0 )
    {
        for (int iCnt = 0 ;iCnt < iRet ; iCnt++)
        {
            if (Buffer[iCnt] >= 'A'  && Buffer[iCnt] <= 'Z')
            {
                Count++;
            }
        }
    }

    pthread_exit(Count);
}

void * ThreadProc2(void * ptr) 
{
    char Buffer[1024];
    int iRet = 0 ;
    int Count  = 0 ;

    while ( (iRet = read((int *) ptr , Buffer , sizeof(Buffer))) != 0 )
    {
    // printf("Inside Small : %d \n" , (int * )ptr);
        for (int iCnt = 0 ;iCnt < iRet ; iCnt++)
        {
            if (Buffer[iCnt] >= 'a'  && Buffer[iCnt] <= 'z')
            {
                Count++;
            }
            // printf("%c", Buffer[iCnt]);
        }
    }

    pthread_exit(Count);
}

int main(int argc , char * argv[])
{
    void * (*fptr[2]) ( void * ) = {ThreadProc1 , ThreadProc2};
    pthread_t TID1 = 0   ;
    pthread_t TID2 = 0   ;
    int iret = 0 ;
    int value1 = 0 ;
    int value2 = 0 ;

    int fd = open (argv[1] , O_RDWR);
    if (fd == -1)
    {
        printf("Unable to open given file \n");
        return -1;
    }

    iret = pthread_create(&TID1 , NULL , fptr[0] , (int * )fd);
    iret = pthread_create(&TID2 , NULL , fptr[1] , (int * )fd);

    pthread_join(TID1, &value1 );
    printf("Count of Capital letters are : %d \n" , value1);
    pthread_join(TID2 , &value2 );
    printf("Count of Small letters are : %d \n" , value2);

    close(fd);
    return 0;
}