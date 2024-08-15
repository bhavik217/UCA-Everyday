#include <stdio.h>
#include "printBits.h"

// Program :-
// Print 1 if n is +ve
// Print -1 if n is -ve
// Print 0 if n is zero

int numType(int n){
    return (n >> 31) | !!n;
}

int main(){
    int n;
    scanf("%d", &n);

    printf("%d", numType(n));
}