#include <stdlib.h>
#include <stdio.h>
#include "rand.h"
int main(int argc, char * argv[])
{
    int count = strtod(argv[1], NULL);
    int low = strtod(argv[2], NULL);
    int high = strtod(argv[3], NULL);
    int seed = strtod(argv[4], NULL);
    srand(seed);
    for(int i = 0; i < count; i++) {
        int r = rand_range(low, high);
        printf("%d\n", r);
    }
}
