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

int main(){
    ll n,m; cin >> n >> m;
    vector<vector<ll>> graph(n);
    rep(i,m) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    rep(i,n){
        queue<Pll> que;
        vector<ll> used(n,0);
        ll ans = 0;
        used[i] = 1;
        que.emplace(i,0);
        while(!que.empty()) {
            Pll p = que.front();que.pop();
            if(p.second == 2){
                ans++;
                continue;
            }
            for(auto to : graph[p.first]){
                if(used[to])continue;
                que.emplace(to, p.second + 1);
                used[to] = 1;
            }
        }

        cout << ans << "\n";
    }
}