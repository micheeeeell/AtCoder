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
const long double eps = 1e-12;

template <typename T>
int comp(T a) {
    if (abs(a) < eps) return 0;
    return a > 0 ? 1 : -1;
}

template <typename T>
int comp(T a, T b) {
    // a > b -> 1, a < b -> -1
    return comp(a - b);
}

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

struct S {
    vector<Pll> v;
    ll n;
    ll state = 0;
    Pll x = {0, 1}, y = {0, 1};
    S(ll n, vector<Pll> &v) : n(n), v(v){};

    void update(ll i) {
        if (i == 1) {
            state--;
            if (state < 0) state += 4;
        } else {
            state++;
            state %= 4;
        }
    }

    void update(ll i, ll j) {
        return update(i, j, state);
    }

    void update(ll i, ll j, ll d) {
        if (i == 3) {
            if (d == 0) {
                x = {2 * j - x.first, x.second * (-1)};
            } else if (d == 1) {
                update(4, -j, 0);
            } else if (d == 2) {
                update(i, -j, 0);
            } else {
                update(4, j, 0);
            }
        } else {
            if (d == 0) {
                y = {2 * j - y.first, y.second * (-1)};
            } else if (d == 1) {
                update(3, j, 0);
            } else if (d == 2) {
                update(4, -j, 0);
            } else {
                update(3, -j, 0);
            }
        }
    }

    Pll query(ll k) {
        k--;
        ll kx = v[k].first;
        ll ky = v[k].second;
        kx = x.first + kx * x.second;
        ky = y.first + ky * y.second;
        debug(kx, ky, state);
        if (state == 1) {
            swap(kx, ky);
            kx = -kx;
        } else if (state == 2) {
            kx = -kx;
            ky = -ky;
        } else if(state == 3){
            swap(kx, ky);
            ky = -ky;
        }

        return {kx, ky};
    }
};

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<Pll> v(n);
    rep(i, 0, n) {
        cin >> v[i].first >> v[i].second;
    }

    ll m;
    cin >> m;
    vector<Pll> op(m);
    rep(i, 0, m) {
        ll t;
        cin >> t;
        if (t == 3 || t == 4) {
            ll k;
            cin >> k;
            op[i].second = k;
        }
        op[i].first = t;
    }
    ll q;
    cin >> q;
    vector<tuple<ll, ll, ll>> que(q);
    rep(i, 0, q) {
        auto &[a, b, c] = que[i];
        cin >> a >> b;
        c = i;
    }
    sort(all(que));
    vector<Pll> ans(q);
    S s(n, v);
    ll cnt = 0;
    rep(i, 0, q) {
        auto [a, b, id] = que[i];
        while (cnt < m && cnt < a) {
            auto [t, k] = op[cnt++];
            if (t <= 2) {
                s.update(t);
            } else {
                s.update(t, k);
            }
        }
        debug(a, b, id);
        auto p = s.query(b);
        ans[id] = p;
    }

    for (auto p : ans) {
        cout << p.first << " " << p.second << "\n";
    }
}