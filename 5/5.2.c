#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


struct student
{
    char Name[20];
    int RID;
    int age;
};

int main(int argc , char * argv[])
{
    struct student sobj;

    char Fname[256];
    int fd = 0 ;

    strcpy(sobj.Name , "Roshan X");
    sobj.RID = 255;
    sobj.age = 19;

    fd = creat (argv[1] , 0777);
    write(fd , &sobj , sizeof(sobj));

    write(1, &sobj , sizeof(sobj) );
    return 0;
}