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
    
    ll R,B; cin >> R >> B;
    ll x,y; cin >> x >> y;
    auto f = [&](int num) -> pair<ll, bool>{
        ll Rt = R, Bt = B;
        Rt -= x * num;
        Bt -= num;
        if(Rt < 0 || Bt < 0)return {-1, true};
        ll bnum = min(Bt / y, Rt);
        Rt -= bnum;
        Bt -= y * bnum;
        return {num + bnum, y <= Bt};
    };

    ll ok = R/x + 1;
    ll ng = 0;
    while(abs(ok - ng) > 1){
        ll num = (ok + ng) / 2;
        if(f(num).second)ok = num;
        else ng = num;
    }

    cout << f(ng).first << endl;
}