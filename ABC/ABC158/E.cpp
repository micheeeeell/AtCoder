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

int main(){
    ll n,p; cin >> n >> p;
    string s;cin >> s;
    ll ans = 0;
    if(p == 2 || p == 5){
        rep(i,n){
            ll t = s[i] - '0';
            if(t % p == 0)ans += i+1;
        }

        cout << ans << endl;
        return 0;
    }

    vector<ll> mod(n+1, 0);
    // map<ll, ll> map_;
    vector<ll> rot(p,0);
    vector<vector<ll>> cnt(2,vector<ll>(p,0));
    rep(i,p)rot[i] = (i * 10) % p;
    rep(i,n){
        ll t = s[i] - '0';
        ll turn = i & 1;
        ll pre = turn ^ 1;
        mod[i+1] = (mod[i] * 10 + t) % p;
        // map_[mod[i+1]]++;
        if(mod[i+1] == 0)ans++;
        rep(i,p)cnt[turn][rot[i]] = cnt[pre][i];
        ans += cnt[turn][mod[i+1]]++;
        // print(cnt[turn]);
    }

    // for(auto itr = map_.begin(); itr != map_.end(); itr++){
    //     ans += (*itr).second * ((*itr).second-1) / 2;
    // }


    cout << ans << endl;
}