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
    ll n; cin >> n;
    vector<Pll> v(n);
    rep(i,0,n){
        ll x,y; cin >> x >> y;
        if (x > y) swap(x, y);
        v[i] = {x, y};
    }
    ll ans = INF;
    ll min_ = INF, max_ = 0;

    // 最大値、最小値を別にする
    sort(all(v));
    ll a = v.back().first - v.begin()->first;
    min_ = v.begin()->first;
    sort(all(v),
         [](const auto a, const auto b) { return a.second < b.second; });
    ll b = v.back().second - v.begin()->second;
    chmin(ans, a * b);
    max_ = v.back().second;
    // 最大値、最小値を同じグループにする

    ll l = INF, r = 0;
    ll mincnt = 0, maxcnt = 0;
    rep(i, 0, n) {
        auto [x, y] = v[i];
        if (x == min_){
            chmax(r, y);
            chmin(l, y);
            mincnt++;
        }
        if(y == max_){
            chmax(r, x);
            chmin(l, x);
            maxcnt++;
        }
    }
    if(mincnt == 1 && maxcnt == 1 && v.back().first == min_){
        cout << ans << endl;
        return 0;
    }


    rep(i,0,n){
        auto [x, y] = v[i];
        if (x > r) r = x;
        if (y < l) l = y;
    }
    debug(l, r);
    sort(all(v));
    ll res = INF;
    auto check = [&](ll x) { return l <= x && r >= x; };
    rep(i, 0, n) {
        auto [x, y] = v[i];
        if (check(x) || check(y)) continue;
        // if (y == max_ || x == min_) continue;
        chmin(res, r - x);
        r = y;
    }

    a = max_ - min_;
    b = res == INF ? (r - l) : res;
    debug(a, b);

    chmin(ans, a * b);


    cout << ans << endl;
}