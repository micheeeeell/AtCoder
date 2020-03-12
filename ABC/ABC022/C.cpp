#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n,m; cin >> n >> m;
    vector<vector<ll>> graph(n,vector<ll>(n,INF));
    vector<Pll> one;
    rep(i,n)graph[i][i] = 0;
    rep(i,m){
        ll f,t,c; cin >> f >> t >> c;
        f--;t--;
        if(f == 0){
            one.emplace_back(t, c);
            continue;
        }
        graph[f][t] = graph[t][f] = c;
    }
    rep(k,n)rep(i,n)rep(j,n){
        chmin(graph[i][j], graph[i][k] + graph[k][j]);
    }

    ll ans = INF;
    for(auto p : one)for(auto q : one){
        if(p == q)continue;
        chmin(ans, p.second + q.second + graph[p.first][q.first]);
    }

    cout << (ans != INF ? ans : -1) << endl;
}