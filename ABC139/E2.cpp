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
const int n_max = 1e7+10;

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}


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

ll memo[n_max] = {};
template<typename T>
ll dfs(graph<T> &g, ll now, ll count = 1){
    // print(now, count, g.data[now].size());
    if(g.data[now].size() == 0)return count;
    if(memo[now])return memo[now];
    ll res = 0;
    for(auto i : g.data[now]){
        res = max(res, dfs(g, i.t, count + 1));
    }
    memo[now] = res;
    return res;
}

int main(){
    ll n; cin >> n;
    ll a[n][n-1];
    ll node[n][n];
    rep(i,n)fill(node[i], node[i] + n, -1);
    ll count = 0;
    rep(i,n)rep(j,n){
        if(i >= j)continue;
        node[i][j] = count;
        // print(i,j,count);
        count++;
    }

    assert(count == n * (n-1) / 2);
    graph<ll> gr(count);
    rep(i,n)rep(j,n-1){
        cin >> a[i][j];
        a[i][j]--;
    }

    ll in[count] = {};
    rep(i,n)rep(j,n-2){
        ll from = (i < a[i][j] ? node[i][a[i][j]] : node[a[i][j]][i]);
        ll to = (i < a[i][j+1] ? node[i][a[i][j+1]] : node[a[i][j+1]][i]);
        gr.add_edge(from, to, -1);
        // print(from, to);
        in[to]++;
    }

    vector<ll> start;
    rep(i,count)if(in[i] == 0)start.push_back(i);
    bool ok = true;
    if(start.size() == 0){
        cout << -1 << endl;
        return 0;
    }

    
    // for(auto i : start){
    //     // print(start);
    //     auto vec = bellmanford(gr, i);
    //     // print(vec);
    //     if(*min_element(vec.begin(), vec.end()) == INT_MIN)ok = false;  
    // }
    // if(!ok){
    //     cout << -1 << endl;
    //     return 0;
    // }
    
    ll res = 0;
    ll node_count = 0;
    // for(auto i : start){
    //     res = max(res, dfs(gr, i));
    // }
    node_count += start.size();
    while(start.size()){
        vector<ll> temp, clear;
        temp = start;
        start = clear;
        for(auto i : temp){
            for(auto j : gr.data[i]){
                in[j.t]--;
                if(in[j.t] == 0){
                    start.push_back(j.t);
                    node_count++;
                }
            }
        }
        // print(temp);y
        res++;
    }
    
    cout << (node_count == count ? res : -1) << endl;
    return 0;
}