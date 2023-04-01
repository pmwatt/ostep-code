#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char* argv[])
{
    int x = 10;
    printf(" Hello World (pid=%d) \n", (int) getpid());

    int pid = fork();

    if (pid < 0) {
        fprintf(stderr, " fork failed \n");
        exit(1);
    }
    else if (pid == 0) { // create a child process
        x = x + 1;
        printf(" Hello, child process %d has x = %d) \n", getpid(), x);
        fflush(stdout);
        execlp("/bin/ls", "/home", NULL); // run ls
        printf("Child process again = %d\n", x);
        fflush(stdout);
    }
    else {
        wait(NULL);
        printf(" Parent pid = %d has x = %d\n", (int) getpid(), x);
        exit(0);
    }
    return 0;
}