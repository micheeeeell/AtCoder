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
void YES(bool ok){
    cout << (ok ? "YES" : "NO") << endl;
}
void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

ll rem(ll x, ll k){
    ll t1 = x >> (k + 1);
    x &= (1LL << k) - 1;
    return (t1 << k) + x;
}

ll ins(ll x, ll k, ll one){
    ll t1 = x >> k;
    x &= (1LL << k) - 1;
    return (t1 << (k+1)) + x + (one << k);
}
vector<ll> ans;
vector<ll> used;
ll n, a, b;
vector<ll> dfs(ll n,ll s, ll t){
    if(n == 1){
        if(s == 0)return {0,1};
        else return {1,0};
    }
    ll id = 0;
    while(((s >> id) & 1) == ((t >> id) & 1))id++;
    ll sd = rem(s, id), td = rem(t, id);
    ll c = 0;
    if(__builtin_popcountll(sd) & 1){
        c = 0;
    }
    else {
        c = 1;
    }
    debug(sd, td, c, id);
    auto left = dfs(n-1, sd, c);
    auto right = dfs(n-1, c, td);
    vector<ll> ans;
    ll one = (s >> id) & 1;
    for(auto &i : left){
        ans.emplace_back(ins(i, id, one));
    }
    for(auto &i : right){
        ans.emplace_back(ins(i, id, one ^ 1));
    }

    return ans;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    if((__builtin_popcountll(a) % 2) == (__builtin_popcountll(b) % 2)){
        YES(false);
        return 0;
    }
    YES(true);
    auto ans = dfs(n, a, b);
    print(ans);
}