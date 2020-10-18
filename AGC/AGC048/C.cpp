#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, t) for (ll i = (ll)(s); i < (ll)(t); i++)
#define rrep(i, s, t) for (ll i = (ll)(s - 1); (ll)(t) <= i; i--)
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
const long double pi = 3.14159265358979323846;

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
    for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
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
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n, l;
    cin >> n >> l;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    ll ans = 0;
    bool flag = true;
    if (n == 1) {
        if (b[0] == a[0])
            ans = 0;
        else if (b[0] == 1 || b[0] == l)
            ans = 1;
        else
            ans = INF;

        cout << (ans == INF ? -1 : ans) << endl;
        return 0;
    }

    rep(i, 0, n) {
        if (a[i] == b[i]) continue;

        if (a[i] > b[i]) {
            if (i == 0) {
                if (b[0] != 1)
                    flag = false;
                else
                    ans++;
            } else {
                if (b[i] == i + 1)
                    ans++;
                else if (b[i] == b[i - 1] + 1) {
                    ans++;
                } else {
                    ll ok = -1, ng = n;
                    while (abs(ok - ng) > 1) {
                        ll x = (ok + ng) / 2;
                        if (a[x] + (i - x) <= b[i])
                            ok = x;
                        else
                            ng = x;
                    }
                    debug(i, ok);
                    if (a[ok] + (i - ok) != b[i])
                        flag = false;
                    else {
                        ans += (i - ok);
                    }
                }
            }
        } else {
            if (i == n - 1) {
                if (b[i] != l)
                    flag = false;
                else {
                    ans++;
                }
            } else if (b[i] == b[i + 1] - 1) {
                ans++;
            } else {
                ll ok = n, ng = -1;
                while (abs(ok - ng) > 1) {
                    ll x = (ok + ng) / 2;
                    if (a[x] + (i - x) >= b[i])
                        ok = x;
                    else
                        ng = x;
                }
                debug(i, ok);
                if (a[ok] + (i - ok) != b[i]){
                    flag = false;
                }
                else {
                    ans += (ok - i);
                }
            }
        }
    }

    cout << (flag ? ans : -1) << endl;
}