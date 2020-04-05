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
#define int ll

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

template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    ll n,m; cin >> n >> m;
    vector<ll> x(n);
    rep(i,n) cin >> x[i];
    vector<ll> cnt(n_max), mod(m), mod_odd(m);
    rep(i,n){
        cnt[x[i]]++;
        mod[x[i] % m]++;
    }
    rep(i,n_max){
        if(cnt[i] & 1)mod_odd[i % m]++;
    }
    
    // print(mod);
    // print(mod_odd);

    ll ans = 0;
    rep(i,m){
        if(i > m-i)continue;
        
        if(i == m-i || i == 0){
            ans += (mod[i]) / 2;
            // debug(i);debug(ans);
            continue;
        }
        ll t = max(mod_odd[i], mod_odd[m-i]);
        chmin(t, mod[i]);chmin(t, mod[m-i]);
        ans += t;
        if(mod_odd[i] < t){
            mod[i] -= t;
        }
        else{
            mod[i] -= mod_odd[i];
        }
        if(mod_odd[m-i] < t){
            mod[m-i] -= t;
        }
        else{
            mod[m-i] -= mod_odd[m-i];
        }
        ans += (mod[i] / 2) + (mod[m-i] / 2);
        // debug(i);debug(t);debug(ans);
    }
    // print(mod);
    cout << ans << endl;
}