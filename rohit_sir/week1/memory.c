// Measure memory taken by program with getrusage
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(){
    // Record the start memory usage
    struct rusage usage_start;
    getrusage(RUSAGE_SELF, &usage_start);

    int *arr = (int*) malloc(100000000 * sizeof(int));

    // Record the end memory usage

    struct rusage usage_end;
    getrusage(RUSAGE_SELF, &usage_end);

    long memory_used = usage_end.ru_maxrss - usage_start.ru_maxrss;   // ru_maxrss measure maximum memory used throughtout program

    printf("Memory used: %ld KB\n", memory_used);

    free(arr);
}

// Note sys/resource.h library works in linux not windows