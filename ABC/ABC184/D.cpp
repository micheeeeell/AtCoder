#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,s,t) for(ll i = (ll)(s); i < (ll)(t); i++)
#define rrep(i,s,t) for(ll i = (ll)(s-1);(ll)(t) <= i; i--)
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
const long double pi = 3.14159265358979323846;
const long double eps = 1e-12;

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';}
string to_string(const char *c) {return to_string((string) c);}
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
    ll a,b,c; cin >> a >> b >> c;
    vector<vector<vector<ld>>> 
        dp(102, vector<vector<ld>>(102, vector<ld>(102)));
    dp[a][b][c] = 1;
    rep(i, a, 100) {
        rep(j, b, 100){
            rep(k, c, 100){
                if(i)dp[i + 1][j][k] += (dp[i][j][k]) * (i) / ld(i + j + k);
                if(j)dp[i][j + 1][k] += (dp[i][j][k]) * (j) / ld(i + j + k);
                if(k)dp[i][j][k + 1] += (dp[i][j][k]) * (k) / ld(i + j + k);
            }
        }
    }

    ld ans = 0;
    rep(i,0,100)rep(j,0,100){
        ans += dp[i][j][100] * (i - a + j - b + 100 - c);
        ans += dp[i][100][j] * (i - a + j - c + 100 - b);
        ans += dp[100][i][j] *(100 - a + i - b + j - c);
    }

    cout << fixed << setprecision(15);
    cout << ans << endl;
}