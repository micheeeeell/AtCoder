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
const int n_max = 110;

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    string s;cin >> s;
    ll n = s.size();
    bitset<26> bs(0);
    vector<vector<ll>> vec(26,vector<ll>(1,-1));
    rep(i,n){
        bs[s[i]-'a'] = 1;
        vec[s[i] - 'a'].emplace_back(i);
    }
    ll ans = INF;
    rep(i,26)vec[i].emplace_back(n);
    rep(i,26){
        if(bs[i] == 0)continue;
        ll temp = 0;
        rep(j,vec[i].size()-1){
            chmax(temp, vec[i][j+1] - vec[i][j]);
        }
        chmin(ans,temp);
    }

    cout << ans-1 << endl;
}