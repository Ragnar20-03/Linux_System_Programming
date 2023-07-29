//  Create An New Procees which Writes all file names in a file

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>


int main(int argc  , char * argv[])
{
    int fd = 0 ;
    int iRet = 0 ;
    int Small = 0 ;
    char Buffer[4096];
    fd = open("Demo.txt" , O_RDWR);

    while ( (iRet = read (fd , Buffer , sizeof(Buffer))) != 0 )
    {
        for (int iCnt = 0 ; iCnt < iRet ; iCnt++)
        {
            if ( Buffer[iCnt] >= 'A' && Buffer[iCnt] <='Z')
            {
                Small++;
            }
        }
    }
    fd = open("Count.txt" , O_APPEND);
    write(fd , &Small , sizeof(Small));

    return 0;
}