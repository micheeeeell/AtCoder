#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
typedef long long ll;
using namespace std;
const ll N = 1e9+7;

int main(){
    string s; cin >> s;
    bool ok = true;
    rep(i,4){
        if(i < 3 &&  s[i] == s[i+1]){
            ok = false;
        }
    }
    int ans = 0;
    if(ok) cout << "Good" << endl;
    else cout << "Bad" << endl;
    // cout << ans << endl;
    return 0;
}