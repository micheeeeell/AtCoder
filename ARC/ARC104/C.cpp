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
constexpr ll n_max = 210;
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

void YES(bool ok){
    cout << (ok ? "Yes" : "No") << endl;
    exit(0);
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<Pll> v(2 * n, {-1, -1});
    rep(i, 0, n) {
        ll a,b; cin >> a >> b;
        if(a != -1){
            a--;
            if (v[a] != Pll{-1, -1}) YES(false);
            v[a] = {0, i};
        }
        if(b != -1){
            b--;
            if (v[b] != Pll{-1, -1}) YES(false);
            v[b] = {1, i};
        }
        if(a != -1 && b != -1){
            if (a > b) YES(false);
        }
    }

    // [l, r]の区間を正しく補完できるかチェック
    auto check = [&](ll l, ll r) {
        if (l & 1) return false;
        if (~r & 1) return false;

        ll len = (r - l + 1) / 2;
        bool res = true;

        rep(i, l, l + len){
            ll j = i + len;
            res &= v[i].first != 1;
            res &= v[j].first != 0;

            if (v[i] != Pll{-1, -1} && v[j] != Pll{-1, -1}) {
                res &= v[j].first == 1 && v[i].second == v[j].second;
            }
        }

        if (res) debug(l, r);
        return res;
    };

    bitset<n_max> dp(0);
    rep(i,0,2 * n){
        if (~i & 1) continue;

        rep(j, 0, i) {
            if (!dp[j]) continue;
            if (check(j + 1, i)){
                dp[i] = 1;
                break;
            }
        }
        if (check(0, i)) dp[i] = 1;
    }
    debug(dp);
    YES(dp[2 * n - 1]);
}