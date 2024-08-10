#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <time.h>

int compare(const void* a, const void* b) {
    int int_a = *((int*)a);
    int int_b = *((int*)b);

    if (int_a < int_b) return -1;
    if (int_a > int_b) return 1;
    return 0;
}
void swapu(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void b_sort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swapu(arr, j, j+1);
            }
        }
    }
}
void test_input(){
    srand(time(0));

    int n = 100000;
    int *arr = (int *) malloc(sizeof(int) * n);
    int *expected_out = (int *) malloc(sizeof(int) * n);

    for(int i=0; i<n; i++){
        arr[i] = rand();
        expected_out[i] = arr[i];
    }
    qsort(expected_out, n, sizeof(int), compare);

    // Memory
    struct rusage start_usage;
    getrusage(RUSAGE_SELF, &start_usage);

    // Runtime
    struct timeval before;
    gettimeofday(&before, NULL);

    long long before_millis = before.tv_sec * 1000LL +  before.tv_usec / 1000LL;


    b_sort(arr, n);


    struct timeval after;
    gettimeofday(&after, NULL);

    struct rusage end_usage;
    getrusage(RUSAGE_SELF, &end_usage);


    long long after_millis = after.tv_sec * 1000LL +  after.tv_usec / 1000LL;
    printf("Runtime - %lld \n", after_millis - before_millis);


    long memory_used = end_usage.ru_maxrss - start_usage.ru_maxrss;
    printf("Memory used - %ld KB\n", memory_used);

    for(int i=0; i<n; i++){
        assert(arr[i] == expected_out[i]);
    }

    free(arr);
    free(expected_out);
}
int main(){
    test_input();
}