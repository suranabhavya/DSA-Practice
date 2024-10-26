#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<int>& arr, vector<int>& dp) {
    if(n == 0) {
        return 0;
    }
    if(dp[n] != -1) return dp[n];
    int left = f(n-1, arr, dp) + abs(arr[n] - arr[n-1]);
    int right = INT_MAX;
    if(n>1) {
        right = f(n-2, arr, dp) + abs(arr[n] - arr[n-2]);
    }
    return min(left, right);
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        cin>>arr[i];
    }
    vector<int> dp(n+1, -1);
    cout<<f(n-1, arr, dp)<<endl;
    return 0;
}