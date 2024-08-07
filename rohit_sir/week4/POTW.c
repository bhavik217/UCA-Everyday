#include <stdio.h>
#include <stdlib.h>

int peakIndexInMountainArray(int* arr, int n) {
    int l = 1, h = n - 2;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
            return mid;
        }
        if (arr[mid] < arr[mid + 1]) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n; 
    scanf("%d", &n);

    int *arr = (int *) malloc(sizeof(int) * n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int peakIndex = peakIndexInMountainArray(arr, n);
    printf("Peak index is: %d\n", peakIndex);
    free(arr);
}