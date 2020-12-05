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

vector<ll> Z_algo(string &s) {
    int len = s.size();
    vector<ll> res(len);
    res[0] = len;
    int i = 1, j = 0;
    while (i < len) {
        while (i + j < len && s[j] == s[i + j]) ++j;
        res[i] = j;
        if (j == 0) {
            ++i;
            continue;
        }
        int k = 1;
        while (i + k < len && k + res[k] < j) {
            res[i + k] = res[k], ++k;
        }
        i += k;
        j -= k;
    }
    return res;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;cin >> s;
    ll n = s.size();
    auto za = Z_algo(s);
    reverse(all(s));
    auto zb = Z_algo(s);
    reverse(all(zb));
    debug(za, zb);
    ll ans = 0;
    rep(i, 1, n) {
        ll a = min({i-1, n-i-1, za[i]}), c = min({i-1,n-i-1,zb[i-1]});
        debug(i, a, c);
        if (!a || !c || i <= n-i) continue;
        ans += max(0LL, a + c - (n - i) + 1);
    }

    cout << ans << endl;
}