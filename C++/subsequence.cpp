#include<bits/stdc++.h>
using namespace std;

void subs(int ind, vector<int>& result, int arr[], int n) {
    if(ind >= n) {
        for(auto x : result) {
            cout<<x<<" ";
        }
        cout<<endl;
        return;
    }
    result.push_back(arr[ind]);
    subs(ind+1, result, arr, n);
    result.pop_back();
    subs(ind+1, result, arr, n);
}


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; ++i) {
        cin>>arr[i];
    }
    vector<int> result;
    subs(0, result, arr, n);
}