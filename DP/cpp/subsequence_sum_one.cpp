#include<bits/stdc++.h>
using namespace std;

bool subs(int ind, vector<int>& result, int arr[], int n, int sum, int total) {
    if(ind >= n) {
        if(sum == total) {
            for(auto x : result) {
                cout<<x<<" ";
            }
            cout<<endl;
            return true;
        } else {
            return false;
        }
    }
    result.push_back(arr[ind]);
    sum += arr[ind];
    if(subs(ind+1, result, arr, n, sum, total)) {
        return true;
    }
    sum -= arr[ind];
    result.pop_back();
    if(subs(ind+1, result, arr, n, sum, total)) {
        return true;
    }
    return false;
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