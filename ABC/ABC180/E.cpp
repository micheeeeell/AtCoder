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
    
    ll n; cin >> n;
    vector<tuple<ll, ll, ll>> v(n);
    for(auto &[x, y, z] : v){
        cin >> x >> y >> z;
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    rep(i,0,n)rep(j,i + 1,n){
        auto [lx, ly, lz] = v[i];
        auto [rx, ry, rz] = v[j];
        ll dist = abs(lx - rx) + abs(ly - ry);
        dp[i][j] = dist + max(0LL, rz - lz);
        dp[j][i] = dist + max(0LL, lz - rz);
    }

    rep(k,0,n)rep(i,0,n)rep(j,0,n){
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    }

    debug(dp);
    vector d(1LL << n, vector<ll>(n, INF));
    d[0][0] = 0;
    rep(i, 0, 1LL << n) {
        rep(j,0,n){
            if ((i >> j) & 1) continue;
            rep(k,0,n){
                chmin(d[i | (1LL << j)][j], d[i][k] + dp[k][j]);
            }
        }
    }
    debug(d);
    ll mask = (1LL << n) - 1;
    cout << d[mask][0] << endl;
}