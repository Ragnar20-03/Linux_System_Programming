// Server for shared memory

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include <sys/shm.h>
  

int main()
{
    int shmid = 0;
    int shmsize = 100;
    int Key = 1234;
    char *ptr = NULL;
    int iRet1 = 0 ; 
    int iRet2 = 0 ; 
    int cpid = 0 ;
    int EXIT_STATUS = 0 ;

    printf("Server application running...\n");

    shmid = shmget(Key,shmsize,IPC_CREAT | 0666);

    printf("Shared memory allocated succesfully...\n");

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL)
    {
        printf("Shared memory atached succesfully...\n");
    }
    
    printf("Data written in shared memory succesfully...\n");

    iRet2 = fork() ; 
    if (iRet2 == 0)
    {
        execl("./shm3" , "NULL" , NULL)
;    }
    else 
    {
        cpid = wait(&EXIT_STATUS);
    }

    iRet1 = fork() ; 
    if (iRet1 == 0)
    {
        execl("./shm2" , "NULL" , NULL);
    }
    else 
    {
        cpid = wait(&EXIT_STATUS);
    }

    
    return 0;
}