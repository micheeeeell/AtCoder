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

void Case(int x){
    cout << "Case #" << x + 1 << ": ";
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    rep(q, t){
        ll x,y; cin >> x >> y;
        string s;cin >> s;
        vector<Pll> v;
        rep(i,s.size()){
            v.emplace_back(x, y);
            if(s[i] == 'S')y--;
            if(s[i] == 'N')y++;
            if(s[i] == 'E')x++;
            if(s[i] == 'W')x--;
        }
        v.emplace_back(x, y);
        ll ans = INF;   
        rep(i, v.size()){
            ll x = v[i].first, y = v[i].second;
            if(abs(x) + abs(y) <= i){
                ans = i;
                break;
            }
        }

        Case(q);
        if(ans == INF)cout << "IMPOSSIBLE" << "\n";
        else cout << ans << endl;
    }
}