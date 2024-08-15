#include <stdio.h>
#include "binToInt.h"
#include "intTobin.h"

// Flip n size window in bin no. from the right with p left shifted

// e.g
// 1010010-1010-101
//        |
// 1010010-0101-101


int main(){
    int n = 4;
    int p = 3;

    btoi("10100101010101");

    int x = 10581;
    int ans = x ^ (~(-1 << n) << p);

    itob(ans);
}