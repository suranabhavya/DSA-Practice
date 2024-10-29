#include<bits/stdc++.h>
using namespace std;

// int f(int row, int col, int n, vector<vector<int> >& triangle, vector<vector<int> >& dp) {
//     if(row == n) {
//         return triangle[row][col];
//     }
//     if(dp[row][col] != -1) return dp[row][col];
//     int down = f(row+1, col, n, triangle, dp);
//     int diag = f(row+1, col+1, n, triangle, dp);
//     return dp[row][col] = triangle[row][col] + min(down, diag);
// }

// int main() {
//     int n;
//     cin>>n;
//     vector<vector<int> > triangle(n, vector<int>(n));
//     for(int i=0; i<n; ++i) {
//         for(int j=0; j<=i; ++j) {
//             cin>>triangle[i][j];
//         }
//     }
//     vector<vector<int> > dp(n, vector<int>(n, -1));
//     cout<<f(0, 0, n-1, triangle, dp)<<endl;
// }

int main() {
    int n;
    cin>>n;
    vector<vector<int> > triangle(n, vector<int>(n));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<=i; ++j) {
            cin>>triangle[i][j];
        }
    }
    vector<vector<int> > dp(n, vector<int>(n, -1));
    for(int i=0; i<n; ++i) {
        dp[n-1][i] = triangle[n-1][i];
    }
    for(int i=n-2; i>=0; --i) {
        for(int j=i; j>=0; --j) {
            int down = dp[i+1][j];
            int diag = dp[i+1][j+1];
            dp[i][j] = triangle[i][j] + min(down, diag);
        }
    }
    cout<<dp[0][0]<<endl;
}