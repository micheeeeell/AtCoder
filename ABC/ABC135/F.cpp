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

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll modpow(ll mt, ll n, ll mod) {
    if (n < 0) {
        n = -n;
        mt = modinv(mt, mod);
        // debug(mt, n);
    }
    ll res = 1, tmp = mt;
    while (n) {
        if (n & 1) {
            res *= tmp;
            res %= mod;
        }
        tmp *= tmp;
        tmp %= mod;
        n /= 2;
    }

    return res;
}
const ll MS = 2;
const ll mod[] = {999999937LL, 1000000007LL}, base = 9937;

struct RollingHash {
    ll n, base;
    vector<ll> hs[MS], pw[MS];
    RollingHash(){};
    RollingHash(const string &s, const ll base = 9937) : base(base) {
        n = s.size();
        for (int i = 0; i < MS; i++) {
            hs[i].assign(n + 1, 0);
            pw[i].assign(n + 1, 0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            for (int j = 0; j < n; j++) {
                pw[i][j + 1] = pw[i][j] * base % mod[i];
                hs[i][j + 1] = (hs[i][j] * base + s[j]) % mod[i];
            }
        }
    }

    vector<long long> hash(int l, int r){
        vector<long long> h;
        for (int i = 0; i < MS; i++) h.emplace_back(hash(l, r, i));
        return h;
    }

    long long hash(int l, int r, int i) {
        return ((hs[i][r] - hs[i][l] * pw[i][r - l]) % mod[i] + mod[i]) %
               mod[i];
    }

    bool match(int l1, int r1, int l2, int r2) {
        bool ret = true;
        for (int i = 0; i < MS; i++) ret &= hash(l1, r1, i) == hash(l2, r2, i);
        return ret;
    }

    bool match(int l, int r, vector<long long> h) {
        bool ret = true;
        for (int i = 0; i < MS; i++) ret &= hash(l, r, i) == h[i];
        return ret;
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s, t;cin >> s >> t;
    ll n = s.size(), m = t.size();
    RollingHash rh(t, base);
    ll run = m;
    rrep(i,m + 1, 1){
        if (m % i != 0) continue;
        bool ok = true;
        for (ll j = i; j < m; j += i){
            ok &= rh.match(0, i, j, j + i);
            if (!ok) break;
        }
        if (ok) run = i;
    }

    debug(m, run);

    string td = t.substr(0, run);
    // debug(td);
    string sd = s;
    while(sd.size() < s.size() + run){
        sd += s;
    }
    sd += sd;
    debug(n, sd.size());
    RollingHash srh(sd), trh(td);
    vector<ll> h = trh.hash(0, run);
    debug(h);

    auto check = [&](ll x) {
        vector<ll> hd(2);
        rep(i, 0, MS) {
            ll r = modpow(base, run, mod[i]);
            hd[i] = h[i] * ((modpow(r, x, mod[i]) - 1 + mod[i]) % mod[i]) % mod[i];
            hd[i] *= modinv((r - 1 + mod[i]) % mod[i], mod[i]);
            hd[i] %= mod[i];
        }
        debug(x, hd);
        bool ok = false;
        rep(i, 0, n) {
            if(i + x * run <= sd.size())ok |= srh.match(i, i + x * run, hd);
        }
        return ok;
    };

    ll ok = 0, ng = sd.size() / run + 1;
    while(abs(ok - ng) > 1){
        ll x = (ok + ng) / 2;
        if (check(x)) ok = x;
        else
            ng = x;
    }
    if (n % run == 0 && (ok * run == sd.size() || ok * run == sd.size() - run)){
        cout << -1 << endl;
        return 0;
    }
    cout << ok / (m / run) << endl;
}