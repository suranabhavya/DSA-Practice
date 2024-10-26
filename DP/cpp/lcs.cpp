#include<bits/stdc++.h>
using namespace std;

int lcs(string str1, string str2, int n, int m) {
    if(n == 0 || m == 0) {
        return 1;
    }
    if(str1[n] == str2[m]) {
        return 1 + lcs(str1, str2, n-1, m-1);
    } else {
        return max(lcs(str1, str2, n-1, m), lcs(str1, str2, n, m-1));
    }
}


int main() {
    string str1;
    string str2;
    cin>>str1;
    cin>>str2;
    cout<<lcs(str1, str2, str1.length()-1, str2.length()-1)<<endl;
}