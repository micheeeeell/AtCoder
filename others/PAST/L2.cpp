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
    int from;
    T cost;
    edge(int to,int from, T cost):to(to),from(from), cost(cost) {};
};
// template< typename T >
// T prim(vector< vector<edge<T>> > &g) {
//   using Pi = pair< T, int >;
 
//   T total = 0;
//   vector< bool > used(g.size(), false);
//   priority_queue< Pi, vector< Pi >, greater< Pi > > que;
//   que.emplace(0, 0);
//   while(!que.empty()) {
//     auto p = que.top();
//     que.pop();
//     if(used[p.second]) continue;
//     used[p.second] = true;
//     total += p.first;
//     for(auto &e : g[p.second]) {
//       que.emplace(e.cost, e.to);
//     }
//   }
//   return total;
// }


struct UnionFind{
private:
    vector<int> par;
    vector<int> rank;
    vector<int> sz;

public:
    //n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n){
        par.resize(n,0);
        rank.resize(n,0);
        sz.resize(n,1);
        rep(i,n){
            par[i] = i;
        }
    }

    //木の根を求める
    int root(int x){
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    //xとyの属する集合を併合
    bool unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        else{
            par[y] = x;
            sz[x] += sz[y];
            if(rank[x] == rank[y]) rank[x]++;
        }
        return true;
    }

    //xとyが同じ集合に属するか否か
    bool same(int x, int y){
        return root(x) == root(y);
    }

    //xが属する集合のサイズを返す
    int size(int x){
        return sz[root(x)];
    }
};

template< typename T >
T kruskal(vector<edge< T >> &edges, int V) {
  sort(begin(edges), end(edges), [](const edge< T > &a, const edge< T > &b) {
    return (a.cost < b.cost);
  });
  UnionFind tree(V);
  T ret = 0;
  for(auto &e : edges) {
    if(tree.unite(e.from, e.to)) ret += e.cost;
  }
  return (ret);
};

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> x(n+m),y(n+m),c(n+m);
    rep(i,n+m)cin >> x[i] >> y[i] >> c[i];
    vector<edge<ld>> g;
    rep(i,n)rep(j,n){
        if(i <= j)continue;
        ld cost;
        ll xt = x[i]-x[j], yt = y[i] - y[j];
        ld dis = sqrt(xt * xt + yt * yt);
        if(c[i] != c[j])cost = dis * 10;
        else cost = dis;
        g.emplace_back(edge<ld>(i,j,cost));
        g.emplace_back(edge<ld>(j,i,cost));
    }
    ld ans = numeric_limits<ld>::max()/2;
    // debug("test");
    rep(i,(1<<m)){
        vector<edge<ld>> temp(g);
        // debug(1);
        ll cnt = 0;
        rep(j,m){
            if((i >> j) & 1){
                rep(k,n+j){
                    if(n <= k && (i >> (k-n) & 1) == 0)continue;
                    ld cost;
                    ll xt = x[k]-x[j+n], yt = y[k] - y[j+n];
                    ld dis = sqrt(xt * xt + yt * yt);
                    if(c[k] != c[j+n])cost = dis * 10;
                    else cost = dis;
                    temp.emplace_back(edge<ld>(j+n,k,cost));
                    temp.emplace_back(edge<ld>(k,j+n,cost));
                }
                cnt++;
            }
        }
        // debug(2);
        ld t = kruskal(temp, n+m);
        chmin(ans, t);
    }
    cout << fixed << setprecision(12);
    cout << ans << endl;
}