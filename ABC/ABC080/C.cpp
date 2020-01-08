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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
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

int main(){
    ll n; cin >> n;
    bitset<10> bs[n];
    rep(i,n){
        rep(j,10){
            int t; cin >> t;
            bs[i][j] = t;
        }
        // debug(bs[i]);
    }
    vector<vector<ll>> p(n, vector<ll>(11));
    rep(i,n)rep(j,11)cin >> p[i][j];

    // print(p);

    ll ans = -INF;
    rep(i,(1LL << 10)){
        ll temp = 0;
        if(!i)continue;
        bitset<10> b(i);
        rep(j,n){
            bitset<10> t = b & bs[j];
            temp += p[j][t.count()];
            // debug(t);
        }
        // debug(i);debug(temp);
        // if(temp == 0){debug(i);debug(b);debug(b&bs[1])}
        chmax(ans, temp);
    }
    cout << ans << endl;
}