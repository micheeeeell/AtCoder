#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
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
const int n_max = 1e5+10;

template<class T>
void chmin(T &a, T &b){
    if(a > b)a = b;
}

class edge {
    public:
    edge(){};
    edge(ll f, ll t, ll c):f(f), t(t), c(c)
    {};
    ll f;
    ll t;
    ll c;
};

int main(){
    ll n,m; cin >> n >> m;
    vvl gr(n, vector<ll>(n,INF));
    vector<edge> edg(m);
    rep(i,m){
        ll a,b,c; cin >> a >> b >> c;
        a--;b--;
        gr[a][b] = gr[b][a] = c;
        edg[i] = edge(a,b,c);
    }
    rep(i,n)gr[i][i] = 0;
    rep(k,n)rep(i,n)rep(j,n){
        // chmin(gr[i][j], gr[i][k] + gr[k][j]);
        gr[i][j] = min(gr[i][j], gr[i][k] + gr[k][j]);
    }

    ll res = 0;
    rep(i,m){
        edge t = edg[i];
        if(gr[t.f][t.t] < t.c)res++;
    }
    cout << res << endl;
}