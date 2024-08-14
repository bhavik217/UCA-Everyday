#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <time.h>


void swapu(int arr[], int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
int partition(int arr[], int l, int r){
	int pivot = arr[r];

	int i = l;

	for(int j = l; j <= r; j++){
		if(arr[j] < pivot){
			swapu(arr, i, j);
			i++;
		}
	}
	swapu(arr, i, r);
	return i;
}
void quick_sort(int arr[], int l, int r){
	if(l >= r) return;

	int mid = partition(arr, l, r);

	quick_sort(arr, l, mid - 1);
	quick_sort(arr, mid + 1, r);
}
long long runtime(int n){
	srand(time(NULL));

	int *arr = malloc(n * sizeof(int));

	for(int i=0; i<n; i++) arr[i] = rand();

	struct timeval before;
	gettimeofday(&before, NULL);

	long long before_millis = before.tv_sec * 1000LL + before.tv_usec / 1000LL;


	quick_sort(arr, 0, n-1);


	struct timeval after;
	gettimeofday(&after, NULL);

	long long after_millis = after.tv_sec * 1000LL + after.tv_usec / 1000LL;


	for(int i = 1; i < n; i++){
		assert((arr[i-1] <= arr[i]) == 1);
	}
	free(arr);

	return after_millis - before_millis;
}
void test_input(){
	long long t1 = runtime(32000);

	long long t2 = runtime(64000);

	printf("Ratio of t2 and t1 %lf\n", t2*1.0 / t1);
}
int main(){
	test_input();
}