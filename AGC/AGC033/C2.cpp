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
const ll MOD = 1e9+7;
const int n_max = 2e5+10;

vector<ll> depth(n_max,-1);

void dfs( vvl &graph, ll pos, ll pre){
    for(auto to : graph[pos]){
        if(to != pre){
            depth[to] = depth[pos] + 1;
            dfs(graph, to, pos);
        }
    }
}

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n; cin >> n;
    vector<vector<ll>> graph(n);
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    depth[0] = 0;
    dfs(graph, 0, -1);
    Pll m = {-1,-1};
    rep(i,n){
        chmax(m, {depth[i],i});
    }
    depth.assign(n,-1);
    depth[m.second] = 0;
    dfs(graph, m.second, -1);
    ll leng = 0;
    rep(i,n)chmax(leng, depth[i]);
    cout << (leng % 3 == 1 ? "Second" : "First") << endl;
}