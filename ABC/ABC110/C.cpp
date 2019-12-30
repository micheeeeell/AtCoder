#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    string s;cin >> s;
    string t;cin >> t;
    ll n = s.size();
    vector<vector<ll>> ind_s(26), ind_t(26);
    ll cnt = 0;
    bitset<26> bs(0), bt(0);
    rep(i,n){
        ll temp = s[i] - 'a';
        ind_s[temp].emplace_back(i);
        bs[temp] = 1;
        temp = t[i] - 'a';
        ind_t[temp].emplace_back(i);
    }
    cnt = bs.count();
    bool ok = true;
    rep(i,26){
        bool temp = true;
        ll pre = -1;
        for(auto j : ind_s[i]){
            if(pre == -1)pre = t[j] - 'a';
            if(t[j] - 'a' != pre)temp = false;
        }
        ok &= temp;
    }
    rep(i,26){
        bool temp = true;
        ll pre = -1;
        for(auto j : ind_t[i]){
            if(pre == -1)pre = s[j] - 'a';
            if(s[j] - 'a' != pre)temp = false;
        }
        ok &= temp;
    }
    // rep(i,n)bt[t[i]-'a'] = 1;
    // if(cnt == 26){
    //     ok &= (bt.count() == 26);
    // }
    // else{
    //     ok &= (bt.count() <= cnt);
    // }

    cout << (ok ? "Yes" : "No") << endl;
}