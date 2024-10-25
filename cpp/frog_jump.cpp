#include<bits/stdc++.h>
using namespace std;

int f(int n, vector<int>& height, vector<int>& dp) {
    if(n == 1) {
        return 0;
    }
    if(n == 2) {
        return abs(height[1] - height[0]);
    }
    if(dp[n] != -1) return dp[n];
    return dp[n] = min(abs(height[n-1] - height[n-3]) + f(n-2, height, dp), abs(height[n-1] - height[n-2]) + f(n-1, height, dp));
}

int main() {
    int n;
    cin>>n;
    vector<int> height(n);
    for(int i=0; i<n; ++i) {
        cin>>height[i];
    }
    vector<int> dp(n+1, -1);
    cout<<f(n, height, dp)<<endl;
}

// int main() {
//     int n;
//     cin>>n;
//     vector<int> height(n);
//     for(int i=0; i<n; ++i) {
//         cin>>height[i];
//     }
//     int prev2 = 0;
//     int prev1 = abs(height[1] - height[0]);
//     for(int i=2; i<n; ++i) {
//         int temp = min(prev2 + abs(height[2] - height[1]), prev1 + abs(height[2] - height[0]));
//         prev2 = prev1;
//         prev1 = temp;
//     }
//     cout<<prev1<<endl;
// }