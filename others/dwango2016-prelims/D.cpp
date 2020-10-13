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
    ll h,w; cin >> h >> w;
    vector<vector<ll>> b(h, vector<ll>(w));
    rep(i,0,h)rep(j,0,w){
        cin >> b[i][j];
    }

    auto calc = [](ll h, ll w, vvl &b) {
        vvl sum(h + 1, vl(w + 1));
        rep(i, 0, h) rep(j, 0, w) {
            sum[i + 1][j + 1] =
                sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + b[i][j];
        }
        debug(sum);
        vector<ll> res(w, -INF);
        vvvl dp(w + 1, vvl(w + 1, vl(h)));
        rep(i,0,w + 1)rep(j,i+1,w + 1)rep(k,0,h){
            chmax(dp[i][j][k], sum[k + 1][i] - sum[k + 1][j]);
            if(k) chmax(dp[i][j][k], dp[i][j][k - 1]);
            // debug(i, j, k, dp[i][j][k]);
        }

        rep(r, 1, w + 1){
            rep(l, 0, r)rep(k, 0, h){
                ll t = sum[k + 1][r] - sum[k + 1][l];
                if (k) t += dp[l][r][k - 1];
                // debug(l, r, k, t, dp[l][r][k]);
                chmax(res[r - 1], t);
                if(r > 1)chmax(res[r - 1], res[r - 2]);
            }
        }

        return res;
    };
    ll ans = -INF;
    auto solve = [&](ll h, ll w, vvl &b) {
        auto left = calc(h, w, b);
        rep(i, 0, h) reverse(all(b[i]));
        auto right = calc(h, w, b);
        reverse(all(right));
        rep(i,0,w-1){
            chmax(ans, left[i] + right[i + 1]);
        }
        // chmax(ans, right[0]);
        debug(left, right);
    };

    solve(h, w, b);
    vvl b2(w, vl(h));
    rep(i, 0, h) rep(j, 0, w) b2[j][i] = b[i][j];
    solve(w, h, b2);

    cout << ans << "\n";
}