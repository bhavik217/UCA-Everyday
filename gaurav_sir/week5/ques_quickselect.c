#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Kth largest element in an array using QuickSelect

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
int select_pvt(int *arr, int l, int h){
    int lar = l;
    int pvt = h;
    for(int i = l; i < h; i++){
        if(arr[i] < arr[pvt]) swap(&arr[i], &arr[lar++]);
    }
    swap(&arr[pvt], &arr[lar]);
    return lar;
}
bool quickselect(int *arr, int n, int k, int l, int h, int *ans){
    if(l >= h) return false;

    int pvt = select_pvt(arr, l, h);

    if(n - k == pvt){
        *ans = arr[pvt];
        return true;
    }
    else if(pvt > n - k && quickselect(arr, n, k, l, pvt - 1, ans)) return true;
    else if(pvt < n - k && quickselect(arr, n, k, pvt + 1, h, ans)) return true;

    return false;
}
int findKthLargest(int *arr, int n, int k) {
    int ans = arr[0];
    quickselect(arr, n, k, 0, n-1, &ans);

    return ans;
}

int main(){
    int n;
    scanf("%d", &n);

    int *arr = (int*) malloc(n * sizeof(int));
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    int k;
    scanf("%d", &k);

    int ans = findKthLargest(arr, n, k);
    printf("%d", ans);

    free(arr);
}