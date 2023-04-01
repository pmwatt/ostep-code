#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char* argv[])
{
    int pid, ppid;

    printf(" starting a new process \n");

    pid = fork();
    if (pid > 0) printf ("process id = %d\n", pid);
    for (int i = 0; i < 2; ++i) {
        pid = fork();
        if (pid > 0) printf ("process id in loop = %d\n", pid);
    }
    wait(NULL);
    printf("42\n");
    return 0;
}