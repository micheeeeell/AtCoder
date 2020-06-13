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

vector<ll> vec, is_used(n_max,0);
// 木の上で2頂点間のパス上にある頂点を求める（スタート，ゴールも入る）
bool dfs(vvl &graph, ll pos, ll ed){
    is_used[pos] = 1;
    if(pos == ed){
        vec.emplace_back(pos);
        return true;
    }
    for(auto to : graph[pos]){
        if(is_used[to] == 0){
            if(dfs(graph, to, ed)){
                vec.emplace_back(pos);
                return true;
            }
        }
    }
    return false;
}