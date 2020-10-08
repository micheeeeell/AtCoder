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
    ll h,w; cin >> h >> w;
    vector<string> c(h);
    rep(i,0,h){
        cin >> c[i];
    }

    auto calc = [&](ll a, ll b) {
        vector dp(h + 1, vector<ll>(h + 1, INF));
        vector cost(h + 1, vector<ll>(h + 1));
        rrep(i, h, 0)rrep(j,h,0){
            cost[i][j] =
                cost[i + 1][j + 1] + (c[h - i - 1][a] == c[h - j - 1][b]);
        }
        debug(a, b, cost);
        dp[0][1] = dp[1][0] = cost[0][0];
        rep(i, 0, h+1) rep(j, 0, h+1) {
            if (i) chmin(dp[i][j], dp[i - 1][j] + cost[i - 1][j]);
            if (j) chmin(dp[i][j], dp[i][j - 1] + cost[i][j - 1]);
        }
        debug(dp);
        return dp[h][h];
    };

    ll ans = 0;
    rep(i,0,w-1){
        ans += calc(i, i+1);
    }

    cout << ans << "\n";
}