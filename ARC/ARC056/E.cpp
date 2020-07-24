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
ll n, k;
vector<ll> memo;

vector<ll> dp, flag;
ll dfs(ll mask){
    if(flag[mask])return dp[mask];
    if(mask == 0)return 0;
    ll res = k;
    for(ll t = mask;;t = ((t-1) & mask)){
        if(t == 0)break;
        if(t == mask)continue;
        chmax(res, k + dfs(t) - memo[mask] + memo[mask-t] + memo[t]);
    }
    flag[mask] = 1;
    return dp[mask] = res;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    vector w(n, vector(n, 0LL));
    rep(i,0,n)rep(j,0,n)cin >> w[i][j];
    memo.resize(1LL << n);dp.resize(1LL << n);flag.resize(1LL << n);
    rep(i,0,1LL << n){
        rep(j,0,n)rep(k,j,n){
            if(((i >> j) & 1) & ((i >> k) & 1)){
                memo[i] += w[j][k];
            }
        }
    }

    debug(memo);
    cout << dfs((1LL << n) - 1) << "\n";
}