#include<bits/stdc++.h>
using namespace std;

// int f(int row, int col, vector<vector<int> >& mat, vector<vector<int> >& dp) {
//     if(col<0 || col>=mat[0].size()) {
//         return INT_MIN;
//     }
//     if(row == 0 || col == 0) {
//         return mat[row][col];
//     }
//     if(dp[row][col] != -1) return dp[row][col];
//     int leftdia = f(row-1, col-1, mat, dp);
//     int rightdia = f(row-1, col+1, mat, dp);
//     int up = f(row-1, col, mat, dp);
//     return dp[row][col] = mat[row][col] + max(up, max(leftdia, rightdia));
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
//     int maxi = INT_MIN;
//     for(int i=0; i<m; ++i) {
//         maxi = max(maxi, f(n-1, i, mat, dp));
//     }
//     cout<<maxi<<endl;
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
    for(int i=0; i<m; ++i) {
        dp[0][i] = mat[0][i];
    }
    for(int i=1; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            int up = mat[i][j] + dp[i-1][j];
            int ld = INT_MIN;
            int rd = INT_MIN;
            if(j-1>=0) ld = mat[i][j] + dp[i-1][j-1];
            if(j+1<m) rd = mat[i][j] + dp[i-1][j+1];
            dp[i][j] = max(up, max(ld, rd));
        }
    }
    int maxi = INT_MIN;
    for(int i=0; i<m; ++i) {
        maxi = max(maxi, dp[n-1][i]);
    }
    cout<<maxi<<endl;
}