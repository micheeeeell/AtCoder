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
constexpr ll n_max = 1e3;
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
template <class T>
void print(vector<T> &vec, ll k){
    ll n = vec.size();
    k = min(k, n);
    rep(i,0,k-1)cerr << vec[i] << " ";
    cerr << vec[k-1] << endl;
}
template <class T>
void print(vector<vector<T>> &vec, ll k){
    ll n = vec[0].size();
    k = min(k, n);
    for(auto &i : vec)print(i, k);
}
vector<vector<ll>> graph(n_max);
vector<ld> sub(n_max);
vector<ll> flag(n_max);
void pre_dfs(ll now, ll par = -1){
    if(flag[now])return ;
    ld c = graph[now].size();
    // if(c == 0)return ;
    for(auto &to : graph[now]){
        pre_dfs(to, now);
        sub[now] += (sub[to] + 1.0) / c;
    }
    flag[now] = 1;
}

vector<ld> dp(n_max);
ld dfs(ll now, ll par = -1){
    if(flag[now])return dp[now];
    ld ans = sub[now];
    ld c = graph[now].size();
    if(c == 1){
        flag[now] = 1;
        return dp[now] = dfs(graph[now][0], now) + 1.0;
    }
    if(c == 0){
        flag[now] = 1;
        return 0;
    }
    ld sum = sub[now];
    ld sum2 = sub[now] * c / (c - 1.0);
    for(auto &to : graph[now]){
        ld t1, t2;
        t1 = sum2 - (sub[to] + 1.0) / (c - 1.0);
        t2 = sum - ((sub[to] + 1.0) / c) + (dfs(to, now) + 1.0) / c;
        chmin(ans, t1);
        chmin(ans, t2);
        debug(now, to, t1, t2, sum, sum2);
    }

    flag[now] = 1;
    return dp[now] = ans;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    rep(i,0,m) {
        ll s,t;cin >> s >> t;
        s--;t--;
        graph[s].emplace_back(t);
    }
    pre_dfs(0);
    print(sub, 10);
    fill(all(flag), 0);
    // double ans = dfs(0);
    double ans = INF;
    dp.resize(n);
    auto f = [&](ll i) -> void{
        ll c = graph[i].size();
        if(c == 0){
            return ;
        }
        if(c == 1){
            return ;
        }
        double temp = INF;
        ld sum = sub[now];
        ld sum2 = sub[now] * c / (c - 1.0);
        for(auto &to : graph[i]){
            chmin(temp, sum2 - (sub[to] + 1.0) / (c - 1.0));
            chmin(temp, sum - ((sub[to] + 1.0) / c) + (dp[to] + 1.0) / c);
        }
        dp[i] = temp;
        rrep(j, i, 0){
            
        }
    };

    print(dp, 10);
    cout << fixed << setprecision(15);
    cout << ans << endl;
}