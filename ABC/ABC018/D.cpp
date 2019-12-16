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
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;



int main(){
    ll n,m; cin >> n >> m;
    ll p,q,r; cin >> p >> q >> r;
    vector<vector<Pll>> choco(n);
    rep(i,r){
        ll x,y,z; cin >> x >> y >> z;
        x--;y--;
        choco[x].emplace_back(Pll(y,z));
    }
    ll ret = 0;
    rep(i,1LL << n){
        bitset<20> bs(i);
        if(bs.count() != p)continue;
        vector<ll> man(m,0);
        rep(j,n){
            if((i >> j) & 1){
                for(auto k : choco[j])man[k.first] += k.second;
            }
        }
        sort(all(man), greater<ll>());
        ll temp = 0;
        rep(i,q)temp += man[i];
        ret = max(ret, temp);
    }
    cout << ret << endl;
}