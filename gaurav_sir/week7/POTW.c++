#include <bits/stdc++.h>
using namespace std;

// Print Maximum and Minimum no. of ones path in a matrix (Just change min and max)

void printPath(vector<vector<int>> arr, int n, int m, int i, int j, int Ones, int &ans){
    if(arr[i][j] == 1) Ones++;

    if(i == n-1 && j == m-1){
        ans = min(ans, Ones);
        return;
    }

    vector<int> row = {1, 0};
    vector<int> col = {0, 1};

    for(int k = 0; k < 2; k++){
        int x = row[k] + i;
        int y = col[k] + j;
        if(x < n && y < m){
            printPath(arr, n, m, x, y, Ones, ans);
        }
    }
}

int func(vector<vector<int>> &arr, int n, int m){
    int ans = INT_MAX;
    printPath(arr, n, m, 0, 0, 0, ans);
    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }

    cout<<func(arr, n, m);
}