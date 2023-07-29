//  Create An New Procees which Writes all file names in a file

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc  , char * argv[])
{

    struct dirent * entry = NULL;
    DIR *dp = NULL;

    printf("....\n");
    dp = opendir("../../");
    if ( dp == NULL)
    {
        printf("Unable to Open DIrectory \n");
        return -1;
    }
    
    int fd = creat("Demo.txt" , 0777);
    if ( fd == -1)
    {
        printf("Unable to Create File\n");
    }

    while ((entry  = readdir(dp)) != NULL  )
    {
        write(fd , entry -> d_name , sizeof(entry -> d_name));
    }

    return 0;
}