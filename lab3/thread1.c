#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int sum;

void* runner (void* param);

int main (int argc, char* argv[])
{
    pthread_t tid;
    pthread_attr_t attr;
    if (argc != 2) {
        fprintf (stderr, " usage: thread1 <integer>\n");
        return -1;
    }
    if (atoi (argv[1]) < 0) {
        fprintf (stderr, " %d must be >= 0 \n", atoi (argv[1]));
        return -1;
    }

    pthread_attr_init(&attr);
    pthread_create(&tid, &attr, runner, argv[1]);
    pthread_join (tid, NULL);
    printf ("sum = %d\n", sum);
    exit (0);
}

void *runner (void* param)
{
    int i, upper = atoi (param);
    sum=0;
    for (i = 1; i <= upper; i++) sum += i; /* compute the summation */
        pthread_exit(0);
}