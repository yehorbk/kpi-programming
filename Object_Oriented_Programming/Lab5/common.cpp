#include <cmath>
#include "common.h"
#include <stdio.h>

char* Common::toString(int num)
{
    int digits = log10(num) + 1;
    char result[4];
    //_itoa_s(num, result, 10);
    sprintf_s(result, "%d", num);
    return result;
}
