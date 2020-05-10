#define _GLIBCXX_DEBUG
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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector graph(n, vector<ll>(n));
    rep(i,n)rep(j,n) cin >> graph[i][j];
    vector num(n, vector<Pll>());
    vector<ll> ave(n, 0LL);
    rep(i,n)rep(j,n){
        num[--graph[i][j]].emplace_back(Pll(i, j));
        ave[graph[i][j]] += i;
    }
    rep(i,n)ave[i] /= n;

    vector ans(n, vector<ll>(n, INF));
    ll ret = 0;
    rep(i,n){
        ll ans = INF;
        for(int j = -40; j <= 40; j++){
            ll temp = 0;
            if(j + ave[i] < 0 || j + ave[i] > n)continue;
            for(auto &p : num[i])temp += max(p.second, abs(p.first - j - ave[i]));
            chmin(ans, temp);
        }
        ret += ans;
    }

    cout << ret << endl;
}