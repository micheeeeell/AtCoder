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
    ll h,w; cin >> h >> w;
    ll n,m; cin >> n >> m;
    vector tate(h, vector<ll>(w));
    rep(i,0,n){
        ll x,y; cin >> x >> y;
        x--;
        y--;
        tate[x][y] = 1;
    }
    rep(j,0,m){
        ll x,y; cin >> x >> y;
        x--;
        y--;
        tate[x][y] = 5;
    }

    vector yoko = tate;
    debug(yoko, tate);
    rep(i, 0, h) rep(j, 0, w - 1) {
        if (yoko[i][j] == 5) continue;
        chmax(yoko[i][j + 1], yoko[i][j]);
    }
    rep(i,0,h)rrep(j,w,1){
        if (yoko[i][j] == 5) continue;
        chmax(yoko[i][j - 1], yoko[i][j]);
    }

    rep(i,0,h-1)rep(j,0,w){
        if (tate[i][j] == 5) continue;
        chmax(tate[i + 1][j], tate[i][j]);
    }

    rrep(i,h,1)rep(j,0,w){
        if (tate[i][j] == 5) continue;
        chmax(tate[i - 1][j], tate[i][j]);
    }

    ll ans = 0;
    rep(i,0,h)rep(j,0,w){
        if (yoko[i][j] == 1 || tate[i][j] == 1) ans++;
    }

    debug(yoko, tate);

    cout << ans << endl;
}