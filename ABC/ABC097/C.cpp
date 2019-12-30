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
    ll k; cin >> k;
    vector<vector<ll>> table(26);
    set<string> ret;
    ll n = s.size();
    rep(i,s.size()){
        ll t = s[i] - 'a';
        table[t].emplace_back(i);
    }
    ll cnt = 0, ind = 0;
    while(cnt < k){
        for(auto i : table[ind]){
            rep(j,k)ret.insert(s.substr(i,j+1));
        }
        cnt = ret.size();
        ind++;
    }
    // string r;
    auto itr = ret.begin();
    rep(i,k-1)itr++;
    cout << *itr << endl;
}