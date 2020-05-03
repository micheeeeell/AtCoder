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

template<class T, class U>
void print(pair<T,U> &p){
    cout << p.first << " " << p.second << "\n";
}

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s, t;cin >> s >> t;
    ll ns, nt;
    ns = s.size();
    nt = t.size();
    debug(ns);debug(nt);
    vector<vector<ll>> dp(ns+1, vector<ll>(nt+1));

    rep(i,ns)rep(j,nt){
        if(s[i] == t[j]){
            chmax(dp[i+1][j+1], dp[i][j] + 1);
        }
        chmax(dp[i+1][j+1], max(dp[i+1][j], dp[i][j+1]));
    }
    // print(dp);

    string ans;
    ll x = ns, y = nt;
    ll temp = dp[ns][nt];
    while(temp){
        // debug(x);debug(y);
        if(dp[x][y] == dp[x-1][y]){
            x--;
            continue;
        }
        if(dp[x][y] == dp[x][y-1]){
            y--;
            continue;
        }
        ans += s[x-1];
        temp--;
        x--;y--;
    }
    reverse(all(ans));
    cout << ans << endl;
}