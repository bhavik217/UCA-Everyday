#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode *head = NULL;
ListNode *tail = NULL;
int n = 0;

void insertAtHead(int x){
    ListNode *newhead = (ListNode *) malloc(sizeof(ListNode));
    newhead->val = x;
    
    newhead->next = head;
    head = newhead;

    if(n == 0) tail = head;
    n++;
}

void insertAtTail(int x){
    ListNode *newTail = (ListNode *) malloc(sizeof(ListNode));
    newTail->val = x;
    newTail->next = NULL;

    tail->next = newTail;
    tail = newTail;
    n++;
}

int delete(int x){
    if(n == 0) return -1;

    if(head->val == x){
        ListNode *temp = head;
        head = head->next;
        free(temp);
        n--;
        return 1;
    }

    ListNode *node = head;

    while(node->next){
        if(node->next->val == x){
            ListNode *temp = node->next;

            node->next = node->next->next;

            free(temp);
            n--;
            return 1;
        }
        node = node->next;
    }
    return -1;
    printf("Node not found!\n");
}

void printList(){
    ListNode *node = head;
    while(node){
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

int size(){
    return n;
}

void test_input(){
    insertAtHead(1);
    insertAtTail(2);
    insertAtHead(3);

    printList();
    assert(size() == 3);

    assert(delete(101) == -1);
    assert(delete(1) == 1);
    assert(delete(2) == 1);
    assert(delete(3) == 1);
    assert(delete(4) == -1);

    assert(size() == 0);
}

int main(){
    test_input();
    printf("All testcases passed\n");
}