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

void YES(const bool ok){
    cout << (ok ? "Takahashi" : "Aoki") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a,b; cin >> a >> b;
    if(a >= n){YES(true);return 0;}
    if(a == b){
        if(n % (a + 1) == 0)YES(false);
        else YES(true);
        return 0;
    }
    if(a > b)YES(true);
    if(a < b)YES(false);
    return 0;
}