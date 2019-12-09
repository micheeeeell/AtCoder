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

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}

int main(){
    ll n,m,p; cin >> n >> m >> p;
    graph<ll> g(n);
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        a--;b--;
        c -= p;
        g.add_edge(a,b,-c);
    }

    vector<ll> bell = bellmanford(g,0);

    ll res = bell[n-1];

    // print(bell);

    if(bell[n-1] == INT_MIN)res = 1;
    else if(bell[n-1] > 0)res = 0;
    cout << -res << endl;
}