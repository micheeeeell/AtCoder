// #define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';}
string to_string(const char c) {return to_string((string) &c);}
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
};

template<typename T>
struct graph{
    std::vector<std::vector<edge<T> > > data;
    graph(int v):data(v){};
    void add_edge(edge<T> &e){
        data[e.f].push_back(e);
    }
    void add_edge(int f,int t,T c){
        data[f].emplace_back(f,t,c);
    }
    size_t size(){
        return data.size();
    }
    vector<edge<T>> operator[](int n){
        return data[n];
    }
    std::vector<edge<T>> make_edges(){
        std::vector<edge<T>> r;
        for(auto &i:data)std::copy(i.begin(),i.end(),std::back_inserter(r));
        return r;
    }
};


template<typename T>
std::vector<T> dijkstra(graph<T> &g,int s){
    using state = std::pair<T,int>;
    //priority_queue
    std::priority_queue<state,std::vector<state>,std::greater<state>> q;
    q.emplace((T)0,s);
    //data init
    std::vector<T> data(g.size(),std::numeric_limits<T>::max());
    data[s] = (T)0;
    //solve
    while(!q.empty()){
        state cur = q.top();q.pop();
        T c = cur.first; int pos = cur.second;
        if(data[pos] < c)continue;
        for(auto &e : g.data[pos]){
            if(c + e.c < data[e.t]){
                data[e.t] = c + e.c;
                q.emplace(c + e.c, e.t);
            }
        }
    }
    return data;
};
void YES(bool ok){
    cout << (ok ? "Yes" : "No") << endl;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    graph<ll> g(n);
    vector<Pll> vec;
    rep(i,m){
        ll a,b; cin >> a >> b;
        a--;b--;
        g.add_edge(a,b,1);
        g.add_edge(b,a,1);
        vec.emplace_back(a,b);
    }

    auto dij = dijkstra(g, 0);

    vector<ll> ans(n, -1);
    bool ok = true;
    rep(i,n){
        ok &= dij[i] != numeric_limits<ll>::max();
    }
    // rep(i,n){
    //     for(auto &e : g[i]){
    //         if(ans[e.f] != -1 && ans[e.t] == -1)continue;
    //         if(dij[e.f] + 1 == dij[e.t]){
    //             ans[e.t] = e.f + 1;
    //         }
    //         if(dij[e.t] + 1 == dij[e.f]){
    //             ans[e.f] = e.t + 1;
    //         }
    //     }
    // }

    YES(ok);
    if(ok){
        
        rep(i,m){
            auto [f, t] = vec[i];
            debug(f,t);
            if(ans[f] != -1 && ans[t] != -1)continue;
            if(dij[f] + 1 == dij[t]){
                ans[t] = f + 1;
                continue;
            }
            if(dij[t] + 1 == dij[f]){
                ans[f] = t + 1;
            }
        }
        reps(i,n-1){
            cout << ans[i] << "\n";
        }
    }
    
}