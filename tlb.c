/*
Remi White
1. The timer is precise to the microsecond. It would need to be at least a few microseconds long before it to be timed precisely because it rounds to the nearest mircrosecond. 
2. 
5.
6.
7.
*/



#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    struct timeval start;
    struct timeval end;

    int PAGESIZE = 10;
    int NUMPAGES = atoi(argv[1]);
    int TRIALS = atoi(argv[2]);
    int jump = PAGESIZE / sizeof(int);
    int *a = calloc(NUMPAGES, PAGESIZE);

    gettimeofday(&start, NULL);
    for(int j = 0; j < TRIALS; j += 1){
        for (int i = 0; i < NUMPAGES * jump; i += jump){
            a[i] += 1;
        }
    }   
    gettimeofday(&end,NULL);
    
    printf("%ld seconds %ld microseconds\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);
   
    return 0;
}



