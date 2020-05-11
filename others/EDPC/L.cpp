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
const int n_max = 3e3+10;
#define int ll

vector<ll> a(n_max);
vector<vector<ll>> memo(n_max, vector<ll>(n_max));
ll dfs(ll left, ll right, ll turn = 0){
    if(memo[left][right])return memo[left][right];
    if(left == right)return 0;
    ll ans;
    if(turn & 1){
        ans = min(dfs(left+1, right, turn + 1) - a[left], dfs(left, right-1, turn + 1) - a[right-1]);
    }
    else{
        ans = max(dfs(left+1, right, turn + 1) + a[left], dfs(left, right-1, turn + 1) + a[right-1]);
    }

    return memo[left][right] = ans;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;

    rep(i,n) cin >> a[i];

    cout << dfs(0, n, 0) << endl;
}