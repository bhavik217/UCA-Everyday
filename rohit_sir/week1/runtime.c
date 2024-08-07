// How to compute actual runtime of a program

#include <stdio.h>
#include <time.h>    // Library for runtime
#include <stdlib.h> // Dynamic memory allocation


void merge(int *arr, int s, int mid, int e){
    int c = 0;
    int *temp = (int*) malloc(sizeof(int) * (e-s + 1));

    int i = s, j = mid+1;

    while(i <= mid && j <= e){
        if(arr[i] > arr[j]) temp[c++] = arr[j++];
        else temp[c++] = arr[i++];
    }

    while(i <= mid) temp[c++] = arr[i++];

    while(j <= e) temp[c++] = arr[j++];

    for(int i = s; i <= e; i++){
        arr[i] = temp[i-s];
    }
    free(temp);
}

void mergesort(int *arr, int s, int e){
    if(s >= e) return;

    int mid = s + (e-s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid+1, e);
    merge(arr, s, mid, e);
}

void algo(){
    int n;
    scanf("%d", &n);

    int *arr = (int*) malloc(sizeof(int) * n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    mergesort(arr, 0, n-1);

    free(arr);
}

int main(){
    // Record the start time
    clock_t start_time = clock(); // clock func returns no. of CLOCK TICKS used by program

    algo();

    // Record the end time
    clock_t end_time = clock();

    // Calculate the CPU time used in seconds
    double cpu_time_used = ((double) (end_time - start_time)) /CLOCKS_PER_SEC; // it convert clock ticks to seconds
    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}

//NOTE that CPU clock_t approach might include extra time due to mutitasking to avoid this we use gettimeofday()




