#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

int n = 0;
int max_size = 1;
int *arr = NULL;

void resize(int max_size){
    int *temp = (int *) malloc(sizeof(int) * max_size);

    for(int i=0; i<n; i++) temp[i] = arr[i];

    free(arr);
    arr = temp;
}

void push(int x){
    if(arr == NULL) arr = (int *) malloc(sizeof(int) * max_size);

    if(n == max_size){ 
        max_size *= 2;
        resize(max_size);
    }

    arr[n++] = x;
}

int pop(){
    if(n == 0) return INT_MIN;

    int x = arr[--n];

    if(n == max_size / 4){
        max_size /= 2;
        resize(max_size);
    }

    return x;
}

bool isEmpty(){    //O(1)
    return n == 0;
}

int size(){    // O(1)
    return n;
}

void test_stack(){
    push(3);
    push(2);
    push(1);

    assert(isEmpty() == false);
    assert(size() == 3);
    assert(pop() == 1);

    assert(size() == 2);
    assert(pop() == 2);

    assert(size() == 1);
    assert(pop() == 3);

    assert(isEmpty() == true);

}
int main(){
    test_stack();
    printf("All test Passed");
}