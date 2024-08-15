#include <stdio.h>

void itob(int x){
    for(int i=31; i>=0; i--){
        printf("%d", (x>>i) & 1);
    }
    printf("\n");
}