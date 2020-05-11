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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll x; cin >> x;
    auto c = [&](ll a,ll b){
        ll l = a - b;
        ll r = a*a*a*a + a*a*a*b + a*a*b*b + a*b*b*b + b*b*b*b;
        return l * r == x;
    };
    auto pow5 = [&](ll i){
        return i*i*i*i*i;
    };
    rep(i,2e3){
        ll temp = pow5(i) - x;
        ll ab = abs(temp);
        ll ok = 2e3, ng = 0;
        while(abs(ok - ng) > 1){
            ll b = (ok + ng) / 2;
            if(pow5(b) >= ab)ok = b;
            else ng = b;
        }
        if(pow5(ok) == ab){
            cout << i << " " << ok * (temp / ab) << endl;
            return 0;
        }
    }
}