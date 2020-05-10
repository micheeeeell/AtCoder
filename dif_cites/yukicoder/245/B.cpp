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
    
    ll q; cin >> q;
    rep(_, q){
        ll n,i,j; cin >> n >> i >> j;
        ll mi = min({i,j,n-i-1, n-j-1});
        ll top = (n-1 + n - 1 - 2 * (mi-1)) * mi * 2;
        ll ans = top;
        if(i == mi)top += (j - mi);
        else if(n-j-1 == mi)top += j - mi + i - mi; 
        else if(n-i-1 == mi)top += 2 * (i - mi) + n-mi-1-j;
        else top += 3 * (n - 2 * mi - 1) + n-mi-1-i;
        cout << top << "\n";
    }
}