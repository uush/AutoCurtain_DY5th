#include <Arduino.h>
#include "length.h"

int funcLength()
{
    if (extern mode_meas==1)
    {
        if ((extern currentCLK != extern lastCLK)  && extern currentCLK == 0)
        {
            x ++;
        }
        y = (extern count>0)? extern count : (-1)* extern count;
        int length=(x+y)/2;
    }
    return length;
}
