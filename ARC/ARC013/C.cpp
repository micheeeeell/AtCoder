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
void YES(bool ok){
    cout << (ok ? "WIN" : "LOSE") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll nim = 0;
    rep(_,n){
        vector<ll> dim(3);
        rep(k,3) cin >> dim[k];

        ll m; cin >> m;
        vl min_(3, INF), max_(3,0);

        rep(j,m){
            vector<ll> v(3);
            rep(k,3) cin >> v[k];
            rep(k,3){
                chmin(min_[k], v[k]);
                chmax(max_[k], v[k]);
            }
        }
        rep(k,3){
            nim ^= min_[k];
            nim ^= dim[k] - max_[k] - 1;
        }
        
    }

    YES(nim != 0);
}