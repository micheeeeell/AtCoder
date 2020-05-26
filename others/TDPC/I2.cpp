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
constexpr ll n_max = 330;
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

vector<vector<ll>> memo(n_max, vector<ll>(n_max));
vector<vector<ll>> flag(n_max, vector<ll>(n_max));
string s;
ll dfs(ll l, ll r){
    if(flag[l][r])return memo[l][r];
    ll len = r - l;
    if(len < 3){
        flag[l][r] = 1;
        return 0;
    }
    if(len == 3 && s.substr(l, 3) == "iwi"){
        flag[l][r] = 1;
        return memo[l][r] = 1;
    }
    ll ret = 0;
    if((len % 3 == 0) && (s.substr(l,1) + s.substr(r-2, 2) == "iwi")){
        if(dfs(l+1, r-2) == (len - 3) / 3){
            chmax(ret, dfs(l+1, r-2) + 1);
        }
    }
    if((len % 3 == 0) && (s.substr(l,2) + s.substr(r-1, 1) == "iwi")){
        if(dfs(l+2, r-1) == (len - 3) / 3){
            chmax(ret, dfs(l+2, r-1) + 1);
        }
    }

    for(int i = l+1; i < r; i++){
        chmax(ret, dfs(l, i) + dfs(i, r));
    }
    flag[l][r] = 1;
    return memo[l][r] = ret;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> s;
    ll n = s.size();
    cout << dfs(0, n) << endl;
}