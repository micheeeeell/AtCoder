#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(ll i = (ll)(s); i < (ll)(t); i++)
#define rrep(i,s,t) for(ll i = (ll)(s-1);(ll)(t) <= i; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
constexpr ll INF = numeric_limits<ll>::max()/4;
constexpr ll n_max = 2e5+10;
#define int ll

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';}
string to_string(const char *c) {return to_string((string) c);}
string to_string(bool b) {return (b ? "true" : "false");}
template <size_t N>
string to_string(bitset<N> v){
    string res = "";
    for(size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for(const auto &x : v) {
        if(!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}

void debug_out() {cerr << endl;}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

ll modpow(ll n, ll k, ll mod){ // n^k % mod
    ll res = 1;
    ll t = n;
    while(k){
        if(k & 1){
            res *= t;
            res %= mod;
        }
        t *= t;
        t %= mod;
        k >>= 1;
    }
    return res;
}

ll dfs(ll f, ll r, ll a, ll m){
    if(a == 1)return f;
    ll res = 0;
    if(a & 1){
        res = dfs(f, r, a/2, m) * (1 + modpow(r, (a+1)/2, m)) % m;
        res = (res + modpow(r, a/2, m)) % m;
    }
    else{
        res = dfs(f, r, a/2, m) * (1 + modpow(r, a / 2, m)) % m;
    }
    return res;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a,b,m; cin >> a >> b >> m;
    ll g = gcd(a, b);
    ll gn = dfs(1, 10, g, m);
    ll an = dfs(1, modpow(10, g, m), a/g, m);
    ll bn = dfs(1, modpow(10, g, m), b/g, m);
    debug(an, bn, gn);
    cout << ((an * bn) % m) * gn % m << "\n";

}