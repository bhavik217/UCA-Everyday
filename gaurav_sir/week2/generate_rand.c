#include <stdio.h>
#include <stdlib.h>

// If we use rand() then it will not print random no. everytime
// So inorder to print randome no. everytime we use seed

int *randint(int n, int lb, int ub){
    int *arr = (int *) malloc(sizeof(int) * n);
    for(int i=0; i<n; i++){
        arr[i] = rand() % (ub - lb + 1) + lb;
    }
    return arr;
}

int main(){
    srand(time(0)); // Seed the random number generator with the current time

    int *arr = randint(10, 300, 350);

    for(int i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    
    free(arr);
}