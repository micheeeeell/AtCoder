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
    string s, t;cin >> s >> t;
    vector memo(n + 1, vector<ll>(n + 1)), flag(n + 1, vector<ll>(n + 1));
    auto dfs = [&](auto self, ll l, ll r) -> ll {
        ll res = 0;
        if (r - l < 3) return 0;
        if (flag[l][r]) return memo[l][r];
        rep(i,l + 1, r){
            chmax(res, self(self, l, i) + self(self, i, r));
        }
        if(s[l] == t[0] && s[r - 1] == t[2]){
            rep(i,l + 1, r - 1){
                if(s[i] == t[1]){
                    ll left = self(self, l + 1, i);
                    ll right = self(self, i + 1, r - 1);
                    if(left * 3 == i - (l + 1) && right * 3 == r - 1 - (i + 1)){
                        chmax(res, left + right + 1);
                    }
                }
            }
        }
        flag[l][r] = 1;
        return memo[l][r] = res;
    };
    cout << dfs(dfs, 0, n) << endl;
}