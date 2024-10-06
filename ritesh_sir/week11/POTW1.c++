// Given an random array find smallest K elements :
// Input : [3,2,6,7,2,1,9]
// k = 3
// Output : [1,2,2] in any order

#include <bits/stdc++.h>
using namespace std;

vector<int> getKSmallest(int n, int k, vector<int> &arr){
    priority_queue<int, vector<int>, greater<>> pq;

    for(int i = 0; i < n; i++) pq.push(arr[i]);

    vector<int> ans;
    for(int i = 0; i < k; i++){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main(){
    int n, k;
    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];

    cin>>k;

    vector<int> ans = getKSmallest(n, k, arr);

    for(int i = 0; i < k; i++) cout<<ans[i]<<" ";
}