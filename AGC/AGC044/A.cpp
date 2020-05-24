// #define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';}
string to_string(const char c) {return to_string((string) &c);}
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

map<ll,ll> mp;
ll a, b, c, d;
ll dfs(ll x){
    if(mp.count(x) != 0)return mp[x];
    if(x == 1)return mp[1] = d;
    if(x == 0)return mp[0] = 0;

    ll ans = INF;
    if(ans / d > x){
        chmin(ans, d * x);
    }

    if(x % 2 == 0)chmin(ans, dfs(x / 2) + a);
    else{
        chmin(ans, dfs((x + 1) / 2) + d + a);
        chmin(ans, dfs((x - 1) / 2) + d + a);
    }

    debug(x, ans);

    if(x % 3 == 0){
        chmin(ans, dfs(x / 3) + b);
    }
    else if(x % 3 == 1){
        chmin(ans, dfs((x - 1) / 3) + d + b);
        chmin(ans, dfs((x + 2) / 3) + 2 * d + b);
    }
    else{
        chmin(ans, dfs((x - 2) / 3) + 2 * d + b);
        chmin(ans, dfs((x + 1) / 3) + d + b);
    }

    debug(x, ans);
    rep(i,5){
        if(x % 5 == i && i == 0){
            chmin(ans, dfs(x / 5) + c);
            continue;
        }

        if(x % 5 == i){
            chmin(ans, dfs((x - i) / 5) + i * d + c);
            chmin(ans, dfs((x + (5 - i)) / 5) + (5 - i) * d + c);
        }

    }
    debug(x, ans);
    return mp[x] = ans;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll t; cin >> t;
    rep(_, t){
        ll n; cin >> n;
        cin >> a >> b;
        cin >> c >> d;
        cout << dfs(n) << "\n";
        mp.clear();
    }
}