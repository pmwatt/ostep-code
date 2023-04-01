#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char* argv[])
{
    printf(" Hello World (pid=%d) \n", (int) getpid());

    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, " fork failed \n");
        exit(1);
    }
    else if (rc == 0) { // create a child process
        printf(" Hello, I am a child process (pid=%d) \n", (int) getpid());
        char *myargs[3];
        myargs[0] = strdup("wc"); // program wc = word count
        myargs[1] = strdup("fork1.c"); // input file to count
        myargs[2] = NULL;
        execvp(myargs[0], myargs); // run wc
        printf("This message is not printed out");
    }
    else {
        int rc_wait = wait(NULL);
        printf(" Hello, I am a parent of %d with rc_wait = %d for pid %d\n", rc, rc_wait, (int) getpid());
    }
    return 0;
}