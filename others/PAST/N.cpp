#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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
    ll n,w,c; cin >> n >> w >> c;
    map<ll,ll> mp;
    rep(i,n){
        ll l,r,p; cin >> l >> r >> p;
        
        // pq.emplace(min(0LL,l-c), 1);
        // pq.emplace(r, -1);
        mp[max(0LL, l-c+1)] += p;
        mp[r] -= p;
    }

    ll ans = INF;
    ll tmp = mp[0];
    mp[0] = 0;
    for(auto itr = mp.begin(); itr != mp.end(); itr++){
        if(itr->first <= w-c){
            tmp += itr->second;
            chmin(ans, tmp);
            // debug(itr->first);debug(itr->second);
            // debug(tmp);
        }
    }

    cout << ans << endl;
}