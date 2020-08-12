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

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
    cout << head;
    if(sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for(auto &a : vec) {
        cout << a;
        if(&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for(auto &vec : df) {
        print(vec);
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n, a, b;
    cin >> n >> a >> b;
    auto rem = [](ll x, ll k) {
        ll u = x >> (k + 1);
        ll d = x & ((1LL << k) - 1);
        return (u << k) + d;
    };

    auto ins = [](ll x, ll k, ll one) {
        ll u = x >> k;
        ll d = x & ((1LL << k) - 1);
        return (u << (k + 1)) + d + (one << k);
    };

    debug(rem(10, 2), ins(10, 2, 1));

    auto dfs = [&](auto self, ll s, ll t, ll n) -> vector<ll> {
        if(n == 1) {
            if(s == 0)
                return {0, 1};
            else
                return {1, 0};
        }
        ll id = 0;
        while(((s >> id) & 1) == ((t >> id) & 1)) id++;
        ll c = rem(s, id) ^ 1;
        vector<ll> l = self(self, rem(s, id), c, n - 1),
                   r = self(self, c, rem(t, id), n - 1);
        debug(s, t, id, rem(s, id), rem(t, id), c);
        vector<ll> res;
        ll one = (s >> id) & 1;
        for(auto &i : l) {
            res.emplace_back(ins(i, id, one));
        }
        for(auto &i : r) {
            res.emplace_back(ins(i, id, one ^ 1));
        }
        debug(res);
        return res;
    };
    debug(__builtin_popcountll(a), __builtin_popcountll(b));
    if((__builtin_popcountll(a) & 1) == (__builtin_popcountll(b) & 1)) {
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    auto ans = dfs(dfs, a, b, n);
    print(ans);
}