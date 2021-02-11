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

template <typename T>
vector<T> N_LIS(vector<T> a, T M0) {
    
    // fill(all(dp), INF);
    int n = a.size();
    vector<T> dp(n + 1, M0);
    for (int i = 0; i < n; i++) {
        *lower_bound(all(dp), a[i]) = a[i];
    }
    // cout << lower_bound(all(dp), M0) - dp.begin() << endl;
    return dp;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    Pll s, t;
    cin >> s.first >> s.second;
    cin >> t.first >> t.second;
    if (s.first > t.first) swap(s, t);
    ll n;
    cin >> n;
    vector<Pll> v(n);
    for(auto &&[a, b] :v){
        cin >> a >> b;
    }

    bool rev = t.second < s.second;
    if(rev){
        t.second = -t.second;
        s.second = -s.second;
    }
    vector<Pll> u;
    for(auto [a, b] : v){
        if(rev){
            b = -b;
        }
        if (a < s.first || a > t.first) continue;
        if (b < s.second || b > t.second) continue;
        u.emplace_back(a, b);
    }
    sort(all(u));
    vector<ll> w;
    for (auto [a, b] : u) w.emplace_back(b);
    auto d = N_LIS(w, INF);
    debug(d);
    ll k = lower_bound(all(d), INF) - d.begin();
    
    ld ans = 100 * (t.first - s.first + t.second - s.second);
    ld a1 = 20 * pi / ld(4) - 20;
    ld a2 = 20 * pi / ld(2) - 20;
    if (k == min(t.first - s.first, t.second - s.second) + 1) {
        ans += (k - 1) * a1 + a2;
    }
    else{
        ans += k * a1;
    }

    cout << fixed << setprecision(15);
    cout << ans << endl;
}