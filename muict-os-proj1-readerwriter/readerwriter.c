#include <stdio.h>
#include <time.h>

int SZ = 10;
int ARR[100];

void generate()
{
    // generate random
    srand(time(NULL));
    for (int i = 0; i < SZ; ++i) {
        ARR[i] = rand() % 500;
    }
}

int main()
{
    generate();
    return 0;
}