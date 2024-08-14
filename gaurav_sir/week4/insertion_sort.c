#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>


void insrt_sort(int *arr, int n){
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void test_input(){
    srand(time(0));

    int n = 10000;
    int *arr = (int *) malloc(sizeof(int) * n);

    for(int i=0; i<n; i++) arr[i] = rand();


    // Memory
    struct rusage start_usage;
    getrusage(RUSAGE_SELF, &start_usage);

    // Runtime
    struct timeval before;
    gettimeofday(&before, NULL);

    long long before_millis = before.tv_sec * 1000LL +  before.tv_usec / 1000LL;


    insrt_sort(arr, n);


    struct timeval after;
    gettimeofday(&after, NULL);

    struct rusage end_usage;
    getrusage(RUSAGE_SELF, &end_usage);


    long long after_millis = after.tv_sec * 1000LL +  after.tv_usec / 1000LL;
    printf("Runtime - %lld \n", after_millis - before_millis);


    long memory_used = end_usage.ru_maxrss - start_usage.ru_maxrss;
    printf("Memory used - %ld KB\n", memory_used);

    for(int i = 1; i < n; i++){
        assert((arr[i-1] <= arr[i]) == 1);
    }

    free(arr);
}
int main(){
    test_input();
}