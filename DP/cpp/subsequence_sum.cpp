#include<bits/stdc++.h>
using namespace std;

void subs(int ind, vector<int>& result, int arr[], int n, int sum, int total) {
    if(ind >= n) {
        if(sum == total) {
            for(auto x : result) {
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return;
    }
    result.push_back(arr[ind]);
    sum += arr[ind];
    subs(ind+1, result, arr, n, sum, total);
    sum -= arr[ind];
    result.pop_back();
    subs(ind+1, result, arr, n, sum, total);
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; ++i) {
        cin>>arr[i];
    }
    int total;
    cin>>total;
    vector<int> result;
    int sum = 0;
    subs(0, result, arr, n, sum, total);
}