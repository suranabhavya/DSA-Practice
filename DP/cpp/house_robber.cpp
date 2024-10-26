#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<int>& arr, vector<int>& dp) {
    if(n==0) return arr[0];
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    int take = arr[n] + f(n-2, arr, dp);
    int not_take = f(n-1, arr, dp);
    return dp[n] = max(take, not_take);
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        cin>>arr[i];
    }
    vector<int> dp(n+1, -1);
    cout<<f(n-1, arr, dp);
}