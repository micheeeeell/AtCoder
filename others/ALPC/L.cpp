#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
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

struct S {
    ll num;
    ll o, z;
    ll rev(){
        ll a = o + z;
        ll res = a * (a - 1) / 2;
        res -= num;
        res -= o * (o - 1) / 2 + z * (z - 1) / 2;
        return res;
    }
};
S op(S l, S r){
    return S{l.num + r.num + l.o * r.z, l.o + r.o, l.z + r.z};
}

S e(){
    return S{0, 0, 0};
}

S mapping(bool is_rev, S x){
    return is_rev ? S{x.rev(), x.z, x.o} : x;
}

bool composition(bool f, bool g){
    return f ^ g;
}

bool id(){
    return false;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,q; cin >> n >> q;
    vector<S> a(n);
    rep(i,0,n){
        ll t; cin >> t;
        if(t)a[i] = S{0, 1, 0};
        else a[i] = S{0, 0, 1};
    }

    lazy_segtree<S, op, e, bool, mapping, composition, id> lseg(a);

    rep(i,0,q){
        ll t; cin >> t;
        if(t == 1){
            ll l,r; cin >> l >> r;
            l--;
            lseg.apply(l, r, true);
        }
        else{
            ll l,r; cin >> l >> r;
            l--;
            cout << lseg.prod(l, r).num << "\n";
        }
    }
}