#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

unsigned int factorial(int n) {
    if (n < 0) return 0;
    unsigned int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}
