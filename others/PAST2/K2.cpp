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
    string s;cin >> s;
    vector<ll> c(n);
    rep(i,n) cin >> c[i];
    vector<ll> d(n);
    rep(i,n) cin >> d[i];
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, INF));
    dp[0][0] = 0;
    rep(i,n){
        rep(j,n){
            if(s[i] == '('){
                chmin(dp[i+1][j+1], dp[i][j]);
                chmin(dp[i+1][j], dp[i][j] + d[i]);
                if(j > 0)chmin(dp[i+1][j-1], dp[i][j] + c[i]);
            }
            else{
                if(j > 0)chmin(dp[i+1][j-1], dp[i][j]);
                chmin(dp[i+1][j], dp[i][j] + d[i]);
                chmin(dp[i+1][j+1], dp[i][j] + c[i]);
            }
        }
    }

    cout << dp[n][0] << endl;
}