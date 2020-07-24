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

ll calc(ll x){
    ll res = 0;
    while(x){
        res += x % 10;
        x /= 10;
    }
    return res;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll k,m; cin >> k >> m;
    ll ans = 0;
    if(m / k < 1e6){
        rep(i,0,min(95LL, k)){
            for(ll j = i;j <= m; j += k){
                if(calc(j) % k == i)ans++;
            }
        }
        ans--;
        cout << ans << "\n";
        return 0;
    }
    string s = to_string(m);
    ll n = s.size();
    vector<ll> p(n);
    p[0] = 1;
    rep(i,1,n) p[i] = p[i-1] * 10 % k;
    reverse(all(p));
    vector dp(n+1, vector(2, vector(95, vector(k, 0LL))));
    dp[0][0][0][0] = 1;
    rep(i,0,n){
        ll t = s[i] - '0';
        rep(small,0,2){
            rep(j,0,95)rep(l,0,k)rep(d,0,small ? 10 : t+1){
                ll small_ = small;
                ll j_ = (j + d) % k;
                ll l_ = (l + d * p[i]) % k;
                if(d < t)small_ = 1;
                if(j_ >= 95)continue;
                dp[i+1][small_][j_][l_] += dp[i][small][j][l];
            }
        }
    }

    rep(i,0,min(k, 95LL)){
        ans += dp[n][0][i][i] + dp[n][1][i][i];
    }
    ans--;
    cout << ans << "\n";
}