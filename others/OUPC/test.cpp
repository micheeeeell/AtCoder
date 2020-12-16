/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;
// using namespace atcoder;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define DEBUG_VEC(v)                                        \
    cerr << #v << ":";                                      \
    for (int i = 0; i < v.size(); i++) cerr << " " << v[i]; \
    cerr << endl;
#define DEBUG_MAT(v)                            \
    cerr << #v << endl;                         \
    for (int i = 0; i < v.size(); i++) {        \
        for (int j = 0; j < v[i].size(); j++) { \
            cerr << v[i][j] << " ";             \
        }                                       \
        cerr << endl;                           \
    }
typedef long long ll;
// #define int ll

#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int> >
#define vll vector<vector<ll> >
#define vs vector<string>
#define pii pair<int, int>
#define pis pair<int, string>
#define psi pair<string, int>
#define pll pair<ll, ll>
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
    return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) {
    return pair<S, T>(s.first - t.first, s.second - t.second);
}
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
#define X first
#define Y second
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rrep1(i, n) for (int i = (int)(n); i > 0; i--)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(), c.end()
void YES(bool t = true) {
    cout << (t ? "YES" : "NO") << endl;
}
void Yes(bool t = true) {
    cout << (t ? "Yes" : "No") << endl;
}
void yes(bool t = true) {
    cout << (t ? "yes" : "no") << endl;
}
void NO(bool t = true) {
    cout << (t ? "NO" : "YES") << endl;
}
void No(bool t = true) {
    cout << (t ? "No" : "Yes") << endl;
}
void no(bool t = true) {
    cout << (t ? "no" : "yes") << endl;
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
#define Sp(p) cout << setprecision(25) << fixed << p << endl;
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
#define fio()   \
    cin.tie(0); \
    ios::sync_with_stdio(false);
// const ll MOD = 1000000007;
const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

vi match;

bool dfs(int v, vii &G, vi &match, vi &used) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        int u = G[v][i], w = match[u];
        if (w < 0 || !used[w] && dfs(w, G, match, used)) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int bipartite_matching(vii &G) {
    int res = 0;
    match.resize(G.size());
    fill(all(match), -1);
    vi used(G.size());
    for (int v = 0; v < G.size(); v++) {
        if (match[v] < 0) {
            fill(used.begin(), used.end(), 0);
            if (dfs(v, G, match, used)) {
                res++;
            }
        }
    }
    return res;
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
    fio();

    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];

    const int M = 33333;
    vector<bool> is_prime(M, true);
    is_prime[0] = is_prime[1] = false;
    vi primes;
    REP(i, 2, M) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2; i * j < M; j++) is_prime[i * j] = false;
        }
    }

    map<ll, ll> cube;
    for (int u : primes) {
        cube[(ll)u * u * u] = u;
    }

    vi cubes;
    vector<pii> sekis;
    for (ll x : a) {
        if (x % 6 != 5) continue;
        if (cube.count(x)) {
            cubes.push_back(cube[x]);
        } else {
            vl divs;
            for (int u : primes) {
                while (x % u == 0) {
                    divs.push_back(u);
                    x /= u;
                    if (divs.size() >= 3) break;
                }
                if (divs.size() >= 3) break;
            }
            if (x > 1) divs.push_back(x);
            if (divs.size() != 2) continue;
            sort(all(divs));
            if (divs[0] == divs[1]) continue;
            sekis.push_back(pll(divs[0], divs[1]));
        }
    }

    if (cubes.size() == 0 and sekis.size() == 0) {
        for (ll x : a) {
            if (x % 6 == 1) continue;
            if (cube.count(x)) {
                cout << 1 << endl;
                cout << x << endl;
                return 0;
            } else {
                vl divs;
                for (int u : primes) {
                    while (x % u == 0) {
                        divs.push_back(u);
                        x /= u;
                        if (divs.size() >= 3) break;
                    }
                    if (divs.size() >= 3) break;
                }
                if (x > 1) divs.push_back(x);
                if (divs.size() != 2) continue;
                sort(all(divs));
                if (divs[0] == divs[1]) continue;
                cout << 1 << endl;
                cout << divs[0] * divs[1] << endl;
                return 0;
            }
        }
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    set<int> ban;
    for (int u : cubes) {
        ans++;
        ban.insert(u);
    }

    map<int, int> mp;
    vi con;
    int cnt = 0;
    for (pii yx : sekis) {
        if (ban.count(yx.first) or ban.count(yx.second)) continue;
        if (mp.count(yx.first) == 0) {
            mp[yx.first] = cnt++;
            con.push_back(yx.first);
        }
        if (mp.count(yx.second) == 0) {
            mp[yx.second] = cnt++;
            con.push_back(yx.second);
        }
    }

    vii G(cnt);
    for (pii yx : sekis) {
        if (ban.count(yx.first) or ban.count(yx.second)) continue;
        int u = mp[yx.first], v = mp[yx.second];
        G[u].push_back(v);
        G[v].push_back(u);
    }

    ans += bipartite_matching(G);
    cout << ans << endl;
    vector<ll> res;
    // cout << ans << endl;
    for (int i = 0; i < match.size(); i++) {
        if (match[i] != -1) {
            ll ai = match[i];
            res.emplace_back(con[i] * con[ai]);
            match[i] = match[ai] = -1;
        }
    }
    for (int u : cubes) {
        res.emplace_back(u * u * u);
    }
    print(res);
    return 0;
}
