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

// template <class Head, class... Tail>
// void print(Head&& head, Tail&&... tail) {
//     cout << head;
//     if (sizeof...(tail) != 0) cout << " ";
//     print(forward<Tail>(tail)...);
// }

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i,k-1)cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    cout << p.first << " " << p.second << "\n";
}


template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    vvl table(n, vl(m));
    rep(i,n)rep(j,m){
        cin >> table[i][j];
        table[i][j]--;
    }
    auto c = [&](ll k){
        bitset<n_max> used = 0;
        vector<ll> top(n);
        bool ok = false;
        vector<ll> cnt(m), clear(m);
        Pll max_ = {0, -1};
        while(!ok && used.count() < m){
            max_ = {0,-1};
            rep(i,n){
                // debug(i);
                while(top[i] < m && used[table[i][top[i]]])top[i]++;
                // debug(top[i]);
                // if(top[i] == m)return false;
                cnt[table[i][top[i]]]++;
            }
            rep(i,m)chmax(max_, {cnt[i], i});
            if(max_.first <= k)ok = true;
            else{
                cnt = clear;
                used[max_.second] = 1;
            }
            // print(max_);
            // print(top);
        }
        return ok;
    };

    ll ok = n;
    ll ng = 0;
    while(abs(ok - ng) > 1){
        ll k = (ok + ng) / 2;
        if(c(k))ok = k;
        else ng = k;
    }

    cout << ok << endl;
}