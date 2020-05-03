// #define _GLIBCXX_DEBUG
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

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i,k-1)cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    cout << p.first << " " << p.second << "\n";
}


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
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ifstream in("killer_01.in");
    cin.rdbuf(in.rdbuf());
    ofstream ofstr("out.txt");
    streambuf* strbuf;
    strbuf = std::cout.rdbuf( ofstr.rdbuf() );
    
    ll n,m; cin >> n >> m;
    graph<ll> g(n);
    rep(i,m){
        ll f,t; cin >> f >> t;
        f--;t--;
        g.add_edge(f, t, 1);
    }
    ll s,t; cin >> s >> t;
    s--;t--;
    vvl data(3, vl(n, INF));
    data[0][s] = 0;
    using state = pair<ll, Pll>;
    priority_queue<state, vector<state>, greater<state>> pq;
    pq.emplace(0, Pll(0,s));
    while(!pq.empty()){
        state t = pq.top();pq.pop();
        ll c = t.first;
        ll dim = t.second.first, pos = t.second.second;
        ll n_dim = (dim + 1) % 3;
        if(data[dim][pos] < c)continue;
        for(auto &e : g[pos]){
            if(data[n_dim][e.t] <= c + 1)continue;
            data[n_dim][e.t] = c + 1;
            pq.emplace(c + 1, Pll(n_dim, e.t));
        }
    }

    // print(data);
    cout << (data[0][t] == INF ? -1 : data[0][t] / 3) << endl;
}