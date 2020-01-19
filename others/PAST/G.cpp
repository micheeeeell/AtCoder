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

void print(Pll &p){
    print(p.first, p.second);
}

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n; cin >> n;
    vector<vector<ll> > a(n,vector<ll>(n,0));
    rep(i,n-1){
        for(int j = i+1; j < n; j++){
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }
    // print(a);
    auto num23 = [&](ll x) -> vector<ll>{
        vector<ll> ret(n,0);
        ll cnt = 0;
        while(0 < x){
            ret[cnt] = x%3;
            x /= 3;
            cnt++;
        }
        return ret;
    };
    // vl vec = num23(10);
    // print(vec);
    auto score = [&](vector<ll> v){
        ll ret = 0;
        ll n = v.size();
        rep(i,n)rep(j,n){
            if(i <= j)continue;
            ret += a[v[i]][v[j]];
        }
        return ret;
    };
    ll ans = numeric_limits<ll>::min();
    rep(i,pow(3,n)){
        vector<ll> t = num23(i);
        ll temp = 0;
        rep(i,3){
            vector<ll> g;
            rep(j,n)if(t[j] == i)g.emplace_back(j);
            temp += score(g);
        }
        chmax(ans,temp);
    }
    cout << ans << endl;
}