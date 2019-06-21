#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;
string ans = "Yay! :(";

int main(){
    int n,k; cin >> n >> k;
    if(k == 1) {
        cout << 0 << endl;
        return 0;
    }
    else{
        cout << n - k << endl;
        return 0;
    }
}