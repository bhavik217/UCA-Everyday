// Ques Given a signed 32-bit integer x, return x with its digits reversed, if overflowed return 0.
#include <stdio.h>
#include <limits.h>

int reverse(int n){
    if(n == INT_MIN) return 0;

    int flag = (n < 0)? -1 : 1;
    n = flag * n;

    int ans = 0;
    while(n){
        int ld = n % 10;

        if(ans > (INT_MAX - ld) / 10) return 0;

        ans = ans * 10 + ld;
        n /= 10;
    }
    return flag * ans;
}

int main(){
    int n;
    scanf("%d", &n);

    printf("%d\n", reverse(n));
}