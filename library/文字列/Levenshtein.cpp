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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}


ll levenshtein(string &s, string &t){
    ll n = s.size(), m = t.size();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));
    rep(i,n+1)dp[i][0] = i;
    rep(i,m+1)dp[0][i] = i;
    rep(i,n){
        rep(j,m){
            if(s[i] == t[i])chmin(dp[i+1][j+1], dp[i][j]);
            else{
                chmin(dp[i+1][j+1], dp[i][j] + 1);
            }
            chmin(dp[i+1][j+1], dp[i+1][j] + 1);
            chmin(dp[i+1][j+1], dp[i][j+1] + 1);
        }
    }

    return dp[n][m];
}

// 削除のみで二つの文字列を合わせるときの操作回数
// よく考えると最長共通部分文字列の長さを計算して引き算でもいい
ll only_delete(string &s, string &t){
    ll n = s.size(), m = t.size();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, INF));
    rep(i,n+1)dp[i][0] = i;
    rep(i,m+1)dp[0][i] = i;
    rep(i,n){
        rep(j,m){
            if(s[i] == t[j])chmin(dp[i+1][j+1], dp[i][j]);
            else{
                chmin(dp[i+1][j+1], dp[i][j] + 2);
            }
            chmin(dp[i+1][j+1], dp[i][j+1] + 1);
            chmin(dp[i+1][j+1], dp[i+1][j] + 1);
        }
    }
    // print(dp);
    return dp[n][m];
}

// 最長共通部分文字列
ll max_common(string &s, string &t){
    ll n = s.size(), m = t.size();
    vector<vector<ll>> dp(n+1, vector<ll>(m+1));
    rep(i,n)rep(j,m){
        if(s[i] == t[j])chmax(dp[i+1][j+1], dp[i][j] + 1);
        chmax(dp[i+1][j+1], dp[i][j+1]);
        chmax(dp[i+1][j+1], dp[i+1][j]);
    }
    print(dp);
    return dp[n][m];
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;cin >> s;
    string t;cin >> t;

    ll tmp = max_common(s, t);
}