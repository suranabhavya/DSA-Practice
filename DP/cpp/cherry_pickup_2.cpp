#include<bits/stdc++.h>
using namespace std;

int f(int row, int a_col, int b_col, int n, int m, vector<vector<int> >& mat, vector<vector<vector<int> > >& dp) {
    if(a_col<0 || a_col>m || b_col<0 || b_col>m) return INT_MIN;
    if(row == n) {
        if(a_col == b_col) return mat[row][a_col];
        else return mat[row][a_col] + mat[row][b_col];
    }
    if(dp[row][a_col][b_col] != -1) return dp[row][a_col][b_col];
    int maxi = INT_MIN;
    for(int dj1=-1; dj1<=1; ++dj1) {
        for(int dj2=-1; dj2<=1; ++dj2) {
            if(a_col == b_col) {
                maxi = max(maxi, mat[row][a_col] + f(row+1, a_col+dj1, b_col+dj2, n, m, mat, dp));
            }
            else {
                maxi = max(maxi, mat[row][a_col] + mat[row][b_col] + f(row+1, a_col+dj1, b_col+dj2, n, m, mat, dp));
            }
        }
    }
    return dp[row][a_col][b_col] = maxi;
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int> >mat(n, vector<int>(m));
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cin>>mat[i][j];
        }
    }
    vector<vector<vector<int> > >dp(n, vector<vector<int> >(m, vector<int>(m, -1)));
    cout<<f(0, 0, m-1, n-1, m-1, mat, dp)<<endl;
}