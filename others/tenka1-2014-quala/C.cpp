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
constexpr ll n_max = 15;
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

ll n, m;
vector<string> vec;
vector<ll> memo;
vector<vector<ll>> table(n_max, vector<ll>(n_max));
ll dfs(ll mask){
    if(memo[mask])return memo[mask];
    string s(m, '*');
    bool ok = true;
    rep(i,n)rep(j,n){
        if(i >= j)continue;
        if(((mask >> i) & 1) && ((mask >> j) & 1)){
            ok &= table[i][j];
        }
    }
    if(ok)return memo[mask] = 1;
    ll ans = INF;
    for(ll t = mask; t > 0; t = (t-1) & mask){
        if(t == mask)continue;
        chmin(ans, dfs(t) + dfs(mask ^ t));
    }

    return memo[mask] = ans;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    vec.resize(n);
    memo.resize(1LL << n);
    rep(i,n)cin >> vec[i];

    auto c = [&](string &s, string &t){
        rep(j,m){
            if(s[j] != '*' && t[j] != '*' && s[j] != t[j]) return false;           
        }

        return true;
    };

    rep(i,n)rep(j,n){
        if(i >= j)continue;
        table[i][j] = c(vec[i], vec[j]);
    }

    cout << dfs((1LL << n) - 1) << endl;
}