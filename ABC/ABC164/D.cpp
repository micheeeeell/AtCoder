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
    string s;cin >> s;
    ll n = s.size();
    const ll MOD = 2019;
    map<ll, ll> mp;
    reverse(all(s));
    ll ans = 0;
    ll sum = 0;
    vector<ll> dp(n+1);
    dp[0] = 1;
    mp[0] = 1;
    rep(i,n)dp[i+1] = dp[i] * 10 % MOD;
    rep(i,n){
        ll t = s[i] - '0';
        sum += dp[i] * t;
        sum %= MOD;
        ans += mp[sum];
        mp[sum]++;
        // debug(sum);
    }
    cout << ans << endl;
}