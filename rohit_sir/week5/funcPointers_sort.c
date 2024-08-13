#include <stdio.h>

int comp_asc(int a, int b){
    return a > b;
}
int comp_desc(int a, int b){
    return a < b;
}

void sortIt(int arr[], int n, int (* comp) (int, int)){
    // Bubble Sort
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            // Use of comparison operator
            if(comp(arr[j], arr[j + 1])){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n = 5;
    int arr[5] = {3, 5, 1, 8, 6};
    sortIt(arr, n, comp_asc);
    sortIt(arr, n, comp_desc);
}