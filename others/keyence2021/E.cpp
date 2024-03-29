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
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector memo(n + 1, vector(n + 1, vector<ll>((n + 1) / 2 + 1)));
    ll s = (n + 1) / 2;
    auto flag = memo;
    auto dfs = [&](auto self, ll l, ll r, ll k) -> ll{
        if (flag[l][r][k]) return memo[l][r][k];
        ll res = 0;
        ll L = 0, R = 0;
        if (l == 0) L = 0;
        else
            L = a[l - 1];
        if (r == n) R = 0;
        else
            R = a[r];
        if(L == R){
            return 0;
        }
        if(L > R){
            chmax(res, self(self, l - 1, r, k));
        }
        else{
            chmax(res, self(self, l, r + 1, k));
        }

        ll m = r - l;
        if(k <= m / 2){
            if (l) chmax(res, self(self, l - 1, r, k + 1) + a[l - 1]);
            if (r < n) chmax(res, self(self, l, r + 1, k + 1) + a[r]);
        }

        flag[l][r][k] = 1;
        return memo[l][r][k] = res;
    };

    rep(i,0,n + 1){
        cout << dfs(dfs, i, i, 0) << "\n";
    }
    // debug(memo);
}