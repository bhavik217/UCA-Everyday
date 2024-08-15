#include <stdio.h>
#include "printBits.h"

int main(){
    int n;
    scanf("%d", &n);
    printBits(n);

    // Approach-1 = There always only one set bit in power of 2
    // printBits(n-1);
    // printf("^\n");
    // printBits(n & n-1);

    // if((n & n-1) == 0) printf("\nYes power of 2\n");
    // else printf("\nNot power of 2\n");


    // Approach-2 = 2's complement of power of 2 will be same as number
    // 1000 - 8
    // 1000 - 2's ~ of 8
    if((n & -n) == n) printf("\nYes power of 2\n");
    else printf("\nNot power of 2\n");
}