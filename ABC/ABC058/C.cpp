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
const int n_max = 1e5+10;
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
int main(){
    ll n; cin >> n;
    vector<ll> cnt(26,INF);
    rep(i,n){
        string s; cin >> s;
        vector<ll> temp(26,0);
        for(auto j : s){
            temp[j - 'a']++;
        }
        rep(k,26)chmin(cnt[k],temp[k]);
    }
    string ans;
    rep(i,26){
        rep(j,cnt[i])ans += 'a'+i;
    }
    cout << ans << endl;
}