// #define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
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
#define int ll

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,c; cin >> n >> c;
    vector<vector<ll>> graph(c, vector<ll>(1, -1));
    auto com = [](int x){
        return x * (x - 1) / 2;
    };
    rep(i,n){
        ll a; cin >> a;
        a--;
        graph[a].emplace_back(i);
    }
    rep(i,c)graph[i].emplace_back(n);
    ll all = com(n+1);
    rep(i,c){
        ll t = graph[i].size();
        ll temp = all;
        reps(j, t-1){
            temp -= com(graph[i][j] - graph[i][j-1]);
        }
        cout << temp << "\n";
    }
    return 0;
}