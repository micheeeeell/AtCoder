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
    rep(q,t){
        ll n,d; cin >> n >> d;
        map<ll, ll> cnt;
        ll max_ = 0;
        rep(i, n){
            ll x; cin >> x;
            chmax(max_, x);
            cnt[x]++;
        }
        ll ans = 5;
        bool three = false;
        ll cnt_max = 0;
        for(auto itr : cnt){
            chmax(cnt_max, itr.second);
            if(itr.first != max_ && itr.second == 2)three = true;
            if(cnt[itr.first * 2] >= 1)three = true;
        }
        // debug(cnt_max);
        if(cnt_max >= d){
            Case(q);
            cout << 0 << "\n";
            continue;
        }
        if(d == 2){
            Case(q);
            cout << 1 << "\n";
            continue;
        }
        if(d == 3){
            Case(q);
            if(three)cout << 1 << "\n";
            else cout << 2 << "\n";
            continue;
        }
        Case(q);
        cout << ans << "\n";
    }
}