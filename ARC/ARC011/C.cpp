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

template<typename T>
struct edge{
    int f,t;
    T c;
    int id;
    edge(){};
    edge(int f,int t,T c,int id = 0):f(f),t(t),c(c),id(id){};
    bool operator< (const edge &rhs) const {
        return (*this).c < rhs.c;
    }
    bool operator> (const edge &rhs) const {
        return (*this).c > rhs.c;
    }
    friend string to_string(edge<T> e){
        return "(" + to_string(e.f) + ", " + to_string(e.t) + ", " + to_string(e.c) + ")";
    }

};

template<typename T>
struct graph{
    std::vector<std::vector<edge<T> > > data;
    graph(){};
    graph(int v):data(v){};
    void resize(int n){
        data.resize(n);
    }
    void add_edge(edge<T> &e){
        data[e.f].push_back(e);
    }
    void add_edge(int f,int t,T c){
        data[f].emplace_back(f,t,c);
    }
    size_t size(){
        return data.size();
    }
    vector<edge<T>> &operator[](int n){
        return data[n];
    }
    std::vector<edge<T>> make_edges(){
        std::vector<edge<T>> r;
        for(auto &i:data)std::copy(i.begin(),i.end(),std::back_inserter(r));
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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s, t;cin >> s >> t;
    ll n; cin >> n;

    ll si, ti;
    vector<string> v(n + 2);
    rep(i,0,n){
        cin >> v[i];
    }
    if (s == t) {
        cout << 0 << endl;
        cout << s << endl << t << endl;
        return 0;
    }


    v[n] = s;
    v[n + 1] = t;
    si = n;
    ti = n + 1;
    n += 2;
    auto check = [&](string &a, string &b) {
        ll count = 0;
        ll m = a.size();
        rep(i,0,m){
            count += a[i] != b[i];
        }
        return count;
    };
    graph<ll> g(n);
    rep(i, 0, n) rep(j, i+1, n) {
        ll c = check(v[i], v[j]);
        if (c != 1) continue;
        g.add_edge(i, j, 1);
        g.add_edge(j, i, 1);
    }

    auto dij = dijkstra(g, si);
    ll ans = dij[ti];

    if (ans == std::numeric_limits<ll>::max()){
        cout << -1 << endl;
        return 0;
    }


    vector<ll> a;
    a.emplace_back(ti);
    ll d = ans, pos = ti;
    while (d){
        d--;
        for (auto &e : g[pos]){
            if(dij[e.t] == d){
                pos = e.t;
                a.emplace_back(pos);
                break;
            }
        }
    }

    reverse(all(a));
    cout << ans - 1 << "\n";
    for (auto i : a){
        cout << v[i] << "\n";
    }
}