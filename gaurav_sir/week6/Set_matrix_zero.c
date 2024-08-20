#include <stdio.h>
#include <stdlib.h>


void unset_row(int m, int **arr, int row){
    for(int i = 0; i < m; i++){
        arr[row][i] = 0;
    }
}
void unset_col(int n, int **arr, int col){
    for(int i = 0; i < n; i++){
        arr[i][col] = 0;
    }
}
void set_mat_zero(int n, int m, int **arr){
    int row = 0, col = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                row = row | (1 << i);
                col = col | (1 << j);
            }
        }
    }
    for(int i=0; i < n; i++){
        if((row >> i) & 1){
            unset_row(m, arr, i);
        }
    }
    for(int i=0; i < m; i++){
        if((col >> i) & 1){
            unset_col(n, arr, i);
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int **arr = (int **) malloc(n * sizeof(int *));
    for(int i=0; i<n; i++){
        arr[i] = (int *) malloc(m * sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    set_mat_zero(n, m, arr);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++) free(arr[i]);
    free(arr);
}