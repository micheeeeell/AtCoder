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
const ll s_max = 2e4+10;
#define int ll
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
struct state{
    ll w, s, v;
    state(){}
};
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<state> v(n);
    rep(i,n){
        cin >> v[i].w >> v[i].s >> v[i].v;
    }
    sort(all(v), [&](const auto &a, const auto &b){
        return a.s + a.w < b.s + b.w;
    });
    // vector<vector<ll>> dp(n+1, vector<ll>(s_max));
    // rep(i,n){
    //     rep(j,s_max){
    //         chmax(dp[i+1][j], dp[i][j]);
    //         if(j - v[i].w >= 0 && v[i].s >= j - v[i].w){
    //             chmax(dp[i+1][j], dp[i][j - v[i].w] + v[i].v);
    //         }
    //     }
    // }
    vector<ll> dp(s_max);
    rep(i,n){
        state t = v[i];
        rrep(j,s_max){
            if(j - t.w >= 0 && t.s >= j - t.w){
                chmax(dp[j], dp[j-t.w] + t.v);
            }
        }
    }

    ll ans = 0;
    rep(j, s_max)chmax(ans, dp[j]);
    cout << ans << endl;
}