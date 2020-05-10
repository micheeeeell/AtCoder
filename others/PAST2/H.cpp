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
    ll n,m; cin >> n >> m;
    string s[n];
    rep(i,n)cin >> s[i];
    vector<vector<Pll>> graph(10);
    vvl dp(n, vector<ll>(m, INF));
    Pll g;
    rep(i,n)rep(j,m){
        if(s[i][j] == 'S'){
            graph[0].emplace_back(i,j);
            dp[i][j] = 0;
        }
        else if(s[i][j] == 'G'){
            g = {i,j};
        }
        else{
            graph[s[i][j] - '0'].emplace_back(i,j);
        }
    }
    
    rep(i,9){
        for(auto &p : graph[i+1]){
            for(auto &pre : graph[i]){
                chmin(dp[p.first][p.second], dp[pre.first][pre.second] + abs(p.first - pre.first) + abs(p.second - pre.second));
            }
        }
    }

    for(auto &p : graph[9]){
        chmin(dp[g.first][g.second], dp[p.first][p.second] + abs(p.first - g.first) + abs(p.second - g.second));
    }
    // print(dp);
    cout << (dp[g.first][g.second] == INF ? -1 : dp[g.first][g.second]) << endl;
}