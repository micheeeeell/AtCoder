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
    
    ll n,m,x; cin >> n >> m >> x;
    vector<ll> c(n);
    vvl a(n, vl(m));
    rep(i,n) {
        cin >> c[i];
        rep(j,m)cin >> a[i][j];
    }
    ll ans = INF;
    rep(i, 1LL << n){
        vector<ll> temp(m);
        ll sum = 0;
        rep(j,n){
            if((i >> j) & 1){
                rep(k,m)temp[k] += a[j][k];
                sum += c[j];
            }
        }
        bool ok = true;
        rep(k,m)ok &= temp[k] >= x;

        if(ok)chmin(ans, sum);
    }

    cout << (ans != INF ? ans : -1) << endl;
}