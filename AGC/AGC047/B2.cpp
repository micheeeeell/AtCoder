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

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    using Pls = pair<ll, string>;
    map<Pls, ll> hash;
    const ll MS = 2;
    const ll mod[] = {999999937LL, 1000000007LL}, base = 9937;
    vector<string> v(n);
    rep(i, 0, n) {
        cin >> v[i];
    }
    sort(all(v),
         [](const auto &a, const auto &b) { return a.size() < b.size(); });
    ll ans = 0;
    rep(i, 0, n) {
        ll m = v[i].size();
        reverse(all(v[i]));
        vector<ll> cnt(26);
        rep(j, 0, m) {
            ll t = v[i][j] - 'a';
            cnt[t]++;
        }
        string s = "";
        rep(j, 0, m - 1) {
            rep(k, 0, 26) {
                if(cnt[k] <= 0) continue;
                Pls p = {k, s};
                if(hash.count(p)) {
                    ans += hash[p];
                }
            }
            s += v[i][j];
            ll t = v[i][j] - 'a';
            cnt[t]--;
        }
        debug(v[i], cnt);
        rep(k, 0, 26) {
            if(cnt[k] <= 0) continue;
            Pls p = {k, s};
            if(hash.count(p)) {
                ans += hash[p];
            }
        }

        ll t = v[i][m - 1] - 'a';
        hash[{t, s}]++;
    }

    cout << ans << "\n";
}