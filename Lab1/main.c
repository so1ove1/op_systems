#include <stdio.h>
#include "factorial.h"

int main() {
    int num;
    printf("Enter n: ");
    scanf("%d", &num);
    printf("Factorial %d = %u \n", num, factorial(num));
    return 0;
}
