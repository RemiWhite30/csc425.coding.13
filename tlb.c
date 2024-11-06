/*
Remi White
1. The timer is precise to the microsecond. It would need to be at least a few microseconds long before it to be timed precisely because it rounds to the nearest mircrosecond. 
2. Done
5. You can ensure it does not remove the main loop if you disable optimization when compiling the file with the gcc flag -O0. 
6. You can do it by binding a process to a CPU. If the code is bouncing from CPU to CPU, you do not get the benefits of cache affinity with the TLB.
7. This will affect the timing a little bit. You could counterbalance it by initializing the array to begin with or by keeping track of the time it takes to initialize it and subtract that from the total time.
*/



#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    //initialize the gettimeofday info.
    struct timeval start; 
    struct timeval end;

    int PAGESIZE = 10; //I just chose a random number.
    int NUMPAGES = atoi(argv[1]); //First inputted argument gives number of pages.
    int TRIALS = atoi(argv[2]); //Second inputted argument gives number of trials. 
    int jump = PAGESIZE / sizeof(int);
    int *a = calloc(NUMPAGES, PAGESIZE);

    gettimeofday(&start, NULL);
    for(int j = 0; j < TRIALS; j += 1){
        for (int i = 0; i < NUMPAGES * jump; i += jump){
            a[i] += 1;
        }
    }   
    gettimeofday(&end,NULL);
    
    //Takes the time before the loops and subtracts it from the time after to figure out how long it took.
    printf("%ld seconds %ld microseconds\n", end.tv_sec-start.tv_sec, end.tv_usec-start.tv_usec);
   
    return 0;
}



