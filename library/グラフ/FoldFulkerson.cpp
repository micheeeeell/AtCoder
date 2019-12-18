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

// Fold Fulkerson による最大フロー
// うしさんありがとうございます
// flow_tはflowのデータ型
template<typename flow_t>
struct FoldFulkerson {
    struct edge {
        int to;
        flow_t cap;
        int rev;
        bool isrev;
        int idx;
    };

    vector<vector<edge>> graph;
    vector<int> used;
    const flow_t INF;
    int timestamp;

    FoldFulkerson(int n) : INF(numeric_limits<flow_t>::max()), timestamp(0) {
        graph.resize(n);
        used.assign(n,-1);
    }

    void add_edge(int from, int to, flow_t cap, int idx = -1) {
        graph[from].emplace_back((edge) {to, cap, (int) graph[to].size(), false, idx});
        graph[to].emplace_back((edge) {from, 0, (int) graph[from].size(), true, idx});
    }

    flow_t dfs(int idx, const int t, flow_t flow) {
        if(idx == t) return flow;
        used[idx] = timestamp;
        for(auto &e : graph[idx]) {
            if(e.cap > 0 && used[e.to] != timestamp) {
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if(0 < d) {
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    flow_t max_flow(int s, int t) {
        flow_t flow = 0;
        for(flow_t f; (f = dfs(s,t,INF)) > 0; timestamp++) {
            flow += f;
        }
        return flow;
    }

    void output() {
        for(int i = 0; i < graph.size(); i++) {
            for(auto &e : graph[i]) {
                if(e.isrev) continue;
                auto &rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
            }
        }
    }
};

int main(){
    ll n,g,e; cin >> n >> g >> e;
    FoldFulkerson<int> ff(n+1);
    vector<ll> p(g);
    rep(i,g){cin >> p[i];}
    rep(i,e){
        ll a,b; cin >> a >> b;
        // a--;b--;
        ff.add_edge(a,b,1);
        ff.add_edge(b,a,1);
    }
    rep(i,g){
        ff.add_edge(p[i], n, 1);
    }
    cout << ff.max_flow(0,n) << endl;
}