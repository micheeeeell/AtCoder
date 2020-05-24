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

vector<vector<ll>> dp(101, vector<ll>(101));
ll ans = 0;
ll n, m;
ll dx[] = {0, -1, 0, -2, 0, -3};
ll dy[] = {-1, 0, -2, 0, -3, 0};

bool check(ll k, ll x,ll y){
    bool ok = true;
    rep(i, k * 2){
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
        ok &= dp[nx][ny] != k;
    }
    return ok;
}
void dfs(ll x, ll y){
    if(y >= m){
        y = 0;
        x++;
    }
    if(x >= n){
        ans++;
        return ;
    }

    reps(i,3){
        if(check(i, x, y)){
            dp[x][y] = i;
            dfs(x, y + 1);
            dp[x][y] = 0;
        }
    }
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;

    n = min(n, (n + 16) % 4 + 16);
    m = min(m, (m + 16) % 4 + 16);
    dfs(0,0);
    cout << ans << endl;
}