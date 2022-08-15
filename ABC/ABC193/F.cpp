#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
// #include<atcoder/all>
// using namespace atcoder;
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

template <typename T>
int comp(T a){
    if (abs(a) < eps) return 0;
    return a > 0 ? 1 : -1;
}

template <typename T>
int comp(T a, T b){
    // a > b -> 1, a < b -> -1
    return comp(a - b);
}

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

struct S {
    vector<ll> v;
    S():v(8, 0){};

    ll id(ll i, ll j, ll k){
        return i + (j << 1) + (k << 2);
    };
    bool update(ll id, ll x) {
        return chmax(v[id], x);
    }
    ll get(ll dim, ll i, ll j, ll k){
        if(dim == 0){
            return max(v[id(0, j, k)], v[id(1, j, k)]);
        }
        if(dim == 1){
            return max(v[id(i, 0, k)], v[id(i, 1, k)]);
        }
        if(dim == 2){
            ll res = 0;
            rep(ii,0,2)rep(jj,0,2){
                chmax(res, v[id(ii, jj, k)]);
            }
            return res;
        }
        return 0;
    }

    friend string to_string(S &s){
        return to_string(s.v);
    }
};
signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h; cin >> h;
    vector<string> s(h);
    for(int i = 0;i < h;i++){
       cin >> s[i];
    }
    ll w = h;

    vector dp(h, vector<S>(w));
    auto id = [](ll i, ll j, ll k) { return i + (j << 1) + (k << 2); };
    auto check = [&](ll i, ll j, ll b) {
        if (s[i][j] == '?') return true;
        return b ? s[i][j] == 'W' : s[i][j] == 'B';
    };
    rep(i,1,h){
        rep(x,0,2){
            if (!check(i-1, 0, x)) continue;
            rep(y, 0, 2) {
                if (!check(i, 0, y)) continue;
                ll t = max(dp[i - 1][0].get(0, 0, 0, x),
                           dp[i - 1][0].get(0, 0, 1, x));
                t += x != y;
                dp[i][0].update(id(x, 0, y), t);
                dp[i][0].update(id(x, 1, y), t);
            }
        }
        debug(i, dp[i][0]);
    }
    rep(j,1,w){
        rep(x, 0, 2){
            if (!check(0, j - 1, x)) continue;
            rep(y,0,2){
                if (!check(0, j, y)) continue;
                ll t = max(dp[0][j - 1].get(1, 0, 0, x),
                           dp[0][j - 1].get(1, 1, 0, x));
                t += x != y;
                dp[0][j].update(id(0, x, y), t);
                dp[0][j].update(id(1, x, y), t);
            }
        }
        debug(j, dp[0][j]);
    }
    rep(i, 1, h) rep(j, 1, w) {
        rep(x,0,2){
            if (!check(i - 1, j - 1, x)) continue;
            rep(y, 0, 2) {
                if (!check(i - 1, j, y)) continue;
                rep(z, 0, 2) {
                    if (!check(i, j - 1, z)) continue;
                    rep(n, 0, 2) {
                        if (!check(i, j, n)) continue;
                        ll t = 0;
                        t = dp[i-1][j].get(0, 0, x, y);
                        t += dp[i][j-1].get(1, x, 0, z);
                        debug(t);
                        t -= dp[i-1][j-1].get(2, 0, 0, x);
                        debug(t);
                        t += y != n;
                        t += z != n;
                        dp[i][j].update(id(y, z, n), t);
                        debug(i, j, x, y, z, n, t, dp[i][j]);
                    }
                }
            }
        }
    }

    ll ans = 0;
    if(s[h-1][w-1] == 'W'){
        ans = dp[h-1][w-1].get(2, 0, 0, 1);
    } else if (s[h - 1][w - 1] == 'B'){
        ans = dp[h-1][w-1].get(2, 0, 0, 0);
    } else{
        ans = *max_element(all(dp[h-1][w-1].v));
    }

    cout << ans << endl;
}