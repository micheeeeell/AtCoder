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

using ll = long long;
constexpr ll M = 1e9 + 7;

signed main() {
    vector<vector<ll>> comb(512, vector<ll>(512));
    for(int i = 0; i < 512; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(i == j || j == 0) {
                comb[i][j] = 1;
            } else {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % M;
            }
        }
    }

    vector<int> x;
    vector<int> sum = {0};
    for(int i = 0; i < 26; ++i) {
        int f;
        cin >> f;
        if(f == 0) {
            continue;
        }
        x.push_back(f);
        sum.push_back(f + sum.back());
    }

    int const n = x.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(300));
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= sum[i]; ++j) {
            for(int k = 1; k <= x[i]; ++k) {
                for(int l = 0; l <= min(j, k); ++l) {
                    ll t = comb[x[i] - 1][k - 1];
                    t = (t * comb[j][l]) % M;
                    t = (t * comb[sum[i] - j + 1][k - l]) % M;
                    t = (t * dp[i][j]) % M;
                    debug(i, j, k, l, t);
                    (dp[i + 1][j - l + x[i] - k] += t) %= M;
                }
            }
        }
    }
    cout << dp[n][0] << endl;
}