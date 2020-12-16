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

template <typename flow_t>
struct Dinic {
    const flow_t INF;

    struct edge {
        int to;
        flow_t cap;
        int rev;
        bool isrev;
        int idx;
    };

    vector<vector<edge>> graph;
    vector<int> min_cost, iter;

    Dinic(int V) : INF(numeric_limits<flow_t>::max()), graph(V) {}

    void add_edge(int from, int to, flow_t cap, int idx = -1) {
        graph[from].emplace_back(
            (edge){to, cap, (int)graph[to].size(), false, idx});
        graph[to].emplace_back(
            (edge){from, 0, (int)graph[from].size() - 1, true, idx});
    }

    bool bfs(int s, int t) {
        min_cost.assign(graph.size(), -1);
        queue<int> que;
        min_cost[s] = 0;
        que.push(s);
        while (!que.empty() && min_cost[t] == -1) {
            int p = que.front();
            que.pop();
            for (auto &e : graph[p]) {
                if (e.cap > 0 && min_cost[e.to] == -1) {
                    min_cost[e.to] = min_cost[p] + 1;
                    que.push(e.to);
                }
            }
        }
        return min_cost[t] != -1;
    }

    flow_t dfs(int idx, const int t, flow_t flow) {
        if (idx == t) return flow;
        for (int &i = iter[idx]; i < graph[idx].size(); i++) {
            edge &e = graph[idx][i];
            if (e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t flow = 0;
        while (bfs(s, t)) {
            iter.assign(graph.size(), 0);
            flow_t f = 0;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }

    vector<pair<ll, ll>> output(ll s, ll t) {
        vector<Pll> res;
        for (int i = 0; i < graph.size(); i++) {
            for (auto &e : graph[i]) {
                if (e.isrev) continue;
                auto &rev_e = graph[e.to][e.rev];
                if (i != s && e.to != t && rev_e.cap != 0) {
                    res.emplace_back(Pll{i, e.to});
                }
            }
        }
        return res;
    }
};

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

pair<ll, vl> solve(vector<ll> a) {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    n = a.size();
    vector<ll> v;
    rep(i, 0, n) {
        ll cnt = 0;
        bool ok = true;
        for (ll j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                if (j != a[i] / j)
                    cnt += 2;
                else
                    cnt += 1;
                if (cnt > 4) {
                    ok = false;
                    break;
                }
            }
        }
        // debug(a[i], ok, cnt);
        ok &= cnt == 4;
        if (ok) v.emplace_back(a[i]);
    }
    if (v.size() == 0) {
        return {-1, {}};
    }
    vector<ll> five, oth;
    for (auto i : v) {
        if (i % 6 == 5)
            five.emplace_back(i);
        else if (i % 6 == 1)
            continue;
        else
            oth.emplace_back(i);
    }
    if (five.size() == 0 && oth.size() == 0) {
        return {-1, {}};
    }
    if (five.size() == 0) {
        // cout << 1 << "\n";
        // cout << oth.back() << "\n";
        return {1, {oth.back()}};
    }
    // if(five.size() == 1){
    //     cout << 1 << "\n";
    //     cout << five.back() << "\n";
    //     return 0;
    // }

    vector<ll> ans;
    vector<ll> prime;
    map<ll, ll> used;
    for (auto i : five) {
        ll p = 0;
        rep(j, 2, i + 1) {
            if (i % j == 0) {
                p = j;
                break;
            }
        }
        if ((i / p) % p == 0) {
            ans.emplace_back(i);
            used[p] = 1;
        }
    }
    for (auto i : five) {
        ll p = 0;
        rep(j, 2, i + 1) {
            if (i % j == 0) {
                p = j;
                break;
            }
        }
        if (used[p] || used[i / p]) continue;
        prime.emplace_back(p);
        prime.emplace_back(i / p);
    }

    sort(all(prime));
    prime.erase(unique(all(prime)), prime.end());

    ll m = prime.size();
    map<ll, ll> mp;
    rep(i, 0, prime.size()) mp[prime[i]] = i;

    Dinic<ll> dinic(m + 2);
    ll s = m, t = m + 1;

    for (auto p : prime) {
        if (p % 6 == 1) {
            dinic.add_edge(s, mp[p], 1);
        } else {
            dinic.add_edge(mp[p], t, 1);
        }
    }
    for (auto i : five) {
        ll p = 0;
        rep(j, 2, i + 1) {
            if (i % j == 0) {
                p = j;
                break;
            }
        }
        if (used[p] || used[i / p]) continue;
        {
            if (p % 6 == 1) {
                dinic.add_edge(mp[p], mp[i / p], 1);
            } else {
                dinic.add_edge(mp[i / p], mp[p], 1);
            }
        }
    }
    dinic.max_flow(s, t);
    auto res = dinic.output(s, t);
    // debug(res);
    for (auto pl : res) {
        ans.emplace_back(prime[pl.first] * prime[pl.second]);
    }
    return {ans.size(), ans};
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto s = solve(a);
    print(s.first);
    if(s.first != -1)print(s.second);
}