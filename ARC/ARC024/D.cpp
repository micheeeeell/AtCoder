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
constexpr ll n_max = 1e3+10;
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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector v(n_max, vector<ll>());
    vector memo(n_max, vector<ll>(n_max));
    vector<ll> X;
    rep(i, 0, n) {
        ll x,y; cin >> x >> y;
        v[x].emplace_back(y);
        X.emplace_back(x);
        memo[x][y] = 1;
    }
    sort(all(X));
    X.erase(unique(all(X)), X.end());
    debug(X);
    ll m = X.size();
    vector<Pll> ans;
    auto dfs = [&](auto self, ll l, ll r) {
        if (r - l == 1) return;
        if(r - l == 2){
            ll x1 = X[l];
            ll x2 = X[l + 1];
            if (v[x1].size() > v[x2].size()) swap(x1, x2);
            for(auto y : v[x1]){
                if(!memo[x2][y]){
                    ans.emplace_back(Pll(x2, y));
                    memo[x2][y] = 1;
                }
            }
            return;
        }
        ll x = l + (r - l) / 2;
        ll x1 = X[x];
        rep(i, l, x) {
            for(auto y : v[X[i]]){
                if(!memo[x1][y]){
                    ans.emplace_back(Pll(x1, y));
                    memo[x1][y] = 1;
                }
            }
        }
        rep(i, x + 1, r){
            for(auto y : v[X[i]]){
                if (!memo[x1][y]) {
                    ans.emplace_back(Pll(x1, y));
                    memo[x1][y] = 1;
                }
            }
        }
        self(self, l, x);
        self(self, x + 1, r);
    };

    dfs(dfs, 0, m);
    cout << ans.size() << "\n";
    for(auto p : ans){
        cout << p.first << " " << p.second << "\n";
    }
}