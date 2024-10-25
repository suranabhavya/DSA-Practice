#include<bits/stdc++.h>
using namespace std;

// int f(int n, vector<int>& arr, vector<int>& dp) {
//     if(n == 0) return arr[0];
//     if(n < 0) return 0;
//     if(dp[n] != -1) return dp[n];
//     int pick = arr[n] + f(n-2, arr, dp);
//     int not_pick = f(n-1, arr, dp);
//     return dp[n] = max(pick, not_pick);
// }

// int main() {
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0; i<n; ++i) {
//         cin>>arr[i];
//     }
//     vector<int> dp(n+1, -1);
//     cout<<f(n-1, arr, dp)<<endl;
// }

// int main() {
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0; i<n; ++i) {
//         cin>>arr[i];
//     }
//     vector<int> dp(n+1, -1);
//     dp[0] = arr[0];
//     for(int i=1; i<n; ++i) {
//         int pick = arr[i];
//         if(i>1) {
//            pick += dp[i-2];
//         }
//         int not_pick = dp[i-1];
//         dp[i] = max(pick, not_pick);
//     }
//     return dp[n-1];
// }


int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        cin>>arr[i];
    }
    
    int prev = arr[0];
    int prev2 = 0;
    for(int i=1; i<n; ++i) {
        int pick = arr[i];
        if(i>1) {
           pick += prev2;
        }
        int not_pick = prev;
        int curri = max(pick, not_pick);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}