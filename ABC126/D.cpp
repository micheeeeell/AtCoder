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
        data[t].emplace_back(t,f,c);
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
// const int n = 1e5+10;
int is_moved[n_max] = {};
int res[n_max] = {};
template<typename T>
void dfs(graph<T> &g, int pos){
    is_moved[pos] = 1;
    for(auto i : g.data[pos]){
        if(!is_moved[i.t]){
            if(i.c%2 == 0)res[i.t] = res[i.f];
            else if(res[i.f] == 0)res[i.t] = 1;
            else res[i.t] = 0;
            dfs(g, i.t);
        }
    }
}

template<typename T>
void reach(graph<T> &g, int pos){
    is_moved[pos] = 1;
    for(auto i : g.data[pos]){
        if(!is_moved[i.t]){
            reach(g, i.t);
        }
    }
}


int main(){
    int n; cin >> n;
    graph<int> gr(n);
    rep(i,n-1){
        int from,to,cost;cin >> from >> to >> cost;
        from--;to--;
        gr.add_edge(from, to, cost);
    }
    dfs(gr, 0);
    rep(i,n) cout << res[i] << "\n";
    return 0;
}