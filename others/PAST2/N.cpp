// #define _GLIBCXX_DEBUG
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

template< typename Monoid, typename OperatorMonoid = Monoid >
struct LazySegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;
    // using G = function< Monoid(Monoid, OperatorMonoid) >;
    using G = function< Monoid(Monoid, OperatorMonoid, int) >;
    using H = function< OperatorMonoid(OperatorMonoid, OperatorMonoid) >;

    int sz, height;
    vector< Monoid > data;
    vector< OperatorMonoid > lazy;
    const F f;
    const G g;
    const H h;
    const Monoid M1;
    const OperatorMonoid OM0;


    LazySegmentTree(int n, const F f, const G g, const H h,
                    const Monoid &M1, const OperatorMonoid OM0)
        : f(f), g(g), h(h), M1(M1), OM0(OM0) {
        sz = 1;
        height = 0;
        while(sz < n) sz <<= 1, height++;
        data.assign(2 * sz, M1);
        lazy.assign(2 * sz, OM0);
    }

    void set(int k, const Monoid &x) {
        data[k + sz] = x;
    }

    void build(vector< Monoid > &vec) {
        for(int i = 0; i < vec.size(); i++)set(i,vec[i]);
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
        // return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k]);
        return lazy[k] == OM0 ? data[k] : g(data[k], lazy[k], length(k));
    }

    int length(int k) {
        int l = sz;
        while(k >>= 1)l >>= 1;
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

    template< typename C >
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while(a < sz) {
        propagate(a);
        Monoid nxt = type ? f(reflect(2 * a + type), M) : f(M, reflect(2 * a + type));
        if(check(nxt)) a = 2 * a + type;
        else M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template< typename C >
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


    template< typename C >
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
};
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



struct state{
    ll x,y,d,c,i;
    state(){};
    state(ll x,ll y, ll d, ll c, ll i):x(x), y(y), d(d), c(c), i(i){}
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,q; cin >> n >> q;
    auto f = [](ll a, ll b){return a + b;};
    auto g = [](ll a, ll x, int num){return a + x * num;};
    auto h = [](ll a, ll b){return a + b;};
    vector<state> v;
    vector<ll> ynum;
    rep(i,n){
        ll x,y; cin >> x >> y;
        ll d,c; cin >> d >> c;
        v.emplace_back(x, y, d, c, 1);
        v.emplace_back(x + d + 1, y, d, c, 2);
        ynum.emplace_back(y);
        ynum.emplace_back(y + d);
    }
    rep(i,q){
        ll x,y; cin >> x >> y;
        v.emplace_back(x,y,i,0,3);
        ynum.emplace_back(y);
    }

    sort(all(ynum));
    unordered_map<ll,ll> za;
    ll id = 0;
    for(auto &y : ynum){
        if(za.find(y) == za.end())za[y] = id++;
    }
    LazySegmentTree<ll> seg(id, f, g, h, 0LL, 0LL);
    sort(all(v), [&](const auto &a, const auto &b){
        return a.x < b.x || (a.x == b.x && a.i < b.i);
    });
    vector<ll> ans(q);
    for(auto &p : v){
        if(p.i == 1){
            seg.update(za[p.y], za[p.y + p.d] + 1, p.c);
        }
        if(p.i == 2){
            seg.update(za[p.y], za[p.y + p.d] + 1, -p.c);
        }
        if(p.i == 3){
            ans[p.d] = seg.query(za[p.y], za[p.y] + 1);
        }
        // debug(p.x);debug(p.y);
    }

    print(ans);
}