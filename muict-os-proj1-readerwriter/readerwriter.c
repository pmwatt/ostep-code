#include <stdio.h>
#include <time.h>
#include <pthread.h>
#define SZ 10
#define RANGE 100

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_t tid;
int ARR[RANGE];

void generate()
{
    // generate random
    srand(time(NULL));
    for (int i = 0; i < SZ; ++i)
    {
        ARR[i] = rand() % RANGE;
    }
}

void *writer(void *num)
{

}

void *reader(void *num)
{

}

int main(int argc, char *argv[])
{
    // verify that correct number of arguments were passed in
    if (argc != 4)
    {
        fprintf(stderr, "USAGE:./readme <WRITER THREAD NO.> <READER THREAD NO.> <OUTPUT.TXT>\n");
        exit(-1);
    }

    // get reader/writer threads count and output file
    int numWriter = atoi(argv[1]);
    int numReader = atoi(argv[2]);

    generate();

    // generate reader threads
    for (int i = 0; i < numReader; ++i)
    {
        // using default thread attributes (NULL)
        pthread_create(&tid, NULL, reader, (void *)numReader);
    }

    // generate writer threads
    for (int i = 0; i < numWriter; ++i)
    {
        // using default thread attributes (NULL)
        pthread_create(&tid, NULL, reader, (void *)numWriter);
    }

    return 0;
}