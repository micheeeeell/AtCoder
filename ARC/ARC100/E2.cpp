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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll N; cin >> N;
    ll n = 1LL << N;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<Pll> dp(n, {0,0});
    rep(i,n){
        dp[i] = {a[i], 0};
    }
    auto merge = [&](Pll &a, Pll &b) -> Pll{
        Pll ret;
        Pll temp = {a.first, b.first};
        ret.first = max(temp.first, temp.second);
        if(temp.first > temp.second)temp.first = a.second;
        else temp.second = b.second;
        ret.second = max(temp.first, temp.second);
        return ret;
    };

    rep(j, N){
        rep(i, n){
            if((i >> j) & 1){
                dp[i] = merge(dp[i], dp[i & ~(1LL << j)]);
            }
        }
    }

    vector<ll> ans(n);
    reps(i,n-1){
        chmax(ans[i], ans[i-1]);
        chmax(ans[i], dp[i].first + dp[i].second);
    }

    reps(i,n-1){
        cout << ans[i] << endl;
    }
}