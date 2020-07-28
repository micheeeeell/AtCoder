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
constexpr ll n_max = 2e6+10;
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

struct bic{
    vector<double> fact;
    bic(){};
    bic(ll n){
        fact.resize(n, 0);
        fact[0] = 0;
        rep(i,1,n_max){
            fact[i] = fact[i-1] + log(i);
        }
    }

    double com(ll n, ll k){
        if(n < k)return 0;
        return fact[n] - fact[k] - fact[n-k];
    }
};

bic bc(n_max);

template< typename Monoid >
struct SegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;

    int sz;
    vector< Monoid > seg;

    const F f;
    const Monoid M1;
    SegmentTree(const int n, const F f, const Monoid &M1) : f(f), M1(M1) {
        sz = 1;
        while(sz < n)sz <<= 1;
        seg.assign(2*sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build(vector< Monoid > &vec) {
        for(int i = 0; i < vec.size(); i++)set(i, vec[i]);
        for(int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) L = f(L, seg[a++]);
            if(b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[] (const int &k) const {
        return seg[k + sz];
    }

    template< typename C >
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while(a < sz) {
            Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if(check(nxt)) a = 2 * a + type;
            else M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template< typename C >
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if(a <= 0) {
            if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) {
                Monoid nxt = f(L, seg[a]);
                if(check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template< typename C >
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if(b >= sz) {
            if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for(b += sz; a < b; a >>= 1, b >>= 1) {
            if(b & 1){
                Monoid nxt = f(seg[--b], R);
                if(check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};

void YES(bool ok){
    cout << (ok ? "FIRST" : "SECOND") << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
    ll n = vec.size();
    k = min(k, n);
    for(int i = 0; i < k-1; i++) cout << vec[i] << " ";
    cout << vec[k-1] << endl;
}
template <class T>
void print(vector<vector<T>> &vec, ll k){
    ll n = vec[0].size();
    k = min(k, n);
    for(auto &i : vec)print(i, k);
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    SegmentTree<double> seg(n, [&](double a, double b){return a + b;}, 0);
    vector<Pll> v(n);
    rep(i,0,n){
        cin >> v[i].first >> v[i].second;
    }
    rep(i,0,n-1){
        ll x = v[i+1].first - v[i].first;
        ll y = v[i+1].second - v[i].second;
        seg.update(i, bc.com(x + y, x));
    }

    // print(bc.fact, 10);
    debug(bc.com(10, 3));

    ll q; cin >> q;
    rep(_,0,q){
        ll t; cin >> t;
        if(t == 1){
            ll k,a,b; cin >> k >> a >> b;
            k--;
            v[k] = {a, b};
            if(k != 0){
                ll x = v[k].first - v[k-1].first;
                ll y = v[k].second - v[k+1].second;
                seg.update(k-1, bc.com(x + y, x));
            }
            if(k != n-1){
                ll x = v[k+1].first - v[k].first;
                ll y = v[k+1].second - v[k].second;
                seg.update(k, bc.com(x + y, x));
            }
        }
        else{
            ll l1,r1; cin >> l1 >> r1;
            ll l2,r2; cin >> l2 >> r2;
            l1--;l2--;r1--;r2--;
            debug(l1, r1, seg.query(l1, r1));
            YES(seg.query(l1, r1) > seg.query(l2, r2));
        }
    }
}