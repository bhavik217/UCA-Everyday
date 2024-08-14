#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <assert.h>
#include <time.h>


void merge(int *arr, int *aux, int l, int mid, int h){
    for(int i = l; i <= h; i++) aux[i] = arr[i];

    int i = l;
    int j = mid+1;

    for(int k = l; k <= h; k++){
        if(i > mid) arr[k] = aux[j++];
        else if(j > h) arr[k] = aux[i++];
        else if(aux[i] <= arr[j]) arr[k] = aux[i++];
        else arr[k] = aux[j++];
    }
}
void m_sort(int *arr, int *aux, int l, int h){
    if(l >= h) return;

    int mid = l + (h-l)/2;

    m_sort(arr, aux, l, mid);
    m_sort(arr, aux, mid+1, h);
    merge(arr, aux, l, mid, h);
}
void merge_sort(int *arr, int n){
    int *aux = (int *) malloc(sizeof(int) * n);
    m_sort(arr, aux, 0, n-1);
}
void test_input(){
    srand(time(0));

    int n = 1000000;
    int *arr = (int *) malloc(sizeof(int) * n);

    for(int i=0; i<n; i++) arr[i] = rand();
    
    struct rusage before_usage;
    getrusage(RUSAGE_SELF, &before_usage);

    struct timeval start_time;
    gettimeofday(&start_time, NULL);
    long long before_millis = start_time.tv_sec * 1000LL + start_time.tv_usec / 1000LL;


    merge_sort(arr, n);


    struct timeval end_time;
    gettimeofday(&end_time, NULL);
    long long after_millis = end_time.tv_sec * 1000LL + end_time.tv_usec / 1000LL;

    printf("Runtime - %lld\n", after_millis - before_millis);

    struct rusage after_usage;
    getrusage(RUSAGE_SELF, &after_usage);

    long memory_used = after_usage.ru_maxrss - before_usage.ru_maxrss;
    printf("Memory used - %ld KB\n", memory_used);

    for(int i = 1; i < n; i++){
        assert((arr[i-1] <= arr[i]) == 1);
    }

    free(arr);
}
int main(){
    test_input();
}