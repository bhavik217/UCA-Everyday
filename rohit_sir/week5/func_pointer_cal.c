#include <stdio.h>

int add(int a, int b){
    return a + b;
}
int sub(int a, int b){
    return a - b;
}
int mul(int a, int b){
    return a * b;
}
int div(int a, int b){
    return a / b;
}

void performAction(int (* func) (int, int), int a, int b){
    printf("%d\n", func(a, b));
}

int main(){
    performAction(add, 10, 2);
    performAction(sub, 10, 2);
    performAction(add, 10, 2);
    performAction(add, 10, 2);
}