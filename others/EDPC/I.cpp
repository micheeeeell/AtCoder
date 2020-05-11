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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ld> p(n);
    rep(i,n)cin >> p[i];
    vector<vector<ld>> dp(n+1, vector<ld>(n + 1));

    dp[0][0] = 1.0;
    rep(i,n)rep(j,i+1){
        dp[i+1][j] += (1.0 - p[i]) * dp[i][j];
        dp[i+1][j+1] += p[i] * dp[i][j];
    }

    ld ans = 0.0;
    rep(i,n+1){
        if(i * 2 <= n)continue;
        ans += dp[n][i];
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;
}