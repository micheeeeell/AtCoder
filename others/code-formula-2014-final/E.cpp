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

vector<ll> f(2);
Pll dfs(const string &s, int n){
    if(s == "a")return {2, 0};
    if(s == "b")return {1, 0};
    if(s == "ab")return {3, 0};
    if(s == "ba")return {3, 1};
    ll sh = f[n-3];
    assert(s.size() == f[n-1]);
    ll id = sh;
    bool ok = true;
    rep(i,0,sh){
        ok &= s[i] == s[id];
        id++;
    }
    Pll l, r;
    if(ok){
        l = dfs(s.substr(0, sh), n - 2);
        r = dfs(s.substr(sh), n - 1);
    }
    else {
        l = dfs(s.substr(0, f[n-2]), n - 1);
        r = dfs(s.substr(f[n-2]), n - 2);
    }
    debug(s, l, r);
    Pll ans;
    ans.first = n;
    if(l.first > r.first){
        ans.second = l.second * 2; 
    }
    else{
        ans.second = r.second * 2 + 1;
    }
    debug(s, ans);
    assert(ans.second / 4 == min(l.second, r.second));
    if(ans.second % 4 == 3)ans.second -= 3;
    return ans;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;cin >> s;
    f[0] = f[1] = 1;
    ll id = 2;
    while(f.back() < 2e5){
        f.emplace_back(f[id-1] + f[id-2]);
        id++;
    }

    debug(f.size());
    debug(f);

    ll n;
    rep(i,0,f.size()){
        if(f[i] == s.size()){
            n = i + 1;
            break;
        }
    }
    auto ans = dfs(s, n);
    cout << ans.first << " " << ans.second << endl;
}
