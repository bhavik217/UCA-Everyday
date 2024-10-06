// Write quick sort in C which can sort any data type. caller will pass the array of any data type, size of array and a compare function to compare elements of that data type.

#include <stdio.h>
#include <stdlib.h>

int compFloat(void *a, void *b){
    return *(float*)a <= *(float*)b;
}

int compChar(void *a, void *b){
    return *(char*)a <= *(char*)b;
}

int compInt(void *a, void *b){
    return *(int*)a <= *(int*)b;
}

void swap(void *a, void *b, int size){
    char *p1 = (char*)a;
    char *p2 = (char*)b;

    for(int i = 0; i < size; i++){
        char temp = p1[i];
        p1[i] = p2[i];
        p2[i] = temp;
    }
}

int selectPvt(int size, void *arr, int l, int h, int (*cmp) (void*, void*)){
    void *pvt = (char*)arr + h * size;

    int j = l;
    for(int i = l; i < h; i++){
        if (cmp((char*)arr + i * size, pvt)) {
            swap((char*)arr + i * size, (char*)arr + j * size, size);
            j++;
        }
    }
    swap((char*)arr + j * size, pvt, size);
    return j;
}

void quickSort(int size, void *arr, int l, int h, int (*cmp)(void*, void*)) {
    if (l >= h) return;

    int pvt = selectPvt(size, arr, l, h, cmp);
    quickSort(size, arr, l, pvt - 1, cmp);
    quickSort(size, arr, pvt + 1, h, cmp);
}

void sortIt(int size, int n, void *arr, int (*cmp)(void*, void*)) {
    quickSort(size, arr, 0, n - 1, cmp);
}

int main() {
    char arr[] = {'g', 'a', 'y', 'x', 'm', 'c'};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortIt(sizeof(float), n, arr, compChar);

    for (int i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}