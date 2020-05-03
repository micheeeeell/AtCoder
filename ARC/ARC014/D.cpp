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
    
    ll a,n,m; cin >> a >> n >> m;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];
    vector<ll> med(n-1);
    rep(i,n-1)med[i] = l[i+1] - l[i] - 1;
    sort(all(med));
    vector<ll> sum(n);
    rep(i,n-1)sum[i+1] = sum[i] + med[i];

    rep(q,m){
        ll x,y; cin >> x >> y;
        ll id = upper_bound(all(med), x + y) - med.begin();
        ll ans = sum[id] - sum[0];
        ans += (n - id - 1) * (x + y);
        ans += n;
        // debug(ans);
        ans += min(l[0] - 1, x);
        // debug(ans);
        ans += min(a - l[n-1], y);
        // debug(ans);
        // debug(id);
        cout << ans << "\n";
    }

}