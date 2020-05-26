#define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
constexpr ll INF = numeric_limits<ll>::max()/4;
constexpr ll n_max = 2e5+10;
#define int ll

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';}
string to_string(const char c) {return to_string((string) &c);}
string to_string(bool b) {return (b ? "true" : "false");}
template <size_t N>
string to_string(bitset<N> v){
    string res = "";
    for(size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for(const auto &x : v) {
        if(!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p){return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}

void debug_out() {cerr << endl;}
template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,d; cin >> n >> d;
    vector<ll> v(6);
    for(int i = 2; i < 6; i++){
        while(d % i == 0){
            v[i]++;
            d /= i;
        }
    }
    if(d != 1){
        cout << 0 << endl;
        return 0;
    }
    using vld = vector< ld >;
    using vvld = vector< vld >;
    using vvvld = vector< vvld >;
    using vvvvld = vector< vvvld>;
    vvvvld dp(n+1, vvvld(v[2]+1, vvld(v[3]+1, vld(v[5]+1))));
    dp[0][0][0][0] = 1.0;
    rep(i,n){
        rrep(j, v[2]+1)rrep(k,v[3]+1)rrep(l,v[5]+1){
            if(dp[i][j][k][l] == 0.0)continue;
            dp[i+1][min(v[2], j + 1)][k][l] += dp[i][j][k][l] / 6.0;
            dp[i+1][min(v[2], j + 2)][k][l] += dp[i][j][k][l] / 6.0;
            dp[i+1][j][min(v[3], k + 1)][l] += dp[i][j][k][l] / 6.0;
            dp[i+1][j][k][min(v[5], l + 1)] += dp[i][j][k][l] / 6.0;
            dp[i+1][min(v[2], j + 1)][min(v[3], k + 1)][l] += dp[i][j][k][l] / 6.0;
            dp[i+1][j][k][l] += dp[i][j][k][l] / 6.0;
        }
    }

    cout << fixed << setprecision(10);

    cout << dp[n][v[2]][v[3]][v[5]] << endl;

}