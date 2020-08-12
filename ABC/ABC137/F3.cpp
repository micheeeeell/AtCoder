#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, t) for(ll i = (ll)(s); i < (ll)(t); i++)
#define rrep(i, s, t) for(ll i = (ll)(s - 1); (ll)(t) <= i; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> Pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
constexpr ll INF = numeric_limits<ll>::max() / 4;
constexpr ll n_max = 2e5 + 10;
#define int ll

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {
    return '"' + s + '"';
}
string to_string(const char *c) {
    return to_string((string)c);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
template <size_t N>
string to_string(bitset<N> v) {
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
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

void debug_out() {
    cerr << endl;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <class T>
bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<long long> MODS = {998244353};
template <int kind = 0, int fast = 0>
class mint {
   public:
    long long a;

    mint() : a(0) {
    }
    mint(long long a)
        : a(fast == 0 ? (a < 0 ? (a % MODS[kind] + MODS[kind]) % MODS[kind]
                               : (a >= MODS[kind] ? a % MODS[kind] : a))
                      : (a)) {
    }
    long long get_mod() {
        return MODS[kind];
    }
    long long get_val() {
        return a;
    }
    void take_mod() {
        a %= MODS[kind];
    }

    
    // template <typename T, long long kind>
    // friend constexpr mint<kind> modpow(const mint<kind> &mt, T n) noexcept {
    //     if(n < 0) {
    //         mint<kind> t = (modint(1) / mt);
    //         return modpow(t, -n);
    //     }
    //     mint<kind> res = 1, tmp = mt;
    //     while(n) {
    //         if(n & 1) res *= tmp;
    //         tmp *= tmp;
    //         n /= 2;
    //     }
    //     return res;
    // }
};
template<long long kind>
std::ostream &operator<<(std::ostream &out, const mint<kind> &m) {
    out << m.a;
    return out;
}
template<long long kind>
std::istream &operator>>(std::istream &in, mint<kind> &m) {
    ll a;
    in >> a;
    m = mint<kind>(a);
    return in;
}

template <int kind, int fast, int fast2>
bool operator==(mint<kind, fast>& a, mint<kind, fast2> b) {
    return a.a == b.a;
}
template <int kind, int fast, int fast2>
mint<kind, fast>& operator+=(mint<kind, fast>& a, mint<kind, fast2> b) {
    return a = a.a + b.a;
}
template <int kind>
mint<kind>& operator-=(mint<kind>& a, mint<kind> b) {
    return a = a.a - b.a;
}
template <int kind>
mint<kind>& operator*=(mint<kind>& a, mint<kind> b) {
    return a = a.a * b.a;
}
template <int kind>
mint<kind>& operator/=(mint<kind>& a, mint<kind> b) {
    return a = a.a * inv_mod(b.a, a.get_mod());
}
template <int kind, int fast, int fast2>
mint<kind, fast> operator+(mint<kind, fast> a, mint<kind, fast2> b) {
    return a += b;
}
template <int kind>
mint<kind> operator-(mint<kind> a, mint<kind> b) {
    return a -= b;
}
template <int kind>
mint<kind> operator*(mint<kind> a, mint<kind> b) {
    return a *= b;
}
template <int kind>
mint<kind> operator/(mint<kind> a, mint<kind> b) {
    return a /= b;
}
template <int kind, int fast>
mint<kind, fast>& operator+=(mint<kind, fast>& a, long long b) {
    return a = a.a + b;
}
template <int kind>
mint<kind>& operator-=(mint<kind>& a, long long b) {
    return a = a.a - b;
}
template <int kind>
mint<kind>& operator*=(mint<kind>& a, long long b) {
    return a = a.a * b;
}
template <int kind>
mint<kind>& operator/=(mint<kind>& a, long long b) {
    return a = a.a * inv_mod(b, a.get_mod());
}
template <int kind, int fast>
mint<kind, fast> operator+(mint<kind, fast> a, long long b) {
    return a += b;
}
template <int kind>
mint<kind> operator-(mint<kind> a, long long b) {
    return a -= b;
}
template <int kind>
mint<kind> operator*(mint<kind> a, long long b) {
    return a *= b;
}
template <int kind>
mint<kind> operator/(mint<kind> a, long long b) {
    return a /= b;
}
template<int kind>
bool operator!=(mint<kind> a, long long b){
    return a.a != b;
}
template<int kind>
string to_string(mint<kind> a){
    return to_string(a.a);
}

template <class T>
struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef() {
    }
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        init(n);
    }
    constexpr void init(int n) noexcept {
        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
        int MOD = fact_[0].get_mod();
        for(int i = 2; i < n; i++) {
            fact_[i] = fact_[i - 1] * i;
            inv_[i] = (T)0-inv_[MOD % i] * (MOD / i);
            finv_[i] = finv_[i - 1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept {
        if(n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[k] * finv_[n - k];
    }
    constexpr T fact(int n) const noexcept {
        if(n < 0) return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        if(n < 0) return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        if(n < 0) return 0;
        return finv_[n];
    }
};
void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    MODS.emplace_back(n);
    vector<mint<1>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    BiCoef<mint<1>> bc(n_max);
    auto c = [&](ll j) {
        vector<mint<1>> res(n);
        res[0] += 1;
        mint<1> t = 1, p = 1;
        rrep(i,n,0){
            res[i] -= bc.com(n-1, i) * t * p;
            t *= j;
            p *= -1;
        }
        debug(j, res);
        return res;
    };

    vector<mint<1>> ans(n);
    rep(i,0,n){
        auto d = c(i);
        rep(j,0,n)ans[j] += d[j] * a[i];
    }
    print(ans);
}