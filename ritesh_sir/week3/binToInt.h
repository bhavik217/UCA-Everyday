#include <stdio.h>
#include <string.h>

void btoi(char *bin){
    int n = strlen(bin);
    int ans = 0;
    for(int i=0; i<n; i++){
        if(bin[n-i-1] == '1') ans += 1 << i;
    }
    printf("%d\n", ans);
}