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

// vector<ll> res;
template<typename T>
vector<T> min_root(graph<T> &gr, int pos, int g, vector<T> data){
    vector<T> res;
    // res.push_back(g);
    if(pos == g){
        // vector<T> res;
        res.push_back(g);
        return res;
    }
    for(auto &e : gr.data[pos]){
        if(data[e.f] - data[e.t] == e.c){
            res = min_root(gr, e.t, g, data);
            res.push_back(pos);
        }
    }
    return res;
}

int main(){
    ll n,m; cin >> n >> m;
    ll l; cin >> l;
    graph<ll> gr(n);
    ll cost[n][n] = {};
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        a--;b--;
        if(c > l)continue;
        gr.add_edge(a,b,c);
        gr.add_edge(b,a,c);
        cost[a][b] = c;
        cost[b][a] = c;
    }
    ll q; cin >> q;
    vector<P> st(q);
    rep(i,q){
        ll s,t; cin >> s >> t;
        s--;t--;
        st[i] = P(s,t);
    }
    bool ok = true;
    vector<ll> ans;
    rep(i,q){
        vector<ll> data = dijkstra(gr, st[i].first);
        // print(data);
        if(data[st[i].second] == LLONG_MAX)ok = false;
        // res.clear();
        if(ok){
            vector<ll> res = min_root(gr,st[i].second, st[i].first,data);
            // reverse(res.begin(), res.end());
            // print("res", st[i].first, st[i].second);
            // print(res);
            int temp = 0;
            ll l_temp = l;
            rep(i,res.size()-1){
                if(cost[res[i]][res[i+1]] > l_temp){
                    temp++;
                    l_temp = l;
                }
                l_temp -= cost[res[i]][res[i+1]];
                if(l_temp < 0){
                    ok = false;
                    break;
                }
            }
            if(ok)ans.push_back(temp);
        }
        if(!ok)ans.push_back(-1);
    }

    // print(ans);
    for(auto i : ans){
        cout << i << endl;
    }
    return 0;
}