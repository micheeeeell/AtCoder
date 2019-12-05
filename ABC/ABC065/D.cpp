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
const ll MOD = 1e9+7;
const ll INF = LLONG_MAX/4;
const int n_max = 1e5+10;

class node{
    public:
    node(){};
    node(ll id, ll x, ll y){
        m_id = id;
        m_x = x;
        m_y = y;
    }
    // private:
    ll m_id;
    ll m_x;
    ll m_y;
};

// node::node(ll id, ll x, ll y){
//     m_id = id;
//     m_x = x;
//     m_y = y;
// }

int main(){
    ll n; cin >> n;
    vector<node> xy(n);
    rep(i,n){
        ll x,y; cin >> x >> y;
        node t(i,x,y);
        xy[i] = t;
    }    
    vector<vector<Pll>> graph(n);
    sort(all(xy),
    [](const auto &a, const auto &b){
        return a.m_x < b.m_x;
    });
    rep(i,n-1){
        node from = xy[i];
        node to = xy[i+1];
        graph[from.m_id].emplace_back(Pll(to.m_id,to.m_x - from.m_x));
        graph[to.m_id].emplace_back(Pll(from.m_id,to.m_x - from.m_x));
    }
    sort(all(xy),
    [](const auto &a, const auto &b){
        return a.m_y < b.m_y;
    });
    rep(i,n-1){
        node from = xy[i];
        node to = xy[i+1];
        graph[from.m_id].emplace_back(Pll(to.m_id,to.m_y - from.m_y));
        graph[to.m_id].emplace_back(Pll(from.m_id,to.m_y - from.m_y));
    }

    // プリム法
    vector<ll> mincost(n,INF);
    bool used[n];
    fill(used, used + n, false);
    mincost[0] = 0;
    ll res = 0;
    ll cnt = 0;
    auto comp = [](Pll a, Pll b){
        return a.second > b.second;
    };
    priority_queue<Pll, vector<Pll>, decltype(comp)> pq(comp);
    pq.push(Pll(0,0));
    while(1){
        assert(cnt <= n);
        cnt++;
        ll v = -1;
        // rep(u,n){
        //     if(!used[u]){
        //         if(v == -1 || mincost[u] < mincost[v])v = u;
        //     }
        // }
        while(pq.size()){
            Pll temp = pq.top();pq.pop();
            if(!used[temp.first]){
                v = temp.first;
                break;
            }
        }
        debug(v);
        if(v == -1)break;
        used[v] = true;
        res += mincost[v];
        for(auto i : graph[v]){
            ll to = i.first;ll cost = i.second;
            // mincost[to] = min(mincost[to], cost);
            if(cost < mincost[to]){
                pq.push(Pll(to,cost));
                mincost[to] = cost;
            }
        }
    }

    cout << res << endl;
}