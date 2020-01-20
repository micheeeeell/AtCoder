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

vector<ll> vec,clear, is_used(55,0);

bool dfs(vvl &graph, ll pos, ll ed){
    is_used[pos] = 1;
    if(pos == ed){
        vec.emplace_back(pos);
        return true;
    }
    for(auto to : graph[pos]){
        if(is_used[to] == 0){
            if(dfs(graph, to,ed)){
                vec.emplace_back(pos);
                return true;
            }
        }
    }
    return false;
}

int main(){
    ll n; cin >> n;
    vector<vector<ll>> graph(n);
    map<Pll,int> edges;
    rep(i,n-1) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        edges[Pll(a,b)] = i;
        edges[Pll(b,a)] = i;
    }
    ll m; cin >> m;
    vector<Pll> query(m);
    bitset<55> b[m];
    rep(i,m){
        ll u,v; cin >> u >> v;
        u--;v--;
        query[i] = {u,v};
        vec = clear;
        is_used.assign(55,0);
        dfs(graph, u,v);
        rep(j,vec.size()-1){
            b[i][edges[Pll(vec[j], vec[j+1])]] = 1;
        }
    }
    // dfs(graph, query[0].first, query[0].second);
    // print(vec);
    ll ans = 0;
    rep(i,(1LL<<m)){
        bitset<22> bs(i);
        bitset<55> t(0);
        rep(j,m){
            if(bs[j])t |= b[j];
        }
        if(bs.count() % 2){
            ans -= pow(2,n-1-t.count());
        }
        else{
            ans += pow(2,n-1-t.count());
        }
    }
    cout << ans << endl;
}