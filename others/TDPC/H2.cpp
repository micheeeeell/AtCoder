// #define LOCAL
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
constexpr ll n_max = 110;
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

const int c_max = 51;
const int w_max = 1e4+10;
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,w,c; cin >> n >> w >> c;
    vector<vector<Pll>> vec(c_max);
    rep(i,n){
        ll w,v,c; cin >> w >> v >> c;
        vec[--c].emplace_back(w, v);
    }

    vector<vector<ll>> dp(c+1, vector<ll>(w+1));
    rep(i,c_max){
        if(vec[i].empty())continue;
        vector<vector<ll>> dp2(c+1, vector<ll>(w+1));
        for(auto &p : vec[i]){
            rrep(j,c){
                rrep(k,w+1){
                    if(k >= p.first){
                        chmax(dp2[j+1][k], dp2[j+1][k - p.first] + p.second);
                        chmax(dp2[j+1][k], dp[j][k - p.first] + p.second);
                    }
                }
            }
        }

        debug(dp2);

        rep(i,c+1)rep(j,w+1)chmax(dp[i][j], dp2[i][j]);
    }

    debug(dp);

    cout << dp[c][w] << endl;
}