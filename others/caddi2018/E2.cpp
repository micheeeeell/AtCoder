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

vector<ll> calc(ll n, vector<ll> &a){
    ll log = 16;
    vector dp(n, vector(log, 0LL));
    rep(j,0,log)dp[n-1][j] = j * 2;
    rrep(i,n-1, 0){
        if(a[i] < a[i+1]){
            ll t = 1;
            ll num = a[i+1] / a[i];
            ll p = 0;
            while(t <= num){
                p++;t *= 4;
            }
            p--;
            debug("1", a[i], a[i+1], p);

            rep(j,0,log){
                dp[i][j] = dp[i+1][max(0LL, j - p)] + j * 2;
            }
        }
        else{
            ll t = 1;
            ll num = (a[i] + a[i+1] - 1) / a[i+1];
            ll p = 0;
            while(t < num){
                p++;t *= 4;
            }
            debug("2", a[i], a[i+1], p);

            rep(j,0,log){
                if(j + p < log){
                    dp[i][j] = dp[i+1][j + p] + j * 2;
                }
                else{
                    dp[i][j] = dp[i+1][log-1] + (n - i - 1) * (j + p - log+1) * 2 + j * 2;
                }
            }
        }
    }

    debug(dp);

    vector<ll> res(n+1);
    rep(i,0,n)res[i] = dp[i][0];
    return res;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    auto l = calc(n, a);
    reverse(all(a));
    auto r = calc(n, a);
    reverse(all(r));
    debug(l, r);
    ll ans = INF;
    rep(i,0,n+1){
        chmin(ans, l[i] + r[i] + i);
    }
    cout << ans << "\n";
}