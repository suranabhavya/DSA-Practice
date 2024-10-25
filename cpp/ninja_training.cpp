#include<bits/stdc++.h>
using namespace std;

// Memoization

// int f(int ind, int last_move, vector<vector<int> >& arr, vector<vector<int> >& dp) {
//     if(ind == 0) {
//         int maxi = INT_MIN;
//         for(int i=0; i<3; ++i) {
//             if(i != last_move) {
//                 maxi = max(maxi, arr[ind][i]);
//             }
//         }
//         return maxi;
//     }
//     if(dp[ind][last_move] != -1) return dp[ind][last_move];
//     int maxi = INT_MIN;
//     for(int i=0; i<3; ++i) {
//         if(i != last_move) {
//             maxi = max(maxi, arr[ind][i] + f(ind-1, i, arr, dp));
//         }
//     }
//     return dp[ind][last_move] = maxi;

// }

// int main() {
//     int n;
//     cin>>n;
//     vector<vector<int> > arr(n, vector<int>(3));
//     for(int i=0; i<n; ++i) {
//         for(int j=0; j<3; ++j) {
//             cin>>arr[i][j];
//         }
//     }
//     vector<vector<int> > dp(n, vector<int>(4, -1));
//     cout<<f(n-1, 3, arr, dp)<<endl;
// }

// Tabulation

int main() {
    int n;
    cin>>n;
    vector<vector<int> > arr(n, vector<int>(3));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<3; ++j) {
            cin>>arr[i][j];
        }
    }
    vector<vector<int> > dp(n, vector<int>(4, -1));
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));

    int maxi = INT_MIN;
    for(int day=1; day<n; ++day) {
        for(int next=0; next<4; ++next) {
            dp[day][next] = INT_MIN;
            for(int task=0; task<3; ++task) {
                if(task != next) {
                    dp[day][next] = max(dp[day][next], arr[day][task] + dp[day-1][task]);
                }
            }
        }
    }
    cout<<dp[n-1][3]<<endl;
}