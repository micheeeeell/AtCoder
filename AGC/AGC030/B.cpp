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

template <typename Monoid>
struct SegmentTree {
    using F = function<Monoid(Monoid, Monoid)>;

    int sz, n;
    vector<Monoid> seg;

    const F f;
    const Monoid M1;
    SegmentTree(const int n, const F f, const Monoid &M1) : n(n), f(f), M1(M1) {
        sz = 1;
        while (sz < n) sz <<= 1;
        seg.assign(2 * sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build(vector<Monoid> &vec) {
        for (int i = 0; i < vec.size(); i++) set(i, vec[i]);
        for (int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while (k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, seg[a++]);
            if (b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[](const int &k) const {
        return seg[k + sz];
    }

    template <typename C>
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while (a < sz) {
            Monoid nxt =
                type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if (check(nxt))
                a = 2 * a + type;
            else
                M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template <typename C>
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if (a <= 0) {
            if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if (a & 1) {
                Monoid nxt = f(L, seg[a]);
                if (check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template <typename C>
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if (b >= sz) {
            if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for (b += sz; a < b; a >>= 1, b >>= 1) {
            if (b & 1) {
                Monoid nxt = f(seg[--b], R);
                if (check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }

    friend string to_string(SegmentTree<Monoid> &seg) {
        string s;
        for (int i = 0; i < seg.n; i++) {
            s += to_string(seg[i]) + " ";
        }
        return s;
    }
};

struct S{
    ll sum;
    ll val;
    ll size;
    friend string to_string(S &s){
        string res = "{";
        res += to_string(s.sum) + ", ";
        res += to_string(s.val) + ", ";
        res += to_string(s.size) + "}";
        return res;
    }
};
S f(S a, S b){
    S res;
    res.sum = a.sum + b.sum;
    res.size = a.size + b.size;
    res.val = a.val + b.val + b.sum * 2 * a.size;
    return res;
}

S f2(S a, S b){
    S res;
    res.sum = a.sum + b.sum;
    res.size = a.size + b.size;
    res.val = a.val + b.val + a.sum * 2 * b.size;
    return res;
}
signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll L,n; cin >> L >> n;
    vector<ll> a(n + 1);
    for(int i = 0; i < n; i++) cin >> a[i + 1];
    vector<S> s(n + 1);
    rep(i,0,n + 1){
        ll val = a[(i + 1) % (n + 1)] - a[i];
        if(val < 0)val += L;
        s[i] = {val, val, 1};
    }
    rep(i, 0, n + 1) debug(s[i]);

    SegmentTree<S> left(n + 1, f, S{0, 0, 0}), right(n + 1, f2, S{0, 0, 0});
    left.build(s);
    right.build(s);
    ll ans = 0;
    rep(i, 0, n + 1){
        ll l = i;
        ll r = n - l;
        ll lp = 0, rp = 0, pos = 0, tmp = 0;
        bool is_left = false;
        if (l > r) {
            lp = l - r;
            tmp += a[lp];
            pos = a[lp];
            l = r;
            is_left = true;
        } else if (l < r) {
            rp = n - (r - l) + 1;
            tmp += L - a[rp];
            pos = a[rp];
            r = l;
        }

        if(l == 0){
            chmax(ans, tmp);
            continue;
        }

        {
            // 右向きからスタート
            ll t = 0;
            S rs = right.query(lp, lp + l);
            S ls = left.query((rp - r + n + 1) % (n + 1), rp == 0 ? n + 1 : rp);
            t += rs.val;
            t += ls.val + ls.sum;
            debug(rs, ls);
            if(is_left){
                S sum = left.query(0, lp);
                debug(sum);
                t += sum.sum * r * 2;
            }
            else{
                S sum = right.query(rp == 0 ? n + 1 : rp, n + 1);
                debug(sum);
                t += sum.sum * (l * 2 - 1);
            }
            chmax(ans, tmp + t);
            debug(tmp, t);
        }
        {
            // 左向きからスタート
            ll t = 0;
            S rs = right.query(lp, lp + l);
            S ls = left.query((rp - r + n + 1) % (n + 1), rp == 0 ? n + 1 : rp);
            debug(rs, ls);
            t += rs.val + rs.sum;
            t += ls.val;
            if(is_left){
                S sum = left.query(0, lp);
                debug(sum);
                t += sum.sum * (r * 2 - 1);
            }
            else{
                S sum = right.query(rp == 0 ? n + 1 : rp, n + 1);
                debug(sum);
                t += sum.sum * r * 2;
            }
            chmax(ans, tmp + t);
            debug(tmp, t);
        }

        debug(l, r, lp, rp, ans, tmp);
    }

    cout << ans << endl;
}