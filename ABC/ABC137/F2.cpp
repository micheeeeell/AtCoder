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
    ll p;
    cin >> p;
    vector<ll> a(p);
    for(int i = 0; i < p; i++) cin >> a[i];
    vector<ll> ans(p);
    ans[0] = a[0];
    ll inv = modinv(p - 1, p);
    debug(inv);
    rep(i, 0, p) {
        a[i] -= ans[0];
        if(a[i] < 0)a[i] += p;
    }
    debug(a);
    rep(i, 1, p){
        ll sum = 0;
        rep(i,0,p){
            sum += a[i];
            sum %= p;
            a[i] *= i;
            a[i] %= p;
        }
        debug(sum);
        ans[p-i] = sum * inv % p;
    }
    print(ans);
}