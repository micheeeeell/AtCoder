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

template<typename T>
struct edge{
    int to;
    T cost;
    edge(int to, T cost):to(to), cost(cost) {};
};
template< typename T >
T prim(vector< vector<edge<T>> > &g) {
  using Pi = pair< T, int >;
 
  T total = 0;
  vector< bool > used(g.size(), false);
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  que.emplace(0, 0);
  while(!que.empty()) {
    auto p = que.top();
    que.pop();
    if(used[p.second]) continue;
    used[p.second] = true;
    total += p.first;
    for(auto &e : g[p.second]) {
      que.emplace(e.cost, e.to);
    }
  }
  return total;
}

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> x(n+m),y(n+m),c(n+m);
    rep(i,n+m)cin >> x[i] >> y[i] >> c[i];
    vector<vector<edge<ld>> > g(n);
    rep(i,n)rep(j,n){
        if(i <= j)continue;
        ld cost;
        ll xt = x[i]-x[j], yt = y[i] - y[j];
        ld dis = sqrt(xt * xt + yt * yt);
        if(c[i] != c[j])cost = dis * 10;
        else cost = dis;
        g[i].emplace_back(edge<ld>(j,cost));
        g[j].emplace_back(edge<ld>(i,cost));
    }
    ld ans = numeric_limits<ld>::max()/2;
    // debug("test");
    rep(i,(1<<m)){
        vector<vector<edge<ld>>> temp = g;
        // debug(1);
        bitset<6> bs(i);
        rep(i,bs.count())temp.emplace_back(vector<edge<ld>>());
        ll cnt = 0;
        rep(j,m){
            if(bs[j]){
                rep(k,n){
                    ld cost;
                    ll xt = x[k]-x[j+n], yt = y[k] - y[j+n];
                    ld dis = sqrt(xt * xt + yt * yt);
                    if(c[k] != c[j+n])cost = dis * 10;
                    else cost = dis;
                    temp[k].emplace_back(edge<ld>(cnt+n,cost));
                    temp[cnt+n].emplace_back(edge<ld>(k,cost));
                }
                cnt++;
            }
        }
        // debug(2);
        ld t = prim(temp);
        chmin(ans, t);
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;
}