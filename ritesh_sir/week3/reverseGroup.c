#include <stdio.h>
#include "intTobin.h"
#include "binToInt.h"

// 1101 0101 => 0101 1101

int main(){
    // btoi(11010101);
    int n = 213;

    int a = n & (-1 << 4);
    int b = n & ~(-1 << 4);

    itob(a);
    itob(b);

    int ans = (a >> 4) | (b << 4);

    itob(ans);
}