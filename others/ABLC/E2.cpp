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
const long double pi = 3.14159265358979323846;

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
using mint = modint998244353;
vector<mint> ten, one;
struct S {
    mint v;
    int len;
};

using F = ll;
const F ID = 0;
S op(S a, S b) {
    return S{a.v * ten[b.len] + b.v, b.len + a.len};
}

S e(){
    return {0, 0};
}

S mapping(F x, S a){
    if(x != ID){
        a.v = one[a.len] * x;
    }
    return a;
}

F composition(F a, F b){
    return a == ID ? b : a;
}

F id(){
    return ID;
}
signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n,q; cin >> n >> q;
    one.resize(n + 1);
    ten.resize(n + 1);
    one[0] = 0;
    ten[0] = 1;
    vector<S> v(n);
    rep(i,0,n){
        one[i + 1] = one[i] * 10 + 1;
        ten[i + 1] = ten[i] * 10;
        v[i] = {1, 1};
    }
    lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    debug(seg.all_prod().v.val());
    rep(i, 0, q) {
        ll l,r,d; cin >> l >> r >> d;
        l--;
        seg.apply(l, r, d);
        S t = seg.all_prod();
        cout << t.v.val() << "\n";
    }
}