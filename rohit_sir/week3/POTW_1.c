// Build Matrix from rowsum and colsum

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int *rowsum = (int *) malloc(sizeof(int) * n);
    int *colsum = (int *) malloc(sizeof(int) * m);

    for(int i=0; i<n; i++) scanf("%d", &rowsum[i]);
    for(int i=0; i<m; i++) scanf("%d", &colsum[i]);

    int ans[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans[i][j] = (rowsum[i] < colsum[j]) ? rowsum[i] : colsum[j];

            rowsum[i] -= ans[i][j];
            colsum[j] -= ans[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    free(rowsum);
    free(colsum);
}
