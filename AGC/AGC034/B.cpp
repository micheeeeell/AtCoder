#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(ll i = 0; i < x; i++)
typedef long long ll;
const ll N = 1e9 + 7;
using namespace std;

int main(){
    string s; cin >> s;
    string num;
    bool ok = true;
    // while(ok){
    //     int pos = s.find("BC");
    //     if(pos == string::npos) break;
    //     s.replace(pos,2,"D");
    // }
    ll i = 0;
    // cout << s.size() << " ";
    while(i < s.size()){
        if(s[i] == 'A') num.push_back('A');
        else if(s[i] == 'B' && s[i+1] == 'C') {
            num.push_back('D');
            i++;
        }
        else num.push_back(s[i]);
        i++;
    }
    // rep(i,num.size())
    //     cout << num[i];
    ll ans = 0;
    ll temp = 0;
    rep(i,num.size()){
        if(num[i] == 'A') temp++;
        else if(num[i] == 'D') ans += temp;
        else temp = 0;
        // cout << temp << endl;
    }

    cout << ans << endl;
    return 0;
}