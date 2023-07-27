#include<stdbool.h>

bool CheckPerfect(int No)
{
    int iSum = 0 ; 
    for (int iCnt = 1 ; iCnt <= No / 2 ; iCnt ++)
    {
        if ( No % iCnt == 0 )
        {
            iSum = iSum +  iCnt;
        }
    }
    if ( iSum == No)
    {
        return true;
    }
    else 
    {
        return false;
    }
}