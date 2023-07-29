#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/resource.h>
#include<string.h>

extern char **environ;

int main()
{
    char **env = environ;
    char **envX = environ;
    char * temp = NULL;
    printf("Environment of running process is : \n");
    
    for(int iCnt = 0 ;*env != NULL; env++  )
    {
        temp = strtok(*env , "=");
        if (( strcmp(temp , "HOME") ==  0) || ( strcmp(temp , "USER") ==  0))
        {
          temp = strtok(NULL , "=");
          printf(" %s\n" , temp );
        }
    }
    
    return 0;
}
