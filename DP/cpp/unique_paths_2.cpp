#include<bits/stdc++.h>
using namespace std;

// int f(int n, int m, vector<vector<int> >& mat, vector<vector<int> >& dp) {
//     if(n==0 && m==0) {
//         return 1;
//     }
//     if(n<0 || m<0) {
//         return 0;
//     }
//     if(mat[n][m] == -1) {
//         return 0;
//     }
//     if(dp[n][m] != -1) {
//         return dp[n][m];
//     }
//     int up = f(n-1, m, mat, dp);
//     int left = f(n, m-1, mat, dp);
//     return dp[n][m] = up+left;
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
            if(mat[i][j] == -1) {
                dp[i][j] = 0;
            }
            else if(i==0 && j==0) {
                dp[i][j] = 1;
            }
            else {
                int up=0, left=0;
                if(i>0) {
                    up = dp[i-1][j];
                }
                if(j>0) {
                    left = dp[i][j-1];
                }
                dp[i][j] = up+left;
            }
        }
    }
    cout<<dp[n-1][m-1]<<endl;
}