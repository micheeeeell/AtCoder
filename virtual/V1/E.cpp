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
    ll h,w; cin >> h >> w;
    vvl c(h, vl(w)),sum1(h+1, vl(w+1)), sum2(h+1, vl(w+1));
    rep(i,h)rep(j,w)cin >> c[i][j];
    rep(i,h)rep(j,w){
        sum1[i+1][j+1] = sum1[i+1][j] + sum1[i][j+1] - sum1[i][j] + ((i + j) % 2 == 0 ? c[i][j] : 0);
        sum2[i+1][j+1] = sum2[i+1][j] + sum2[i][j+1] - sum2[i][j] + ((i + j) % 2 == 1 ? c[i][j] : 0);
    }
    ll t1, t2;
    ll ans = 0;
    reps(xe,h)reps(ye,w)rep(xs, xe)rep(ys,ye){
        t1 = sum1[xe][ye] - sum1[xe][ys] - sum1[xs][ye] + sum1[xs][ys];
        t2 = sum2[xe][ye] - sum2[xe][ys] - sum2[xs][ye] + sum2[xs][ys];
        if(t1 != t2)continue;
        chmax(ans, (xe- xs) * (ye - ys));
    }
    cout << ans << endl;
}