// Fruits to basket - we can have only 2 types of fruits in basket

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    map<int, int> mp;

    int j=0;
    int ans = 0;
    for(int i=0; i<n; i++){
        mp[arr[i]]++;
        while(mp.size() > 2){
            mp[arr[j]]--;
            if(mp[arr[j]] == 0) mp.erase(arr[j]);
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout<<ans;
}
