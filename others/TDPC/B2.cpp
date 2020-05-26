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
constexpr ll n_max = 2e3+10;
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

ll A, B;
vector<ll> a(n_max), b(n_max);
vector<vector<ll>> memo(n_max, vector<ll>(n_max));
ll dfs(ll turn, ll i, ll j){
    if(i == A && j == B)return 0;
    if(memo[i][j])return memo[i][j];
    // resはすぬけ君の得点　- すめけ君の得点
    ll res;
    // すめけ君の手番、小さくしたい
    if(turn & 1){
        res = INF;
        if(i + 1 <= A)chmin(res, dfs(turn+1, i+1, j) - a[i]);
        if(j + 1 <= B)chmin(res, dfs(turn+1, i, j+1) - b[j]);
    }
    else{
        res = -INF;
        if(i + 1 <= A)chmax(res, dfs(turn+1, i+1, j) + a[i]);
        if(j + 1 <= B)chmax(res, dfs(turn+1, i, j+1) + b[j]);
    }

    return memo[i][j] = res;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> A >> B;
    ll sum = 0;
    rep(i,A){
        cin >> a[i];
        sum += a[i];
    }
    rep(j,B){
        cin >> b[j];
        sum += b[j];
    }

    ll ans = dfs(0,0,0);
    ans = (sum + ans) / 2;

    cout << ans << endl;
}