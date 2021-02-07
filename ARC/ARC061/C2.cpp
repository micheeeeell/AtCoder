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
template <typename T>
struct edge {
    int f, t;
    T c;
    int id;
    edge(){};
    edge(int f, int t, T c, int id = 0) : f(f), t(t), c(c), id(id){};
    bool operator<(const edge &rhs) const {
        return (*this).c < rhs.c;
    }
    bool operator>(const edge &rhs) const {
        return (*this).c > rhs.c;
    }
    friend string to_string(edge<T> e) {
        return "(" + to_string(e.f) + ", " + to_string(e.t) + ", " +
               to_string(e.c) + ")";
    }
};

template <typename T>
struct graph {
    std::vector<std::vector<edge<T>>> data;
    graph(){};
    int n;
    graph(int v) : n(v), data(v){};
    void resize(int n) {
        data.resize(n);
    }
    void add_edge(edge<T> &e) {
        data[e.f].push_back(e);
    }
    void add_edge(int f, int t, T c) {
        data[f].emplace_back(f, t, c);
    }
    void add_edge(int f, int t, T c, int id) {
        data[f].emplace_back(f, t, c, id);
    }
    size_t size() {
        return data.size();
    }
    vector<edge<T>> &operator[](int n) {
        return data[n];
    }
    std::vector<edge<T>> make_edges() {
        std::vector<edge<T>> r;
        for (auto &i : data)
            std::copy(i.begin(), i.end(), std::back_inserter(r));
        return r;
    }

    vector<T> dijkstra(ll s) {
        using state = pair<T, int>;
        priority_queue<state, vector<state>, greater<state>> pq;
        T max_ = INF;
        vector<T> res(n, max_);
        res[s] = 0;
        pq.emplace((T)0, s);
        while (!pq.empty()) {
            auto [c, t] = pq.top();
            pq.pop();
            if (res[t] < c) continue;
            for (auto &e : data[t]) {
                if (chmin(res[e.t], e.c + c)) {
                    pq.emplace(res[e.t], e.t);
                }
            }
        }

        return res;
    }

    vector<vector<T>> warshall_froid() {
        vector<vector<T>> res(n, vector<T>(n, INF));
        for (int i = 0; i < n; i++) res[i][i] = 0;
        for (int i = 0; i < n; i++) {
            for (auto e : data[i]) {
                res[e.f][e.t] = e.c;
            }
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (res[i][k] == INF || res[k][j] == INF) continue;
                    res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
                }
            }
        }

        return res;
    }
    vector<ll> topo_sort() {
        queue<ll> que;
        vector<ll> ans;
        vector<ll> in(n);
        for (auto edges : data) {
            for (auto e : edges) in[e.t]++;
        }
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) {
                que.emplace(i);
                ans.emplace_back(i);
            }
        }

        while (!que.empty()) {
            auto f = que.front();
            que.pop();
            for (auto &e : data[f]) {
                in[e.t]--;
                if (!in[e.t]) {
                    ans.emplace_back(e.t);
                    que.emplace(e.t);
                }
            }
        }

        return ans;
    };
};
signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    graph<ll> g(n);
    rep(i, 0, m) {
        ll f, t, c;
        cin >> f >> t >> c;
        f--;
        t--;
        g.add_edge(f, t, c);
        g.add_edge(t, f, c);
    }
    map<Pll, ll> mp;
    deque<Pll> deq;
    for (auto e : g[0]) {
        deq.emplace_back(Pll(0, e.c));
        mp[Pll{0, e.c}] = 1;
    }

    while (!deq.empty()) {
        auto [pos, last] = deq.front();
        deq.pop_front();
        ll c = mp[Pll{pos, last}];
        debug(pos, last, c);
        for (auto e : g[pos]) {
            if (mp.count(Pll{e.t, e.c})) {
                if(e.c == last){
                    chmin(mp[Pll{e.t, e.c}], c);
                }
                else {
                    chmin(mp[Pll{e.t, e.c}], c + 1);
                }
            }else{
                if (e.c == last) {
                    deq.emplace_front(Pll{e.t, e.c});
                    mp[Pll{e.t, e.c}] = c;
                } else {
                    deq.emplace_back(Pll{e.t, e.c});
                    mp[Pll{e.t, e.c}] = c + 1;
                }
            }

        }
    }

    ll res = INF;
    for (auto p : mp) {
        if (p.first.first == n - 1) {
            chmin(res, p.second);
        }
    }

    cout << (res != INF ? res : -1) << endl;
}