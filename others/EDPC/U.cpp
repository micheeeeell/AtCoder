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
const int n_max = 17;
#define int ll
#define bit(n,k) ((n >> k) & 1)
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

vector<vector<ll>> a(n_max, vector<ll>(n_max));
vector<ll> dp((1LL << n_max)), flag((1LL << n_max));
ll dfs(ll mask){
    // ll mask = 0;
    // for(auto &i : vec)mask |= (1LL << i);
    // debug(mask);
    if(flag[mask])return dp[mask];

    // ll n = vec.size();
    if(__builtin_popcountll(mask) == 1){
        flag[mask] = 1;
        return dp[mask] = 0;
    }
    ll ans = 0;
    rep(i,n_max){
        for(int j = i+1; j < n_max; j++)if(bit(mask,i) && bit(mask,j))ans += a[i][j];
    }
    // ans /= 2;

    for(ll i=mask; i >= 0; i = (i-1) & mask){
        if(i == mask || i == 0)continue;
        chmax(ans, dfs(i) + dfs(i ^ mask));
    }
    flag[mask] = 1;
    return dp[mask] = ans;
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    rep(i,n)rep(j,n)cin >> a[i][j];
    // vector<ll> vec(n);
    // std::iota(all(vec), 0);
    ll mask = (1LL << n) - 1;
    cout << dfs(mask) << endl;
}