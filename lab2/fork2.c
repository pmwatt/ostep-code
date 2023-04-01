#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main (int argc, char* argv[])
{
    int pid, ppid;
    int x;

    x = getpid();
    printf(" PID of this process is %d\n", x);

    x = 10;
    printf(" create a process \n");
    pid = fork();

    if (pid > 0)
    {
        printf(" I am a parent process with PID = %d of child process %d\n", getpid(), pid);
        x = x+2;
        printf(" parent process has x = %d\n", x);
        exit(0);
    }
    else
    {
        printf(" I am a child process with PID = %d\n", getpid());
        printf(" My parent process with PID = %d\n", getppid());
        printf(" child process has x = %d\n", x);
        exit(0);
    }
}