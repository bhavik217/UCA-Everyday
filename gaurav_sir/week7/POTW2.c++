#include <bits/stdc++.h>
using namespace std;

// Print maximum no, of cherry you can get on a path

// x - Blocked
// o - Open
// c - cherry

// Input -
// o c o
// x o x
// o c o

// Output -
// 2
// via below path
// o c
//   o
//   c o


void func(vector<vector<char>> &arr, vector<vector<int>> &vis, int n, int m, int i, int j, int cherry, int &ans){
    if(arr[i][j] == 'c') cherry++;
    if(i == n-1 && j == m-1){ 
        ans = max(ans, cherry);
        return;
    }

    vector<int> row = {-1, 0, 1, 0};
    vector<int> col = {0, 1, 0, -1};

    for(int k = 0; k < 4; k++){
        int x = row[k] + i;
        int y = col[k] + j;
        if(x < n && y < m && x >= 0 && y >= 0 && !vis[x][y] && arr[x][y] != 'x'){
            vis[x][y] = 1;

            func(arr, vis, n, m, x, y, cherry, ans);

            vis[x][y] = 0;
        }
    }
}

int find_max(vector<vector<char>> &arr, int n, int m){

    int ans = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    func(arr, vis, n, m, 0, 0, 0, ans);

    return ans;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<char>> arr(n, vector<char>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }
    printf("%d", find_max(arr, n, m));
}