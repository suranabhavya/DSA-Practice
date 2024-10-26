#include<bits/stdc++.h>
using namespace std;

// int f(int ind, int k, vector<int>& height, vector<int>& dp) {
//     if(ind == 0) {
//         return 0;
//     }
//     if(dp[ind] != -1) return dp[ind];
//     int minSteps = INT_MAX;
//     for(int i=1; i<=k; ++i) {
//         if(ind-i>=0) {
//             int jump = f(ind-i, k, height, dp) + abs(height[ind] - height[ind-i]);
//             minSteps = min(minSteps, jump);
//         }
//     }
//     return dp[ind] = minSteps;
// }

// int main() {
//     int n;
//     cin>>n;
//     vector<int> height(n);
//     for(int i=0; i<n; ++i) {
//         cin>>height[i];
//     }
//     int k;
//     cin>>k;
//     vector<int> dp(n+1, -1);
//     cout<<f(n-1, k, height, dp)<<endl;
// }

// int main() {
//     int n;
//     cin>>n;
//     vector<int> height(n);
//     for(int i=0; i<n; ++i) {
//         cin>>height[i];
//     }
//     int k;
//     cin>>k;
//     vector<int> dp(n+1, -1);
//     dp[0] = 0;
//     for(int i=1; i<n; ++i) {
//         for(int j=1; j<=k; ++j) {
//             if(i-j>=0) {
//                 dp[i] = min(dp[i], dp[i-j] + abs(height[i] - height[i-j]));
//             }
//         }
//     }
//     cout<<dp[n-1]<<endl;
// }


// int main() {
//     int n;
//     cin>>n;
//     vector<int> height(n);
//     for(int i=0; i<n; ++i) {
//         cin>>height[i];
//     }
//     int k;
//     cin>>k;
//     vector<int> dp(n+1, -1);
//     dp[0] = 0;
//     for(int i=1; i<n; ++i) {
//         int minJump = INT_MAX;
//         for(int j=1; j<=k; ++j) {
//             if(i-j>=0) {
//                 minJump = min(minJump, dp[i-j] + abs(height[i] - height[i-j]));
//             }
//         }
//         dp[i] = minJump;
//     }
//     cout<<dp[n-1]<<endl;
// }



int main() {
    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }
    int k;
    cin >> k;
    
    vector<int> dp(k, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i < n; ++i) {
        int minJump = INT_MAX;
        for (int j = 1; j <= k; ++j) {
            if (i - j >= 0) {
                minJump = min(minJump, dp[(i - j) % k] + abs(height[i] - height[i - j]));
            }
        }
        dp[i % k] = minJump;
    }
    
    cout << dp[(n - 1) % k] << endl;
}