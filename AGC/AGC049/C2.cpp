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
const long double eps = 1e-12;

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

template <typename Monoid>
struct DualSegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

    int sz, n;
    vector<Monoid> seg;

    const Monoid M1;
    const F f;

    DualSegmentTree(const int n, const F f, const Monoid &M1)
        : n(n), f(f), M1(M1) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build(vector<Monoid> &vec) {
        for (int i = 0; i < vec.size(); i++) set(i, vec[i]);
    }

    void update(int a, int b, const Monoid &x) {
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) seg[a++] = f(seg[a], x);
            if (b & 1) seg[b] = f(seg[--b], x);
        }
    }

    Monoid get(int k) {
        k += sz;
        Monoid res = seg[k];
        while (k >>= 1) {
            res = f(res, seg[k]);
        }
        return res;
    }

    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }
#ifdef LOCAL
    void print(const string s = "seg") {
        cerr << s << "\n";
        int t = 1, cnt = 0;
        for (int i = 1; i < sz * 2; i++) {
            cerr << to_string(seg[i]) << " ";
            cnt++;
            if (cnt == t) {
                cerr << "\n";
                t *= 2;
                cnt = 0;
            }
        }
        cerr << "\n";
    }
#else
    void print(const string s = "seg") {
        return;
    }
#endif
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<ll> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    auto f = [&](ll a, ll b) { return a + b; };
    DualSegmentTree<ll> seg(n, f, 0);
    rep(i,0,n){
        if(a[i] > b[i]){
            ll id = lower_bound(all(a), a[i] - b[i]) - a.begin();
            seg.update(id, i, 1);
        }
    }
    bool ok = true;
    rep(i,0,n){
        if (a[i] <= b[i]) ok &= seg.get(i);
    }

    if(ok){
        cout << 0 << endl;
        return 0;
    }

    ll ans = INF;
    ll sum = 0;
    rrep(i, n, 0) {
        if(a[i] <= b[i]){
            ll tmp = max(b[i] - a[i] + 1, sum);
            chmin(ans, tmp);
            if (!seg.get(i)) {
                sum++;
            }
        }
    }

    chmin(ans, sum);

    cout << ans << endl;
}