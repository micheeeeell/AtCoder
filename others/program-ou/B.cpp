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
const ll MOD = 998244353;
const int n_max = 1e5+10;


int main(){
    ll n; cin >> n;
    bool ok = true;
    map<ll,ll> mp;
    vector<ll> dv(n);
    ll ma = 0;
    rep(i,n){
        cin >> dv[i];
        mp[dv[i]]++;
        ma = max(ma,dv[i]);
    }
    ll res = 1;
    if(mp[0] != 1 || dv[0] != 0){
        ok =false;
        // cout << 0 << endl;
        // return 0;
    }
    ll pre;
    rep(i,ma+1){
        if(mp[i] == 0){
            ok = false;
            break;
        }
        if(i == 0){
            pre = mp[i];
            continue;
        }
        ll now = mp[i];
        // res = (res * ll(pow(pre, now))) % MOD;
        rep(j,now){
            res = (res * pre) % MOD;
        }
        pre = now;
    }
    cout << (ok ? res : 0) << endl;
}