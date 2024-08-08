#include <stdio.h>
#include <assert.h>

// Assert.h is used for unit testing the function that whether they are giving us the expected output
// assert ( condition for expected output )

void swapu(int minidx, int i, int arr[]){
    int temp = arr[minidx];
    arr[minidx] = arr[i];
    arr[i] = temp;
}
void selection_sort(int arr[], int n){
    for(int i=0; i<n; i++){
        int minidx = i;
        for(int j=i+1; j<n; j++){
            if(arr[minidx] > arr[j]){
                minidx = j;
            }
        }
        swapu(minidx, i, arr);
    }
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void test_input(){
    int arr[] = {3,8,5,7,1,9,4};
    int n = sizeof(arr) / sizeof(int);

    int expected_out[] = {1,3,4,5,7,8,9};

    selection_sort(arr, n);

    for(int i=0; i<n; i++){
        assert(arr[i] == expected_out[i]);
    }
}
int main(){
    test_input();
}