#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> sumMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B) {
    int row1 = A.size();
    int col1 = A[0].size();
    int row2 = B.size();
    int col2 = B[0].size();

    if(row1 != row2 || col1 != col2) {
        return {};
    }

    vector<vector<int>> result;

    for(int i=0; i<row1; ++i) {
        vector<int> v;
        for(int j=0; j<col1; j++) {
            v[j] = A[i][j] + B[i][j];
        }
        result.push_back(v);
    }

    return result;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int row, col;
        cin>>row>>col;
        vector<vector<int>> A(row);
        for(int i=0; i<row; ++i) {
            A[i].assign(col, 0);
            for(int j=0; j<col; ++j) {
                cin>>A[i][j];
            }
        }
        cin>>row>>col;
        vector<vector<int>> B(row);
        for(int i=0; i<row; ++i) {
            B[i].assign(col, 0);
            for(int j=0; j<col; ++j) {
                cin>>B[i][j];
            }
        }
        vector<vector<int>> result = sumMatrix(A, B);
        if(result.size() == 0) {
            cout<<"-1";
        } else {
            for(int i=0; i<row; ++i) {
                for(int j=0; j<col; ++j) {
                    cout<<result[i][j]<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}