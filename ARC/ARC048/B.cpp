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

signed main(){
    ll n; cin >> n;
    vector<Pll> rh(n);
    vvl vec(n_max, vector<ll>(3, 0));
    rep(i,n){
        ll r,h; cin >> r >> h;
        vec[r][--h]++;
        rh[i] = {r, h};
    }
    vector<ll> cnt(n_max);
    rrep(i,n_max-1){
        cnt[i] = cnt[i+1];
        rep(j,3)cnt[i] += vec[i][j];
    }
    
    rep(i,n){
        // auto [r, h] = rh[i];
        ll r = rh[i].first, h = rh[i].second;
        ll lose = cnt[r + 1];
        lose += vec[r][(h + 2) % 3];
        ll even = vec[r][h] - 1;
        ll win = n - lose - even - 1;
        print(win, lose, even);
    }
    return 0;
}