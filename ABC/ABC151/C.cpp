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
    ll n,m; cin >> n >> m;
    using ps = pair<ll, string>;
    vector<ps> vec(m);
    rep(i,m){
        ll p; cin >> p;
        p--;
        string s;cin >> s;
        vec[i] = {p,s};
    }
    vector<ll> count(n,0);
    bitset<n_max> bs(0);
    rep(i,m){
        ll p = vec[i].first;
        string s = vec[i].second;
        if(s == "WA"){
            if(bs[p] == 0)count[p]++;
        }
        else{
            bs[p] = 1;
        }
    }
    ll wa = 0;
    rep(i,n)if(bs[i] == 1)wa += count[i];

    cout << bs.count() << " " << wa << endl;
}