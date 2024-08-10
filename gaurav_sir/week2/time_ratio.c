#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

// Program for checking time ratio when input size doubled

void swapu(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void selection_sort(int *arr, int n){
    for(int i=0; i<n; i++){
        int idx = -1;
        for(int j=i; j<n; j++){
            if(arr[j] < arr[idx]) idx = j;
        }
        swapu(arr, i, idx);
    }
}
long long cal_t(int *arr, int n){
    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    long long millis_before = start_time.tv_sec * 1000LL + start_time.tv_usec / 1000LL;


    selection_sort(arr, n);


    struct timeval end_time;
    gettimeofday(&end_time, NULL);

    long long millis_after = end_time.tv_sec * 1000LL + end_time.tv_usec / 1000LL;

    return millis_after - millis_before;
}
void test_input(){
    srand(time(0));

    int n = 32000;
    int *arr1 = (int *) malloc(sizeof(int) * n);
    for(int i=0; i<n; i++) arr1[i] = rand();

    long long t1 = cal_t(arr1, n);

    int m = 64000;
    int *arr2 = (int *) malloc(sizeof(int) * m);
    for(int i=0; i<m; i++) arr2[i] = rand();

    long long t2 = cal_t(arr2, m);

    free(arr1);
    free(arr2);

    printf("Runtime of 32000 array - %lld\n", t1);
    printf("Runtime of 64000 array - %lld\n", t2);

    printf("Ratio of t1 and t2 %lf", t2*1.0 / t1);
}
int main(){
    test_input(); 
}