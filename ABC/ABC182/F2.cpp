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
    ll n,X; cin >> n >> X;
    vector<ll> a(n + 1, INF);
    for(int i = 0; i < n; i++) cin >> a[i];
    reverse(all(a));
    vector<ll> x(n + 1), m(n + 1);
    {
        ll T = X;
        rep(i,0,n + 1) {
            x[i] = T / a[i];
            T %= a[i];
            if (i) m[i] = a[i - 1] / a[i];
        }

        debug(x, m);
    }

    vector<ll> dp(2);
    dp[0] = 1;
    rep(i, 0, n){
        vector<ll> dp_(2);
        rep(j,0,2)rep(k,0,2){
            ll pre = X % a[i], nxt = X % a[i + 1];
            if (j) pre = pre - a[i];
            if (k) nxt = nxt - a[i + 1];
            ll num = abs(pre - nxt);
            if (num % a[i + 1] != 0) continue;
            if (num / a[i + 1] >= m[i + 1]) continue;
            debug(j, k, pre, nxt);
            dp_[k] += dp[j];
        }
        debug(i, dp, dp_);
        swap(dp, dp_);
    }

    cout << dp[0] << endl;
}