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
    ll n; cin >> n;
    using Pld = pair<double, double>;
    vector<Pld> a(n), b(n);
    Pld c1 = {0, 0}, c2 = {0, 0};
    rep(i,n){
        ld x,y; cin >> x >> y;
        a[i] = {x, y};
        c1.first += x;
        c1.second += y;
    }
    rep(i,n){
        ld x, y; cin >> x >> y;
        b[i] = {x, y};
        c2.first += x;
        c2.second += y;
    }
    c1.first /= ld(n);
    c1.second /= ld(n);
    c2.first /= ld(n);
    c2.second /= ld(n);

    ld dist1 = 0, dist2 = 0;
    rep(i,n){
        dist1 += hypot(a[i].first - c1.first, a[i].second - c1.second);
        dist2 += hypot(b[i].first - c2.first, b[i].second - c2.second);
    }

    cout << fixed << setprecision(15);
    cout << dist2 / dist1 << endl;
}