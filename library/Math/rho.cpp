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

template <typename T>
int comp(T a){
    if (abs(a) < eps) return 0;
    return a > 0 ? 1 : -1;
}

template <typename T>
int comp(T a, T b){
    // a > b -> 1, a < b -> -1
    return comp(a - b);
}
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

template <typename T, typename U>
T modpow(T a, U n, T m){
    unsigned __int128 res = 1;
    unsigned __int128 x = a;
    if (n == 0) return m == 1 ? 0 : 1;
    while(n){
        if(n & 1){
            res *= x;
            res %= m;
        }
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

template <typename T>
bool is_prime(T n){
    assert(n > 1);
    vector<ll> A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    if (n == 2 || n == 3 || n == 5 || n == 7) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0) return false;

    ll d = n - 1;
    while(~d & 1) d >>= 1;



    for(auto a : A){
        ll t = d;
        __uint128_t y = modpow(a, t, n);
        if(y == 0)continue;
        // debug(a, t, y);

        while(t != (n-1) && y != 1 && y != n-1){
            y = (y * y) % n;
            t <<= 1;
        }
        if(y != n-1 && (~t & 1)) return false;
    }
    return true;

}

template <typename T>
void rho(T n, map<T, int> &mp){
    auto f = [&n](T x, T c) {
        __uint128_t r = x;
        r = r * r + c;
        r %= n;
        return (T)r;
    };
    if (n == 1) return;
    if (is_prime(n)) {
        mp[n]++;
        return;
    }

    vector<ll> v = {2, 3, 5, 7, 11, 13};
    for(auto i : v){
        if(n % i == 0){
            mp[i]++;
            rho(n / i, mp);
            return;
        }
    }

    T d = 1;
    T c = 1;
    while (1) {
        T x = 2;
        T y = 2;

        while(d == 1){
            x = f(x, c);
            y = f(f(y, c), c);
            debug(n, x, y, c);
            if (x == y) break;
            d = gcd(n, abs(x - y));
        }
        if (d == 1) c++;
        else
            break;
    }
    rho(d, mp);
    rho(n / d, mp);
}

template<typename T>
map<T, int> prime(T x){
    map<T, int> mp;
    rho(x, mp);
    return mp;
}

template <typename T>
vector<T> divisor(T x) {
    auto mp = prime(x);
    vector<T> res;
    vector<pair<T, T>> v;
    for (auto p : mp) {
        debug(p);
        v.emplace_back(p);
    }
    ll n = v.size();
    auto dfs = [&](auto s, ll val = 1, ll d = 0) {
        if (d == n) {
            if (val != 1) res.emplace_back(val);
            return;
        }

        s(s, val, d + 1);
        for (int i = 0; i < v[d].second; i++) {
            val *= v[d].first;
            s(s, val, d + 1);
        }
    };
    dfs(dfs);
    return res;
}


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n; cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
    ll g = 0;
    rep(i,0,n){
        ll l = lcm(a[i], b[i]);
        g = gcd(g, l);
    }

    auto d = divisor(g);
    d.emplace_back(1);
    debug(d, g);
    ll res = 0;
    for(auto t : d){
        bool ok = true;
        rep(i,0,n){
            ok &= a[i] % t == 0 || b[i] % t == 0;
        }
        if (ok) chmax(res, t);
    }

    cout << res << endl;
}