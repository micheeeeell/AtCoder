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
    ll n,k; cin >> n >> k;
    string s;cin >> s;
    // R = 0, P = 1, S = 2
    auto bt = [](ll a, ll b){
        if(a == b)return a;
        if(a > b)swap(a, b);
        if(a == 0){
            if(b == 1)return b;
            else
                return a;
        }
        else if(a == 1){
            return b;
        }
    };
    vector<ll> modn(k);
    modn[0] = 1;
    rep(i, 1, k) modn[i] = modn[i - 1] * 2 % n;
    debug(modn);

    vector dp(n, vector<ll>(k + 1));
    rep(i,0,n){
        ll t = 0;
        if(s[i] == 'P')t = 1;
        else if(s[i] == 'S')
            t = 2;
        dp[i][0] = t;
    }

    rep(j, 0, k) rep(i, 0, n)
    {
        debug(i, j, dp[i][j], dp[(i + modn[j]) % n][j]);
        dp[i][j + 1] = bt(dp[i][j], dp[(i + modn[j]) % n][j]);
    }
    debug(dp);

    string ans;
    if(dp[0][k] == 0)ans = "R";
    else if(dp[0][k] == 1)ans = "P";
    else ans = "S";

    cout << ans << endl;
}