#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

int main() {
    int value;
    DWORD bytesRead;

    printf("This is child process.\n");

    if (!ReadFile(GetStdHandle(STD_INPUT_HANDLE), &value, sizeof(value), &bytesRead, NULL)) {
        fprintf(stderr, "Child failed to read from pipe.\n");
        return 2;
    }

    printf("Child fact of %d is %u.\n", value, factorial(value));
    return 1;
}