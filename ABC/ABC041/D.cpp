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
#define mp make_pair
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
void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}

ll dfs(vvl &to, vl &dp, vl &out, ll now, ll n){
    ll res = 0;
    if(now == 0)return 1;
    if(dp[now] != 0)return dp[now];
    vector<ll> next;
    rep(i,n){
        if(out[i] == 0 && ((1LL << i) & now))next.emplace_back(i);
    }
    // for(auto i : next){
    //     for(auto j : to[i])out[j]--;
    // }
    // print(next);
    for(auto i : next){
        for(auto j : to[i])out[j]--;
        res += dfs(to, dp, out, (now^(1LL<<i)), n);
        for(auto j : to[i])out[j]++;
    }
    dp[now] = res;
    // print(now, res);
    return res;
}

int main(){
    ll n,m; cin >> n >> m;
    vector<vector<ll>> from(n), to(n);
    vector<ll> in(n,0), out(n,0);
    rep(i,m){
        ll x,y; cin >> x >> y;
        x--;y--;
        from[x].emplace_back(y);
        to[y].emplace_back(x);
        in[y]++;
        out[x]++;
    }
    // const int l = n;
    vector<ll> dp((1LL << n), 0);

    cout << dfs(to, dp, out, (1LL << n)-1, n) << endl;
}