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
const int n_max = 61;

int main(){
    ll n,k; cin >> n >> k;
    vector<double> x(n), y(n), c(n);
    rep(i,n) cin >> x[i] >> y[i] >> c[i];
    auto dis = [&](ll i, ll j){
        return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    };

    auto check = [&](double time){
        vector<double> r(n);
        rep(i,n){
            r[i] = time / c[i];
        }
        vector<bitset<n_max>> graph(n, 0);
        rep(i,n)rep(j,n){
            if(i < j)continue;
            if(dis(i, j) < r[i] + r[j]){
                graph[i][j] = graph[j][i] = 1;
            }
        }
        // 要素数kの頂点集合Sをとった時に，Sが完全グラフとなるような要素の取り方ができればOK
        vector<ll> S(n), T, clear;
        iota(all(S), 0);
        while(S != T){
            T = S;
            S = clear;
            for(auto i : T){
                ll cnt = 0;
                for(auto j : T)cnt += graph[i][j]; 
                if(cnt >= k)S.emplace_back(i);
            }
        }
        if(S.size() >= k)return true;
        else return false;
    };
    double ok = 1e9;
    double ng = 0;
    rep(i, 100) {
        double time = (ok + ng) / 2.0;
        if(check(time))ok = time;
        else ng = time;
    }

    cout << fixed << setprecision(15);
    cout << ok << endl;
}