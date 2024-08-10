#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode *head = NULL;

int n = 0;

void push(int x){    // O(1)
    ListNode *newHead = (ListNode *) malloc(sizeof(ListNode));
    newHead->val = x;

    newHead->next = head;
    head = newHead;
    n++;
}

int pop(){    // O(1)
    if(n == 0) return INT_MIN;

    int x = head->val;

    ListNode *temp = head;
    head = temp->next;
    n--;

    free(temp);
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