#include<bits/stdc++.h>
using namespace std;

// int f(int row, int col, vector<vector<int> >& dp) {
//     if(row == 0 && col == 0) {
//         return 1;
//     }
//     if(row < 0 || col < 0) {
//         return 0;
//     }
//     if(dp[row][col] != -1) return dp[row][col];
//     int up = f(row-1, col, dp);
//     int left = f(row, col-1, dp);
//     return dp[row][col] = up + left;
// }

// int main() {
//     int n, m;
//     cin>>n>>m;
//     vector<vector<int> > dp(n, vector<int>(m, -1));
//     cout<<f(n-1, m-1, dp)<<endl;
// }

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int> > dp(n, vector<int>(m, -1));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(i==0 && j==0) {
                dp[i][j] = 1;
            }
            else {
                int left = 0, up = 0;
                if(j>0) {
                    left = dp[i][j-1];
                }
                if(i>0) {
                    up = dp[i-1][j];
                }
                dp[i][j] = left + up;
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
}