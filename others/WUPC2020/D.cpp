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

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while(b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if(u < 0) u += m;
    return u;
}

ll modpow(ll mt, ll n, ll mod){
    if(n < 0){
        n = -n;
        mt = modinv(mt,mod);
        // debug(mt, n);
    }
    ll res = 1, tmp = mt;
    while(n) {
        if(n & 1){
            res *= tmp;
            res %= mod;
        }
        tmp *= tmp;
        tmp %= mod;
        n /= 2;
    }

    return res;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m,q; cin >> n >> m >> q;
    vector<ll> d(m);
    for(int i = 0; i < m; i++) cin >> d[i];
    vector<ll> sum(m + 1);
    sum[0] = 1;
    rep(i,0,m){
        sum[i+1] = sum[i] * d[i];
        sum[i + 1] %= n;
    }

    auto calc = [&](ll y, ll z){
        ll ans = 1;
        ll r = z / m;
        ans *= modpow(sum[m], r, n);
        z %= m;
        if(z > m-y){
            ans *= sum[m] * modinv(sum[y], n) % n;
            z -= m - y;
            ans %= n;
            ans *= sum[z];
            ans %= n;
        }
        else{
            ans *= sum[y+z] * modinv(sum[y], n) % n;
            ans %= n;
        }
        return ans;
    };

    rep(i,0,q){
        ll x,y,z; cin >> x >> y >> z;
        y--;
        ll a = calc(y, z);
        // debug(a);
        ll d = modinv(a, n);
        cout << modpow(x, d, n+1) << "\n";
    }
}