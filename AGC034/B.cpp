#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
typedef long long ll;
const ll N = 1e9 + 7;
using namespace std;

int main(){
    string s; cin >> s;
    vector<int> num;
    bool ok = true;
    // while(ok){
    //     int pos = s.find("BC");
    //     if(pos == string::npos) break;
    //     s.replace(pos,2,"D");
    // }
    int i = 0;
    while(i < s.size()){
        if(s[i] == 'A') num.push_back(0);
        else if(s[i] == 'B' && s[i+1] == 'C') {
            num.push_back(1);
            i++;
        }
        else num.push_back(2);
        i++;
    }
    // rep(i,num.size())
    //     cout << num[i];
    int ans = 0;
    int temp = 0;
    rep(i,num.size()){
        if(num[i] == 0) temp++;
        else if(num[i] == 1) ans += temp;
        else temp = 0;
        // cout << temp << endl;
    }

    cout << ans << endl;
    return 0;
}