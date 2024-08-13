#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

struct ListNode{
    int val;
    struct ListNode *next;
};
typedef struct ListNode ListNode;


ListNode *head = NULL;
ListNode *tail = NULL;
int n = 0;

void enqueue(int x){
    if(n == 0){
        head = (ListNode *) malloc(sizeof(ListNode));
        head->val = x;
        head->next = NULL;
        
        tail = head;
        n++;
        return;
    }
    ListNode *newtail = (ListNode *) malloc(sizeof(ListNode));
    newtail->val = x;
    newtail->next = NULL;

    tail->next = newtail;
    tail = newtail;

    n++;
}

int dequeue(){
    if(n == 0) return INT_MIN;

    int x = head->val;

    ListNode *temp = head;
    head = head->next;

    free(temp);
    n--;

    return x;
}

bool isEmpty(){
    return n == 0;
}

int size(){
    return n;
}

void test_input(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);

    assert(size() == 4);
    assert(dequeue() == 1);
    assert(dequeue() == 2);
    assert(dequeue() == 3);
    assert(size() == 1);
    assert(dequeue() == 4);
    assert(isEmpty() == true);
}

int main(){
    test_input();
    printf("All test Passed");
}