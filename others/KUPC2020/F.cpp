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
    vector<ll> a(h-1);
    for(int i = 0; i < h-1; i++) cin >> a[i];
    vector<ll> b(w);
    for(int i = 0; i < w; i++) cin >> b[i];
    vector<ll> c(h);
    for(int i = 0; i < h; i++) cin >> c[i];
    vector<ll> d(w-1);
    for(int i = 0; i < w-1; i++) cin >> d[i];

    vector<ll> ws(w - 1);
    rep(i,0,w - 1){
        ws[i] = d[i] - b[i + 1]; 
    }
    sort(all(ws));
    debug(ws);

    ll ans = 0;
    ans += c[0] * (w - 1);
    rep(i, 0, h - 1) {
        ll id = lower_bound(all(ws), a[i] - c[i + 1]) - ws.begin();
        debug(i, id);
        ans += c[i + 1] * id;
        ans += a[i] * (w - id);
    }
    debug(ans);
    vector<ll> hs(h - 1);
    rep(i, 0, h - 1) {
        hs[i] = a[i] - c[i + 1];
    }
    sort(all(hs));
    debug(hs);

    ans += b[0] * (h - 1);
    rep(i,0,w - 1){
        ll id = upper_bound(all(hs), d[i] - b[i + 1]) - hs.begin();
        debug(i, id);
        ans += b[i + 1] * id;
        ans += d[i] * (h - id);
    }

    cout << ans << endl;
}