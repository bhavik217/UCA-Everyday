// Write a program to return the sum of all even numbers in the Fibonacci series till a given number n. Ex: for n = 100, fib series till 100 is [1,1,2,3,5,8,21,34,55,89]. Return sum of even numbers in it : 2+8+34 = 44

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int sum = 0;
    int a = 1, b = 1;
    while(a < n){
        int c = a + b;
        if(a % 2 == 0) sum += a;
        a = b;
        b = c;
    }
    printf("%d", sum);
}