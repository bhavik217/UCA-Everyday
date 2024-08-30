#include <stdio.h>

void helper(int n, int src, int dest, int help, int ans){
    if(n == 0) return;

    helper(n - 1, src, help, dest, ans);
    printf("Move disk %d from rod %d to rod %d\n", n, src, dest);
    helper(n - 1, help, dest, src, ans);
}

long long towerOfHanoi(int n, int src, int dest, int help){
    long long ans = 0;
    helper(n, src, help, dest, ans);
    return ans;
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%lld", towerOfHanoi(n, 1, 2, 3));
}