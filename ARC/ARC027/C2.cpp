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

void print() {
    cout << endl;
}

// template <class Head, class... Tail>
// void print(Head&& head, Tail&&... tail) {
//     cout << head;
//     if (sizeof...(tail) != 0) cout << " ";
//     print(forward<Tail>(tail)...);
// }

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<T> &vec, ll k){
   ll n = vec.size();
   k = min(k, n);
   rep(i,k-1)cout << vec[i] << " ";
   cout << vec[k-1] << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template <class T>
void print(vector<vector<T>> &df, ll k) {
    for (auto& vec : df) {
        print(vec, k);
    }
}
template<class T, class U>
void print(pair<T,U> &p){
    print(p.first, p.second);
}


template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll x,y; cin >> x >> y;
    ll n; cin >> n;
    vector<ll> t(n), h(n);
    rep(i,n) cin >> t[i] >> h[i];

    vvvl dp(n+1, vvl(x+1, vl(x+y+10, -1)));
    // ll dp[n+1][x+1][x+y+10] = {};

    dp[0][0][0] = 0;
    rep(i,n){
        rrep(j,min(i+1, x)){
            rep(k, x+y+10){
                chmax(dp[i+1][j][k], dp[i][j][k]);
                if(k >= t[i] && dp[i][j][k - t[i]] != -1){
                    chmax(dp[i+1][j+1][k], dp[i][j][k - t[i]] + h[i]);
                }
            }
        }

        print(dp[i+1], 10);print();
    }

    ll ans = 0;
    rep(i,n+1)rep(j,x+1)rep(k,x+y+1)chmax(ans, dp[i][j][k]);

    cout << ans << endl;
}