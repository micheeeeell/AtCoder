#define LOCAL
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
ll n;
const ll n_max = 15;
const ll MAX = 1LL << n_max;
vector<vector<ll>> vec(n_max, vector<ll>(2));
vector<ll> memo(MAX);
ll dfs(ll mask){
    if(__builtin_popcountll(mask) == 1)return 1;
    if(memo[mask])return memo[mask];
    bool ok = true;
    ll ed = -1;
    rep(i,n){
        if((mask >> i) & 1){
            if(ed > vec[i][0])ok = false;
            ed = vec[i][1];
        }
    }
    rep(i,n){
        if((mask >> i) & 1){
            if(ed >( vec[i][0] + 60 * 24))ok = false;
            ed = vec[i][1] + 60 * 24;
        }
    }
    
    if(ok)return memo[mask] = 1;
    ll ans = INF;
    for(ll t = mask; t > 0; t = (t-1) & mask){
        if(t == mask)continue;
        chmin(ans, dfs(t) + dfs(mask ^ t));
    }

    return memo[mask] = ans;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    auto to_num = [](string &s){
        ll ret = (s[0] - '0') * 10 + (s[1] - '0');
        ret *= 60;
        ret += (s[3] - '0') * 10 + (s[4] - '0');
        return ret;
    };
    vector<Pll> v;
    rep(i,n){
        string s, t;cin >> s >> t;
        v.emplace_back(to_num(s), to_num(t));
    }
    sort(all(v));
    rep(i,n){
        vec[i][0] = v[i].first;
        vec[i][1] = v[i].second;
    }

    cout << dfs((1LL << n) - 1) << endl;
}