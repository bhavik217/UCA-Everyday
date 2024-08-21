#include <stdio.h>

int main(){
    int n = 27;

    int ans = ((n | -n) >> 31) + 1;
    printf("%d", ans);
}