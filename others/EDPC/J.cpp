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
const int n_max = 330;
#define int ll

ll n;
vector<vector<vector<double>>> memo(n_max, vector<vector<double>>(n_max, vector<double>(n_max)));
double dfs(ll c1, ll c2, ll c3){
    double i = n - c1 - c2 - c3;
    if(memo[c1][c2][c3])return memo[c1][c2][c3];
    if(i == n)return 0.0;
    double ans = double(n);
    if(c1 > 0)ans += dfs(c1-1, c2, c3) * c1;
    if(c2 > 0)ans += dfs(c1+1, c2-1, c3) * c2;
    if(c3 > 0)ans += dfs(c1, c2+1, c3-1) * c3;
    // debug(c1);debug(c2);debug(c3); debug(ans);debug(i);debug(n);
    return memo[c1][c2][c3] =  ans / double(n - i);
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> cnt(4);
    rep(i,n){
        cnt[a[i]]++;
    }

    // debug(dfs(2,0,0));

    cout << fixed << setprecision(15);
    cout << dfs(cnt[1], cnt[2], cnt[3]) << endl;
}