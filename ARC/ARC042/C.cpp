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
void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,p; cin >> n >> p;
    vector<Pll> a(n);
    rep(i,n)cin >> a[i].first >> a[i].second;
    // vector<vector<ll>> dp(n+1, vector<ll>(p+1, 0));
    vector<ll> dp(p+1);
    // dp[0][0] = 0;
    sort(all(a), greater<Pll>());
    // rep(i,n){
    //     rep(j,p+1){
    //         chmax(dp[i+1][j], dp[i][j]);
    //         if(j - a[i].first>= 0)chmax(dp[i+1][j], dp[i][j - a[i].first] + a[i].second);
    //     }
    // }
    // // print(dp);print();
    // ll ans = 0;
    // rep(i,n){
    //     chmax(ans, dp[i][p] + a[i].second);
    // }
    ll ans = 0;
    rep(i,n){
        chmax(ans, dp[p] + a[i].second);
        rrep(j,p + 1){
            if(j - a[i].first >= 0)chmax(dp[j], dp[j - a[i].first] + a[i].second);
        }
    }

    cout << ans << endl;
}