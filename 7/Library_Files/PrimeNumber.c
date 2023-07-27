#include<stdbool.h>

// 7.3.c

bool CheckPrime(int No)
{
    bool bFlag = true ;
    int i = 0 ;
    for (i  = 2 ; i< No / 2 ; i++ )
    {
        if ((No % i ) == 0 )
        {
            break;
        }
    }
    if ( i >= No/2)
    {
        bFlag = true;
        return bFlag;
    }
    else 
    {
        bFlag = false;
        return bFlag;
    }
}