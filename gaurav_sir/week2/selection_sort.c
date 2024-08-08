#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>

// Now we will apply all things we have learnt (runtime, memory used, assert, rand) on Selection Sort


int compare(const void* a, const void* b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}
void swapu(int minidx, int i, int arr[]){
    int temp = arr[minidx];
    arr[minidx] = arr[i];
    arr[i] = temp;
}
void selection_sort(int arr[], int n){
    for(int i = 0; i < n; i++){
        int minidx = i;
        for(int j = i+1; j < n; j++){
            if(arr[minidx] > arr[j]){
                minidx = j;
            }
        }
        swapu(minidx, i, arr);
    }
}
void test_input(){
    srand(time(0));
    int n = 100000;

    int *arr = (int *) malloc(sizeof(int) * n);
    int *expected_out = arr;

    for(int i = 0; i < n; i++){
        arr[i] = rand();
        expected_out[i] = arr[i];
    }

    qsort(expected_out, n, sizeof(int), compare);

    // Memory
    struct rusage usage_start;
    getrusage(RUSAGE_SELF, &usage_start);

    // Runtime
    struct timeval before;
    gettimeofday(&before, NULL);

    long long before_millis = before.tv_sec * 1000LL + before.tv_usec / 1000LL;

    selection_sort(arr, n);

    struct timeval after;
    gettimeofday(&after, NULL);

    struct rusage usage_end;
    getrusage(RUSAGE_SELF, &usage_end);

    long long after_millis = after.tv_sec * 1000LL + after.tv_usec / 1000LL;

    printf("Runtime taken - %llu sec\n", (after_millis - before_millis)/1000);

    long memory_used = usage_end.ru_maxrss - usage_start.ru_maxrss;

    printf("Memory used - %ld KB\n", memory_used);

    for(int i=0; i<n; i++){
        assert(arr[i] == expected_out[i]);
    }

    free(arr);
}
int main(){
    test_input();
}