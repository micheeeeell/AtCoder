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
    
    ll n,m; cin >> n >> m;
    vector<ll> x(m);
    rep(i,m) cin >> x[i];

    auto check = [&](ll time) {
        // 未整備の一番左
        ll left = 1;
        rep(i,m){
            if(left > x[i])chmax(left, x[i] + time + 1);
            else {
                if(x[i] - left > time)return false;
                ll l = max(0LL, time - (x[i] - left) * 2);
                // chmax(left, x[i] + l + 1);
                ll r = max(0LL, (time - x[i] + left) / 2);
                chmax(left, x[i] + max(l,r) + 1);
                // debug(i);debug(l);debug(r);
            }
            // debug(i);debug(left);
        }
        return left > n;
    };

    debug(check(0));

    ll ok = 3e9;
    ll ng = -1;
    while(abs(ok - ng) > 1) {
        ll time = (ok + ng) / 2;
        if(check(time))ok = time;
        else ng = time;
    }

    cout << ok << endl;
}