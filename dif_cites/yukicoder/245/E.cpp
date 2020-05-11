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
    
    ll n,V,l; cin >> n >> V >> l;
    vector<ll> x(n+1), v(n), w(n);
    x[0] = 0;
    rep(i,n){
        cin >> x[i+1] >> v[i] >> w[i];
    }
    vector<vector<ll>> dp(n+10, vector<ll>(V+10, INF));
    rep(i,V+1)dp[0][i] = 0;
    rep(i,n){
        rrep(j,V+1){
            if(j + x[i+1] - x[i] < V+1)chmin(dp[i+1][j], dp[i][j + x[i+1] - x[i]]);
        }
        rrep(j,V+1){
            chmin(dp[i+1][j], dp[i+1][max(0LL,j - v[i])] + w[i]);
            chmin(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    print(dp);
    if(l - x[n] > V){
        cout << -1 << endl;
        return 0;
    }
    cout << (dp[n][l-x[n]] == INF ? -1 : dp[n][l-x[n]]) << endl;
}