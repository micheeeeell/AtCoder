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
    ll x,y; cin >> x >> y;
    ll n; cin >> n;
    vector<Pll> v(n + 1);
    rep(i,0,n){
        cin >> v[i].first >> v[i].second;
    }
    v[n] = v[0];

    auto area = [&](Pll a, Pll b, Pll c) {
        double ans = 0;
        a.first -= c.first;
        b.first -= c.first;
        a.second -= c.second;
        b.second -= c.second;
        ans = abs(a.first * b.second - a.second * b.first);
        ans /= 2.0;
        return ans;
    };

    auto dist = [&](Pll a, Pll b, Pll c) {
        double ar = area(a, b, c) * 2.0;
        debug(a, b, c, ar);
        return ar / (hypot(a.first - b.first, a.second - b.second));
    };

    double ans = INF;
    rep(i, 0, n) {
        double temp = dist(v[i], v[i + 1], Pll(x, y));
        chmin(ans, temp);
        debug(i, temp);
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;
}