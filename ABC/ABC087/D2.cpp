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
#define eb emplace_back
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;


ll n = 1e5+10,m = 2e5+10;
ll INF = INT_MAX;
vector<ll> place(n,INF), is_move(n,0);

template<class T>
bool dfs(vector<vector<Pll>> &graph, T now, T mi = 0, T ma = 0){
    bool ok = true;
    is_move[now] = 1;
    for(auto i : graph[now]){
        ll to = i.first, dis = i.second;
        if(!is_move[to]){
            place[to] = place[now] + dis;
            ma = max(ma,place[to]);
            mi = min(mi,place[to]);
            ok &= dfs(graph, to, mi, ma);
        }
        else{
            if(place[to] != place[now] + dis)ok = false;
        }
    }
    return ok & ((ma-mi) < 1e9);
}

int main(){
    cin >> n >> m;
    vector<ll> l(m), r(m), d(m);
    vector<vector<Pll>> graph(n);
    rep(i,m){
        cin >> l[i] >> r[i] >> d[i];
        l[i]--;r[i]--;
        graph[l[i]].emplace_back(Pll(r[i],d[i]));
        graph[r[i]].emplace_back(Pll(l[i],-d[i]));
    }
    bool res = true;
    rep(i,n){
        if(!is_move[i]){
            place[i] = 0;
            res &= dfs(graph,ll(i));
        }
    }
    cout << (res ? "Yes" : "No") << endl;
}
