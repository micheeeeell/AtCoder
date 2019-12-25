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
    string s;cin >> s;
    ll n = s.size();
    vector<ll> cnt(n,0);
    for(int i = n-1;0 < i;i--){
        if(s[i] == '-')cnt[i-1] = cnt[i]-1;
        else if(s[i] == '+')cnt[i-1] = cnt[i]+1;
        else cnt[i-1] = cnt[i];
    }
    vector<Pll> vec;
    ll M_cnt = 0;
    rep(i,n){
        if(s[i] == 'M')vec.emplace_back(Pll(cnt[i],i));
    }
    sort(all(vec), greater<Pll>());
    bitset<n_max> bs(0);
    rep(i,vec.size()/2){
        bs[vec[i].second] = 1;
    }
    ll ret = 0;
    rep(i,n){
        if(s[i] == 'M'){
            if(bs[i] == 0)ret -= cnt[i];
            else ret += cnt[i];
        }
    }
    cout << ret << endl;
}