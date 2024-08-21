#include <stdio.h>

int main(){
    int x = 0;
    int y = 15;
    int z = 6;

    int ans = ((!!x << 31) >> 31 & y) + ((!x << 31) >> 31 & z);
    printf("%d", ans);
}