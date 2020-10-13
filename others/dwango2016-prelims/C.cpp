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

template <typename T>
struct edge {
    int f, t;
    T c;
    T id;
    edge(){};
    edge(int f, int t, T c, T id = 0) : f(f), t(t), c(c), id(id){};
    bool operator<(const edge &rhs) const {
        return (*this).c < rhs.c;
    }
    bool operator>(const edge &rhs) const {
        return (*this).c > rhs.c;
    }
    friend string to_string(edge<T> e) {
        return "(" + to_string(e.f) + ", " + to_string(e.t) + ", " +
               to_string(e.c) + ", " + to_string(e.id) + ")";
    }
};

template <typename T>
struct graph {
    std::vector<std::vector<edge<T>>> data;
    graph(){};
    graph(int v) : data(v){};
    void resize(int n) {
        data.resize(n);
    }
    void add_edge(edge<T> &e) {
        data[e.f].push_back(e);
    }
    void add_edge(int f, int t, T c, T id = 0) {
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
};
template <typename T>
std::vector<T> dijkstra(graph<T> &g, int s) {
    using state = std::pair<T, int>;
    // priority_queue
    std::priority_queue<state, std::vector<state>, std::greater<state>> q;
    q.emplace((T)0, s);
    // data init
    std::vector<T> data(g.size(), std::numeric_limits<T>::max());
    data[s] = (T)0;
    // solve
    while (!q.empty()) {
        state cur = q.top();
        q.pop();
        T c = cur.first;
        int pos = cur.second;
        if (data[pos] < c) continue;
        for (auto &e : g.data[pos]) {
            if (c + e.c < data[e.t]) {
                data[e.t] = c + e.c;
                q.emplace(c + e.c, e.t);
            }
        }
    }
    return data;
};

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll s, d;
    cin >> s >> d;
    vector<vector<edge<ll>>> edges(m);
    graph<ll> g(n);

    vector<ll> sum(m);

    rep(i, 0, m) {
        ll l;
        cin >> l;
        vector<ll> node(l), dist(l - 1);
        rep(j, 0, l) {
            cin >> node[j];
        }
        ll tmp = 0;
        rep(j, 0, l - 1) cin >> dist[j];
        ll left = (node[0] << 1) | 1, right = node.back() << 1;
        rep(j, 0, l - 1) {
            g.add_edge(node[j], node[j + 1], dist[j]);
            g.add_edge(node[j + 1], node[j], dist[j]);
            edges[i].emplace_back(node[j], node[j + 1], dist[j], right);
            edges[i].emplace_back(node[j + 1], node[j], dist[j], left);
            tmp += dist[j];
        }
        sum[i] = tmp;
    }

    auto dij = dijkstra(g, d);
    rep(i, 0, m) {
        ll tmp = 0;
        for (auto &[f, t, dis, id] : edges[i]) {
            ll last = id >> 1;
            if (~id & 1) {
                id = dij[last] + sum[i] - tmp;
                tmp += dis;
            } else {
                id = dij[last] + tmp;
            }
        }
    }
    graph<ll> g2(n);
    rep(i, 0, m) {
        for (auto &e : edges[i]) {
            g2.add_edge(e);
            debug(e);
        }
    }

    auto check = [&](ll k) {
        using state = pair<ll, ll>;
        priority_queue<state, vector<state>, greater<state>> pq;
        pq.emplace(0, s);
        vector<ll> used(n, INF);
        used[s] = 0;
        while (!pq.empty()) {
            auto [c, t] = pq.top();
            pq.pop();
            if (c > used[t]) continue;
            for (auto &e : g2[t]) {
                if (c + e.id > k) continue;
                if (c + e.c < used[e.t]) {
                    used[e.t] = c + e.c;
                    pq.emplace(c + e.c, e.t);
                }
            }
        }
        // debug(k, used);
        return used[d] != INF;
    };

    ll ok = 1e9;
    ll ng = 0;
    while (abs(ok - ng) > 1) {
        ll x = (ok + ng) / 2;
        if (check(x))
            ok = x;
        else
            ng = x;
    }

    cout << ok << endl;
}