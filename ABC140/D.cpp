#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ll n,k; cin >> n >> k;
    string s;cin >> s;

    auto judge = [](string str){
        ll res = 0;ll temp_cnt = 0;
        ll len = str.size();
        rep(i,len){
            if(i == 0)temp_cnt++;
            if(str[i] == str[i-1])temp_cnt++;
            else{
                res += temp_cnt-1;
                temp_cnt = 1;
            }
        }
        res += temp_cnt-1;
        return res;
    };

    // cout << judge(s) << endl;
    ll start = judge(s);
    int type;
    // if(s[0] == s[n-1] && s[0] == 'L')type = 1;
    // else if(s[0] == s[n-1] && s[0] == 'R')type = 2;
    // else type = 0;

    if(s[0] == 'L')type = 1;
    else type = 2;

    string rev;
    if(type <= 1)rev = "LR";
    else rev = "RL";

    bool ok;
    if(s[0] == s[n-1])ok = true;
    else ok = false;

    ll count = 0;
    rep(i,n-1){
        string temp = {s[i],s[i+1]};
        if(temp == rev)count++;
    }

    ll ans = 0;
    if(ok)ans = start + min(count, k)*2;
    else{
        if(k < count)ans = start + k*2;
        else ans = start + count*2 -1;
    }

    cout << ans << endl;
    return 0;
}