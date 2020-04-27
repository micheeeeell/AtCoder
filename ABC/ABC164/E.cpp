#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;
#define int ll
void print() {
    cout << endl;
}

// template <class Head, class... Tail>
// void print(Head&& head, Tail&&... tail) {
//     cout << head;
//     if (sizeof...(tail) != 0) cout << " ";
//     print(forward<Tail>(tail)...);
// }

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

// template <class T>
// void print(vector<T> &vec, ll k){
//    ll n = vec.size();
//    k = min(k, n);
//    rep(i,k-1)cout << vec[i] << " ";
//    cout << vec[k-1] << endl;
// }

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

// template<class T, class U>
// void print(pair<T,U> &p){
//     print(p.first, p.second);
// }

template<typename T>
struct edge{
    int f,t;
    T c;
    int d;
    edge(){};
    edge(int f,int t,T c,int d = 0):f(f),t(t),c(c),d(d){};
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
    void add_edge(int f,int t,T c, int d){
        data[f].emplace_back(f,t,c,d);
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
vector<ll> c(n_max), d(n_max);
struct state{
    ll c, id, d;
    state(){};
    state(ll c, ll id, ll d):c(c), id(id), d(d){};
    bool operator<(const state rhs) const {
        return c < rhs.c;
    };
    bool operator>(const state rhs) const {
        return c > rhs.c;
    };
};
template<typename T>
std::vector<T> dijkstra(graph<T> &g,int s, vector<ll> &coin){
    // using state = std::pair<T,int>;
    //priority_queue
    std::priority_queue<state,std::vector<state>,std::greater<state>> q;
    q.emplace((T)0,s, 0);
    //data init
    std::vector<T> data(g.size(),std::numeric_limits<T>::max());
    data[s] = (T)0;
    coin[s] = 0;
    //solve
    while(!q.empty()){
        state cur = q.top();q.pop();
        T c = cur.c; int pos = cur.id; ll d = cur.d;
        if(data[pos] < c)continue;
        for(auto &e : g.data[pos]){
            if(c + e.c < data[e.t]){
                data[e.t] = c + e.c;
                coin[e.t] = d + e.d;
                q.emplace(c + e.c, e.t, d + e.d);
            }
        }
    }
    return data;
};


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m,s; cin >> n >> m >> s;
    graph<ll> g(n);
    rep(i,m){
        ll u,v; cin >> u >> v;
        u--;v--;
        ll d,c; cin >> d >> c;
        g.add_edge(u,v,c,d);
        g.add_edge(v,u,c,d);
    }

    rep(i,n) cin >> c[i] >> d[i];
    vector coin(n, vector<ll>(n, 0LL));
    vector<vector<ll>> dij(n);
    rep(i,n){
        dij[i] = dijkstra(g, i, coin[i]);
    }
    print(dij);
    print(coin);

    vector dp(n, vector(n, vector(n, 0LL)));
    
}