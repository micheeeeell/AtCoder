#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
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

vector<ll> dis(n_max,INT_MAX);
template<typename T>
void dfs(graph<T> &graph, int x, ll dist = 0){
    dis[x] = dist;
    for(auto i : graph.data[x]){
        if(dis[i.t] == INT_MAX)dfs(graph, i.t, dist+i.c);
    }
}

int main(){
    ll n; cin >> n;
    graph<ll> gr(n);
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        ll c; cin >> c;
        a--;b--;
        gr.add_edge(a,b,c);
        gr.add_edge(b,a,c);
    }
    ll q,k; cin >> q >> k;
    k--;
    vector<ll> x(q), y(q);
    rep(i,q){
        cin >> x[i] >> y[i];
        x[i]--;y[i]--;
    }
    dfs(gr, k);
    rep(i,q){
        cout << dis[x[i]] + dis[y[i]] << "\n";
    }
    return 0;
}