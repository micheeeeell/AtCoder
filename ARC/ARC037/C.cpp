// #define _GLIBCXX_DEBUG
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
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> b(n);
    rep(i,n) cin >> b[i];
    sort(all(b));
    sort(all(a));

    auto check = [&](ll num){
        ll temp = 0;
        ll t, m;
        rep(i,n){
            t = num / a[i];
            m = upper_bound(all(b), t) - b.begin();
            if(m == 0)break;
            temp += m;
        }
        return k <= temp;
    };

    auto check2 = [&](ll num){
        ll temp = 0;
        ll ok, ng, id;
        rep(i,n){
            ok = -1, ng = n;
            while(abs(ok - ng) > 1){
                id = (ok + ng) / 2;
                if(b[id] * a[i] <= num)ok = id;
                else ng = id;
            }
            temp += ok + 1;
        }
        return k <= temp;
    };
    ll ok = 1e18;
    ll ng = 0;
    ll num;
    while(abs(ok - ng) > 1){
        num = (ok + ng) / 2;
        if(check2(num))ok = num;
        else ng = num;
    }

    cout << ok << endl;
}