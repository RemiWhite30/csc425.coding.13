#include <stdio.h>

int PAGESIZE;
int NUMPAGES;

int jump = PAGESIZE / sizeof(int);
for (i = 0; i < NUMPAGES * jump; i += jump){
    a[i] += 1;
}
    

