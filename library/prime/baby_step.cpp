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

// a**x == b mod M となるようなxをO(root(M))で計算するアルゴリズム
template<class T>
struct BabyStepGiantStep {
    using i64 = std::int_fast64_t;
    T a, mod, r, A;
    unordered_map<T, T> mp;

    BabyStepGiantStep(T a, T mod): a(a), mod(mod) {
        build(a, mod);
    };

    void build(T _a, T _mod){
        a = _a;
        mod = _mod;
        T t = 1;
        r = sqrt(mod) + 1;
        for(ll i = 0; i <= r; i++){
            mp[t] = i;
            t *= a;
            t %= mod;
        }
        A = modinv(modpow(a, r, mod), mod);
    }

    T modinv(T _a, T m){
        ll b = m, u = 1, v = 0;
        while(b){
            ll t = _a/b;
            _a -= t * b; swap(_a,b);
            u -= t * v; swap(u,v);
        }
        u %= m;
        if(u < 0) u += m;
        return u;
    }

    T modpow(T _a, ll n, T mod){
        T res = 1, t = _a;
        while(n){
            if(n & 1){
                res *= t;
                res %= mod;
            }
            t *= t;
            t %= mod;
            n >>= 1;
        }
        return res;
    }

    T query(T b){
        T t = 1;
        for(ll i = 0; i <= r; i++){
            ll temp = t * b % mod;
            if(mp.count(temp)){
                return i * r + mp[temp];
            }
            t *= A;
            t %= mod;
        }
        return -1;
    }

};

template<class T>
T modpow(T a, ll n, T mod){
    T res = 1, t = a;
    while(n){
        if(n & 1){
            res *= t;
            res %= mod;
        }
        t *= t;
        t %= mod;
        n >>= 1;
    }
    return res;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll x,p; cin >> x >> p;
    ll a,b; cin >> a >> b;
    ll k = 1e7;
    ll ans = INF;
    if(b - a + 1 < k){
        ll r = modpow(x, a, p);
        rep(i,a,b+1){
            chmin(ans, r);
            r *= x;
            r %= p;
        }
    }
    else{
        BabyStepGiantStep<ll> bg(x, p);
        rep(i,1,p){
            ll t = bg.query(i);
            if(t == -1)continue;
            if(t > b)continue;
            if(a <= t){
                ans = i;
                break;
            }
            ll temp = (a - t) / (p - 1);
            t += temp * (p-1);
            if(t < a)t += p-1;
            if(t <= b){
                ans = i;
                break;
            }
        }
    }


    cout << ans << "\n";
}