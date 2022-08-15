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

// SegmentTree(n, f, g, h, M1, OM0):= サイズ n の初期化。
// ここで f は2つの区間の要素をマージする二項演算, 
// g は要素と作用素をマージする二項演算(第三引数が必要な場合，対応する区間の長さ), 
// h は作用素同士をマージする二項演算, 
// M1 はモノイドの単位元, 
// OM0 は作用素の単位元である。
// update(a, b, x) := 区間 [a,b) に作用素 x を適用する。
// set(id, x) := id番目の要素をxに変更する(一点更新)
// dataの一番下（元のデータ）はsetによって変えない限り常に変わらない(seg[id]で現在のid番目の要素に直接アクセスできる)
// seg[id] == seg.query(id, id+1)とは限らない

template <typename Monoid, typename OperatorMonoid = Monoid>
struct LazySegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function< Monoid(Monoid, OperatorMonoid) >;
    // using G = function<Monoid(Monoid, OperatorMonoid, int)>;
    using H = function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>;

    int sz, height, n;
    vector<Monoid> data;
    vector<OperatorMonoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;

    LazySegmentTree(int n, const F f, const G g, const H h, const Monoid &M1,
                    const OperatorMonoid OM0)
        : n(n), f(f), g(g), h(h), M1(M1), OM0(OM0) {
        sz = 1;
        height = 0;
        while(sz < n) sz <<= 1, height++;
        data.assign(2 * sz, M1);
        lazy.assign(2 * sz, OM0);
    }

    void set(int k, const Monoid &x) {
        thrust(k += sz);
        data[k] = x;
        recalc(k);
    }

    void build(const vector<Monoid> &vec) {
        for(int i = 0; i < vec.size(); i++) data[i + sz] = vec[i];
        for(int k = sz - 1; k > 0; k--) {
            data[k] = f(data[2 * k + 0], data[2 * k + 1]);
        }
    }

    inline void propagate(int k) {
        if(lazy[k] != OM0) {
            lazy[2 * k + 0] = h(lazy[2 * k + 0], lazy[k]);
            lazy[2 * k + 1] = h(lazy[2 * k + 1], lazy[k]);
            data[k] = reflect(k);
            lazy[k] = OM0;
        }
    }

    inline Monoid reflect(int k) {
        return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
        // return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k], length(k));
    }

    int length(int k) {
        int l = sz;
        while(k >>= 1) l >>= 1;
        return l;
    }

    inline void recalc(int k) {
        while(k >>= 1) data[k] = f(reflect(2 * k + 0), reflect(2 * k + 1));
    }

    inline void thrust(int k) {
        for(int i = height; i > 0; i--) propagate(k >> i);
    }

    void update(int a, int b, const OperatorMonoid &x) {
        thrust(a += sz);
        thrust(b += sz - 1);
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) lazy[l] = h(lazy[l], x), ++l;
            if(r & 1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    Monoid query(int a, int b) {
        thrust(a += sz);
        thrust(b += sz - 1);
        Monoid L = M1, R = M1;
        for(int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) L = f(L, reflect(l++));
            if(r & 1) R = f(reflect(--r), R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) {
        return query(k, k + 1);
    }

    template <typename C>
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while(a < sz) {
            propagate(a);
            Monoid nxt = type ? f(reflect(2 * a + type), M)
                              : f(M, reflect(2 * a + type));
            if(check(nxt))
                a = 2 * a + type;
            else
                M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template <typename C>
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if(a <= 0) {
            if(check(f(L, reflect(1)))) return find_subtree(1, check, L, false);
            return -1;
        }
        thrust(a + sz);
        int b = sz;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) {
                Monoid nxt = f(L, reflect(a));
                if(check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template <typename C>
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if(b >= sz) {
            if(check(f(reflect(1), R))) return find_subtree(1, check, R, true);
            return -1;
        }
        thrust(b + sz - 1);
        int a = sz;
        for(b += sz; a < b; a >>= 1, b >>= 1) {
            if(b & 1) {
                Monoid nxt = f(reflect(--b), R);
                if(check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }

    friend string to_string(LazySegmentTree<Monoid, OperatorMonoid> &seg) {
        string s;
        for(int i = 0; i < seg.n; i++) {
            s += to_string(seg[i]) + " ";
        }
        return s;
    }
};

// 区間min、区間上書きの例（作用素の単位元を-1で定義、出てきうる数値の範囲にない数を適宜設定）

// auto f = [](ll a, ll b) { return min(a, b); };
// auto g = [](ll a, ll x) { return (x == -1 ? a : x); };
// auto h = [](ll a, ll b) { return b; };
// LazySegmentTree<ll, ll> seg(W, f, g, h, INF, -1);

// 区間和、区間更新の例
// struct S {
//     ll value = 0;
//     ll size = 0;
// };
// S e = {0, 0};  // monoid単位元
// ll id = INF;  //作用素の単位元
// auto f = [](S a, S b) { return S{a.value + b.value, a.size + b.size}; };
// auto g = [](S a, ll x) {
//     if (x != INF) a.value = x * a.size;
//     return a;
// };
// auto h = [](ll a, ll b) { return b == INF ? a : b; };
// LazySegmentTree<S, ll> seg(n, f, g, h, e, id);
// seg.build(vector<S>(n,S{0, 1}));

signed
main() {
    ll n,q; cin >> n >> q;
    vector<ll> a(n,0);
    // 区間和取得、区間加算の例
    auto f = [](ll a, ll b){ return a + b; };
    auto g = [](ll a, ll x, int num){ return a + x * num; };
    auto h = [](ll a, ll b){ return a + b; };
    LazySegmentTree<ll> seg(n, f, g, h, 0, 0);
    // debug(seg.sz);
    // debug(seg.length(1));
    seg.build(a);
    debug(seg);
    // rep(i,q){
    //     ll qry; cin >> qry;
    //     if(qry == 0){
    //         ll s,t,x; cin >> s >> t >> x;
    //         s--;t--;
    //         seg.update(s,t+1, x);
    //     }
    //     else {
    //         ll s,t; cin >> s >> t;
    //         s--;t--;
    //         cout << seg.query(s, t+1) << "\n";
    //     }
    // }
}