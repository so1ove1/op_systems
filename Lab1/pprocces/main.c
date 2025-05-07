#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "factorial.h"

int main() {
    HANDLE hRead, hWrite;
    SECURITY_ATTRIBUTES sa = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };

    // создаём pipe
    if (!CreatePipe(&hRead, &hWrite, &sa, 0)) {
        fprintf(stderr, "Cannot create pipe!\n");
        return 1;
    }

    // подготовка для запуска дочернего процесса
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    si.dwFlags = STARTF_USESTDHANDLES;
    si.hStdInput = hRead;
    si.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    si.hStdError = GetStdHandle(STD_ERROR_HANDLE);

    char cmd[] = "child.exe";

    if (!CreateProcess(NULL, cmd, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "Cannot start child process!\n");
        return 1;
    }

    // родитель записывает число
    int n = 6;
    printf("This is parent process!\n");
    DWORD bytesWritten;
    WriteFile(hWrite, &n, sizeof(n), &bytesWritten, NULL);

    printf("Fact of %d is %u.\n", n, factorial(n));

    CloseHandle(hWrite); //закрываем канал после записи
    CloseHandle(hRead);  // родитель не читает

    // ожидаем завершения дочернего процесса
    WaitForSingleObject(pi.hProcess, INFINITE);
    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);
    printf("Child exit value = %lu\n", exitCode);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}