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

struct state{
    ll l, r;
    state(){}
    state(ll l, ll r):l(l), r(r){};
};
void YES(bool ok){
    cout << (ok ? "Yes" : "No") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<state> v(n);
    ll lcnt = 0, rcnt = 0;
    bool one = false;
    rep(i,n){
        string s;cin >> s;
        ll temp = 0;
        state t(0, 0);
        for(auto &c : s){
            if(c == ')')temp--;
            else temp++;
            chmin(t.l, temp);
        }
        reverse(all(s));
        temp = 0;
        for(auto &c : s){
            if(c == '(')temp--;
            else temp++;
            chmin(t.r, temp);
        }
        t.r = abs(t.r);
        t.l = abs(t.l);
        if(t.l == 0)lcnt++;
        if(t.r == 0)rcnt++;
        if((t.l == 0 && t.r != 0) || (t.r == 0 && t.l != 0))one = true;
        v[i] = t;
        // debug(t.l);debug(t.r);
    }

    ll lsum = 0, rsum = 0;
    rep(i,n){
        lsum += v[i].l;
        rsum += v[i].r;
    }
    bool ok = false;
    if(lcnt >= 2 && rcnt >= 2)ok = true;
    if(lcnt >= 1 && rcnt >= 2)ok = true;
    if(lcnt >= 2 && rcnt >= 1)ok = true;
    if(lcnt >= 1 && rcnt >= 1 && n == 1)ok = true;
    if(lcnt >= 1 && rcnt >= 1 && one)ok = true;
    YES(lsum == rsum && ok);
}