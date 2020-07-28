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
    ll n; cin >> n;
    map<ll, vector<ll>> xm, ym;
    vector<tuple<ll, ll, ll>> v(n);
    rep(i,0,n){
        auto &[x,y,p] = v[i];
        cin >> x >> y >> p;
    }

    vector dp(1LL << n, vector<ll>(n+1, INF));
    map<Pll, vector<ll>>mp;
    ll num = 0;
    vector<ll> t(n);
    rep(i,0,n){
        auto &[x,y,p] = v[i];
        num += min(abs(x), abs(y)) * p;
        t[i] = min(abs(x), abs(y)) * p;
    }
    dp[0][0] = num;
    mp[{0,0}] = t;
    rep(i,0,1LL << n){
        rep(j,0,n){
            if(mp.find({i, j}) != mp.end())t = mp[{i, j}];
            else continue;
            ll num = dp[i][j];
            rep(k,0,n){
                auto &[x,y,p] = v[k];
                ll xnum = num, ynum = num;
                ll mask = i | (1LL << k);
                vector<ll> xt = t, yt = t;
                rep(l,0,n){
                    auto &[xx,yy,pp] = v[l];
                    if(abs(xx - x) * pp <= t[l]){
                        xnum -= t[l] - abs(xx - x) * pp;
                        xt[l] = abs(xx - x) * pp;
                    }
                    if(abs(yy - y) * pp <= t[l]){
                        ynum -= t[l] - abs(yy - y) * pp;
                        yt[l] = abs(yy - y) * pp;
                    }
                }
                if(chmin(dp[mask][j+1], xnum)){
                    mp[{mask, j+1}] = xt;
                }
                if(chmin(dp[mask][j+1], ynum)){
                    mp[{mask, j+1}] = yt;
                }
            }
        }
    }

    rep(k,0,n+1){
        ll ans = INF;
        rep(i,0,1LL << n)chmin(ans, dp[i][k]);
        cout << ans << "\n";
    }

}