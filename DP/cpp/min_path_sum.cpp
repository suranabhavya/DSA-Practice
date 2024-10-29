#include<bits/stdc++.h>
using namespace std;

// int f(int row, int col, vector<vector<int> >& mat, vector<vector<int> >& dp) {
//     if(row == 0 && col == 0) {
//         return mat[row][col];
//     }
//     if(row < 0 || col < 0) {
//         return INT_MAX;
//     }
//     if(dp[row][col] != -1) return dp[row][col];
//     int up = f(row-1, col, mat, dp);
//     int left = f(row, col-1, mat, dp);
//     return dp[row][col] = mat[row][col] + min(up, left);
// }

// int main() {
//     int n, m;
//     cin>>n>>m;
//     vector<vector<int> > mat(n, vector<int>(m));
//     for(int i=0; i<n; ++i) {
//         for(int j=0; j<m; ++j) {
//             cin>>mat[i][j];
//         }
//     }
//     vector<vector<int> > dp(n, vector<int>(m, -1));
//     cout<<f(n-1, m-1, mat, dp)<<endl;
// }

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int> > mat(n, vector<int>(m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin>>mat[i][j];
        }
    }
    vector<vector<int> > dp(n, vector<int>(m, -1));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(i == 0 && j == 0) {
                dp[i][j] = mat[i][j];
            }
            else {
                int up = INT_MAX, left = INT_MAX;
                if(i>0) {
                    up = dp[i-1][j];
                }
                if(j>0) {
                    left = dp[i][j-1];
                }
                dp[i][j] = mat[i][j] + min(up, left);
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
}