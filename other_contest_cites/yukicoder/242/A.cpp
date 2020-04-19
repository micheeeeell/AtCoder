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
void YES(bool ok){
    cout << (ok ? "Yes" : "No") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    ll x,y,z; cin >> x >> y >> z;   
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    bool ok = true;
    rep(i,n){
        ll num = min(x, a[i] / 1000 + 1);
        x -= num; 
        a[i] -= num * 1000;
        if(a[i] < 0)continue;
        num = min(y, a[i] / 5000 + 1);
        y -= num;
        a[i] -= num * 5000;
        if(a[i] < 0)continue;
        num = min(z, a[i] / 10000 + 1);
        z -= num;
        a[i] -= num * 10000;
        if(a[i] > 0)ok = false;
    }

    YES(ok);
}