#include <stdlib.h>
#include <stdio.h>
#include "rand.h"
int rand_range(int low, int high)
{
    return (int) ((rand() / (RAND_MAX + 1.0)) * abs(high - low)) + low;
}