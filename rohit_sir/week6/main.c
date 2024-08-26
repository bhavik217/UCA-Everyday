#include <stdio.h>
#include "cal_arith.h"
#include "cal_bit.h"

int main(){
    printf("%d\n", add(4, 2));
    printf("%d\n", sub(4, 2));
    printf("%d\n", mul(4, 2));
    printf("%d\n", div(4, 2));

    printf("%d\n", addBit(4, 2));
    printf("%d\n", subBit(4, 2));
    printf("%d\n", mulBit(4, 2));
    printf("%d\n", divBit(4, 2));
}