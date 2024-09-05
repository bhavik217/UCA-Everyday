#include <stdio.h>
#include <stdlib.h>

typedef struct priority_queue{
    int arr[100];
    int size;
} pq;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int comp_maxHeap(int a, int b){
    return a < b;
}

int comp_minHeap(int a, int b){
    return a > b;
}

int comp_eq_maxHeap(int a, int b){
    return a >= b;
}

int comp_eq_minHeap(int a, int b){
    return a <= b;
}

void insert(pq *pq, int val, int (* comp) (int, int)){
    int idx = ++pq->size;
    pq->arr[idx] = val;

    while(idx > 1){
        int par = idx / 2;

        if(comp(pq->arr[par], pq->arr[idx])){
            swap(&pq->arr[par], &pq->arr[idx]);
            idx = par;
        }
        else return;
    }
}   

int delMax(pq *pq, int (* comp) (int, int), int (* comp_eq) (int, int)){
    if(pq->size == 0) return -1;

    int top = pq->arr[1];
    pq->arr[1] = pq->arr[pq->size];
    pq->size--;

    // Logic to balance heap
    int n = pq->size, par = 1;

    while(2 * par <= n){
        int ch = 2 * par;
        if(ch < n && comp(pq->arr[ch], pq->arr[ch + 1])){
            ch++;
        }
        if(comp_eq(pq->arr[par], pq->arr[ch])) break;

        swap(&pq->arr[par], &pq->arr[ch]);
        par = ch;
    }
    return top;
}

void print(pq *pq){
    int n = pq->size;
    for(int i = 1; i <= n; i++){
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

int main(){
    pq maxH;
    maxH.size = 0;

    // MaxHeap
    insert(&maxH, 10, comp_maxHeap);
    insert(&maxH, 20, comp_maxHeap);
    insert(&maxH, 30, comp_maxHeap);
    insert(&maxH, 40, comp_maxHeap);
    insert(&maxH, 50, comp_maxHeap);
    print(&maxH);

    printf("%d \n", delMax(&maxH, comp_maxHeap, comp_eq_maxHeap));
    printf("%d \n", delMax(&maxH, comp_maxHeap, comp_eq_maxHeap));
    printf("%d \n", delMax(&maxH, comp_maxHeap, comp_eq_maxHeap));
    print(&maxH);


    // MinHeap
    pq minH;
    minH.size = 0;
    insert(&minH, 10, comp_minHeap);
    insert(&minH, 20, comp_minHeap);
    insert(&minH, 30, comp_minHeap);
    insert(&minH, 40, comp_minHeap);
    insert(&minH, 50, comp_minHeap);
    print(&minH);

    printf("%d \n", delMax(&minH, comp_minHeap, comp_eq_minHeap));
    printf("%d \n", delMax(&minH, comp_minHeap, comp_eq_minHeap));
    printf("%d \n", delMax(&minH, comp_minHeap, comp_eq_minHeap));
    print(&minH);
}