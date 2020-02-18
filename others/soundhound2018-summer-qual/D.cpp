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
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;

struct edge{
    edge(){};
    edge(ll f, ll t, ll c):f(f), t(t), c(c){};
    ll f, t, c;
};

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

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

template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}


int main(){
    ll n,m; cin >> n >> m;
    ll s,t; cin >> s >> t;
    s--;t--;
    vector<vector<edge>> snuke(n), yen(n);
    rep(i,m){
        ll u,v; cin >> u >> v;
        u--;v--;
        ll a,b; cin >> a >> b;
        snuke[u].emplace_back(edge(u,v,b));
        snuke[v].emplace_back(edge(v,u,b));
        yen[u].emplace_back(edge(u,v,a));
        yen[v].emplace_back(edge(v,u,a));
    }

    auto dijkstra = [&](ll s, ll t, vector<vector<edge>> &graph){
        vector<ll> res(n,INF);
        priority_queue<Pll, vector<Pll>, greater<Pll>> pq;
        pq.push(Pll(0,s));

        res[s] = 0;
        // bitset<n_max> bs(0);
        while(!pq.empty()) {
            Pll p = pq.top();pq.pop();
            if(res[p.second] < p.first)continue;
            for(auto &e : graph[p.second]){
                if(p.first + e.c < res[e.t]){
                    res[e.t] = p.first + e.c;
                    pq.push(Pll(e.c + p.first, e.t));
                }
            }
            // if(bs.count() == n)break;
        }

        return res;
    };

    vector<ll> snu_path = dijkstra(t,s, snuke), yen_path = dijkstra(s,t,yen);
    vector<ll> ans(n);

    // print(snu_path);
    // print(yen_path);
    ll snu = 1e15;
    ll pre = 0;
    for(int i = n-1; 0 <= i; i--){
        chmax(pre, snu - (snu_path[i] + yen_path[i]));
        ans[i] = pre;
    }

    for(auto i : ans)cout << i << "\n";
}