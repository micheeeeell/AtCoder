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
        k += sz;
        data[k] = x;
    }

    void build(vector<Monoid> &vec) {
        for(int i = 0; i < vec.size(); i++) set(i, vec[i]);
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

const long double pi = 3.14159265358979323846;
struct mon{
    double x, y;
    friend string to_string(mon &m){
        return to_string(m.x) + " " + to_string(m.y);
    }
};

struct op{
    double ang;
    double mul;
    bool operator!=(const op &rhs){
        return (this)->ang != rhs.ang || (this)->mul != rhs.mul;
    }
    bool operator!=(const op &rhs) const {
        return (this)->ang != rhs.ang || (this)->mul != rhs.mul;
    }
    bool operator==(const op &rhs) {
        return (this)->ang == rhs.ang && (this)->mul == rhs.mul;
    }
    bool operator==(const op &rhs) const {
        return (this)->ang == rhs.ang && (this)->mul == rhs.mul;
    }
};
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n,q; cin >> n >> q;
    auto f = [](mon a, mon b){
        return mon{a.x + b.x, a.y + b.y};
    };
    auto g = [](mon a, op o) {
        mon r = mon {
            a.x * cos(o.ang) - a.y * sin(o.ang), a.x * sin(o.ang) + a.y * cos(o.ang)
        };
        r.x *= o.mul;
        r.y *= o.mul;
        return r;
    };
    auto h =[](op x, op y){
        op r = {x.ang + y.ang, x.mul * y.mul};
        return r;
    };
    vector<double> angle(n);
    vector<double> d(n, 1);
    LazySegmentTree<mon, op> seg(n, f, g, h, mon{0, 0}, op{0, 1});
    vector<mon> v(n, {1, 0});
    seg.build(v);

    cout << fixed << setprecision(10);
    rep(i,0,q){
        ll t; cin >> t;
        if(t == 2){
            ll id; cin >> id;
            id--;
            mon r = seg.query(0, id+1);
            cout << r.x << " " << r.y << "\n";
        }
        if(t == 1){
            ll id,x; cin >> id >> x;
            id--;
            mon r = seg.query(id, id+1);
            // debug(r);
            double s = d[id];
            s = (double)x / s;
            seg.update(id, id+1, op{0, s});
            d[id] = x;
        }
        if(t == 0){
            ll id; cin >> id;
            double x; cin >> x;
            id--;
            x = x * pi / (double)180.0;
            double ang = x - angle[id];
            seg.update(id, n, op{ang, 1});
            angle[id] = x;
        }

        // debug(seg.query(0, n));
    }
}