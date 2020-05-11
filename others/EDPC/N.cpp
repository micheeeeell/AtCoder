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
const int n_max = 440;
#define int ll

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

vector<ll> a(n_max);
vector<vector<ll>> memo(n_max, vector<ll>(n_max));
ll dfs(ll left, ll right){
    if(memo[left][right])return memo[left][right];
    if(right == left + 1)return 0;
    ll sum = 0;
    ll ans = INF;
    for(ll i = left; i < right; i++)sum += a[i];
    for(ll i = left + 1; i < right; i++){
        chmin(ans, dfs(left, i) + dfs(i, right) + sum);
    }

    return memo[left][right] = ans;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    rep(i,n) cin >> a[i];

    cout << dfs(0, n) << endl;
}