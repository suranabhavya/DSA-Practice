#include<bits/stdc++.h>
using namespace std;

int subs(int ind, vector<int>& result, int arr[], int n, int sum, int total) {
    if(ind >= n) {
        if(sum == total) {
            return 1;
        }
        return 0;
    }
    result.push_back(arr[ind]);
    sum += arr[ind];
    int l = subs(ind+1, result, arr, n, sum, total);
    sum -= arr[ind];
    result.pop_back();
    int r = subs(ind+1, result, arr, n, sum, total);
    return l+r;
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
    cout<<subs(0, result, arr, n, sum, total)<<endl;;
}