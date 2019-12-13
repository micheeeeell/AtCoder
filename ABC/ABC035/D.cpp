#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

//頂点fromから頂点toへのコストcostの辺
template<typename T>
struct edge{
    int f,t;
    T c;
    int id;
    edge(){};
    edge(int f,int t,T c,int id = 0):f(f),t(t),c(c),id(id){};
    bool operator< (const edge &s){
        return c < s.c;
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
    std::vector<edge<T>> make_edges(){
        std::vector<edge<T>> r;
        for(auto &i:data)std::copy(i.begin(),i.end(),std::back_inserter(r));
        return r;
    }
};

vector<int> is_moved(n_max,0);

template<typename T>
void reach(graph<T> &g, int pos){
    is_moved[pos] = 1;
    for(auto i : g.data[pos]){
        if(!is_moved[i.t]){
            reach(g, i.t);
        }
    }
}

template<typename T>
std::vector<T> bellmanford(graph<T> &g, int s){
    const T INF = std::numeric_limits<T>::max()/4;
    std::vector<T> data(g.size(),INF);
    data[s] = 0;
    for(int i=0;i<g.size()-1;i++){
        for(auto &v:g.data)for(auto &e:v){
            if(data[e.f]==INF)continue;
            data[e.t] = std::min(data[e.f] + e.c,data[e.t]);
        }
    }
    for(auto &v:g.data)for(auto &e:v){
        if(data[e.f]==INF)continue;
        if(data[e.f]==INT_MIN)continue;        
        if(data[e.f] + e.c < data[e.t]){
            // fill(data.begin(),data.end(),std::numeric_limits<T>::min());
            fill(is_moved.begin(),is_moved.end(),0);
            reach(g,e.f);
            for(T i = 0; i < g.data.size();i++){
                if(is_moved[i])data[i] = INT_MIN;
            }
            break;
        }
    }
    return data;
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

int main(){
    ll n,m,t; cin >> n >> m >> t;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    graph<ll> g(n), g_rev(n);
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        a--;b--;
        g.add_edge(a,b,c);
        g_rev.add_edge(b,a,c);
    }
    vector<ll> dij = dijkstra(g, 0);
    vector<ll> dij_rev = dijkstra(g_rev, 0);
    ll res = 0;
    rep(i,n){
        ll temp = 0;
        if(dij[i] == LLONG_MAX || dij_rev[i] == LLONG_MAX)continue;
        ll time = t - (dij[i] + dij_rev[i]);
        if(time < 0)continue;
        temp = time * a[i];
        res = max(res, temp);
    }
    cout << res << endl;
}