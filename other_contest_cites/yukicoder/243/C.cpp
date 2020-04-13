#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
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
#define int ll

// xを素因数分解する関数
// 連想配列で＜素因数，べき乗＞が帰る
// template<class T>
map<ll,int> prime(ll x){
    map<ll,int> e;
    rep(i,sqrt(x)+1){
        if(i <= 1)continue;
        while(x % i == 0){
            e[i]++;
            x /= i;
        }
    }
    if(x != 1)e[x]++;
    return e;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll t; cin >> t;
    rep(i,t){
        ll ans = 0;
        ans += n * n;
        ans += n * (n-1);
        for(int i = 2)
    }
}