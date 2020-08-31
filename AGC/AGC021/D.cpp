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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;cin >> s;
    ll k; cin >> k;
    ll n = s.size();
    vector dp(n, vector(n+1, vector(k+1, 0LL)));

    auto dfs = [&](auto self, ll l, ll r, ll x){
        if(dp[l][r][x])return dp[l][r][x];
        if(r - l == 1){
            return dp[l][r][x] = 1;
        }
        if(r - l == 2){
            if(x){
                return dp[l][r][x] = 2;
            }
            else{
                return dp[l][r][x] = (s[l] == s[r-1] ? 2 : 1);
            }
        }
        ll res = 0;
        chmax(res, self(self, l, r-1, x));
        chmax(res, self(self, l+1, r, x));
        if(s[l] == s[r-1]) chmax(res, self(self, l+1, r-1, x) + 2);
        else{
            if(x)chmax(res, self(self, l+1, r-1, x-1) + 2);
        }

        return dp[l][r][x] = res;
    };

    cout << dfs(dfs, 0, n, k) << "\n";
}