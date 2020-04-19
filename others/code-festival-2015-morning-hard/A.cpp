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
const ll INF = numeric_limits<ll>::max();
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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = INF;
    ll sum = 0;
    reps(i,n-1){
        sum += a[i] * i;
        sum += i-1;
    }
    vector<ll> s(n+1);
    rep(i,n)s[i+1] = s[i] + a[i];
    // debug(sum);
    if(n % 2 == 1)chmin(ans, sum);
    rep(i,n-1){
        sum -= s[n] - s[i+1];
        sum -= n - 1 - (i+1);
        sum += i;
        sum += s[i+1] - s[0];
        // debug(sum);
        if(i % 2 == n % 2)chmin(ans, sum);
    }

    cout << ans << endl;
}