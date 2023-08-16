// Client 2
// Client for shared memory

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

    printf("Client application running...\n");

    shmid = shmget(Key,shmsize, 0666);

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL)
    {
        printf("Shared memory atached succesfully...\n");
    }
        
    *ptr = 'H';
    ptr++;

    *ptr = 'e';
    ptr++;
    
    *ptr = 'l';
    ptr++;
    
    *ptr = 'l';
    ptr++;
    
    *ptr = 'o';
    ptr++;
    
    *ptr = '\0';
    ptr++;
    
    printf("Data written in shared memory succesfully...\n");



    
    return 0;
}