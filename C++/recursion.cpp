#include<bits/stdc++.h>

using namespace std;

// int factorial(int n) {
//     if(n == 1 || n == 0) {
//         return 1;
//     }
//     return n * factorial(n-1);
// }


void reverse(int numbers[], int i, int n) {
    if(i >= n/2) {
        return;
    }
    swap(numbers[i], numbers[n-i-1]);
    reverse(numbers, i+1, n);
}


int main() {
    int n;
    cin>>n;
    int numbers[n];
    for(int i=0; i<n; ++i) {
        cin>>numbers[i];
    }
    reverse(numbers, 0, n);
    for(int i=0; i<n; ++i) {
        cout<<numbers[i]<<" ";
    }
    // cout<<factorial(n)<<endl;
}