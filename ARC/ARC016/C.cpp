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

vector<vector<Pll>> v;
vector<ll> cost;
ll n, m;
vector<double> dp;
vector<int> flag;

double dfs(ll mask) {
    if(__builtin_popcountll(mask) == n){
        flag[mask] = 1;
        return 0.0;
    }
    if(flag[mask])
        return dp[mask];

    double ret = INF;
    rep(i,0,m){
        double coef = 0;
        double temp = 0;
        for(auto &p : v[i]){
            if((mask >> p.first) & 1){
                coef += p.second;
            }
            else {
                temp += (double)p.second * dfs(mask | (1LL << p.first)) / 100.0;
            }
        }
        if(coef == 100){
            continue;
        }
        temp += cost[i];
        temp *= 100;
        temp /= double(100 - coef);
        chmin(ret, temp);
    }
    flag[mask] = 1;
    return dp[mask] = ret;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    v.resize(m);
    cost.resize(m);
    rep(i,0,m){
        ll k,co; cin >> k >> co;
        rep(j,0,k){
            ll idol,p; cin >> idol >> p;
            idol--;
            v[i].emplace_back(idol, p);
        }
        cost[i] = co;
    }

    dp.resize(1LL << n);
    flag.resize(1LL << n, 0);

    cout << fixed << setprecision(15);
    cout << dfs(0) << endl;
}