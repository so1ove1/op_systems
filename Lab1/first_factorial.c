#include <stdio.h>

unsigned long long factorial(int n) {
    if (n < 0) return 0; 
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

int main() {
    int num;
    printf("Введите число: ");
    scanf("%d", &num);
    printf("Факториал числа %d = %llu\n", num, factorial(num));
    return 0;
}
