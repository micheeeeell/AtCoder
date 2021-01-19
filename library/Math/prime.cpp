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

template <typename T>
int comp(T a){
    if (abs(a) < eps) return 0;
    return a > 0 ? 1 : -1;
}

template <typename T>
int comp(T a, T b){
    // a > b -> 1, a < b -> -1
    return comp(a - b);
}
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


// xを素因数分解する関数
// 連想配列で＜素因数，べき乗＞が帰る
template<class T>
map<T,int> prime(T x){
    map<T,int> e;
    for(ll i = 2; i * i <= x; i++){
        while(x % i == 0){
            e[i]++;
            x /= i;
        }
    }
    if(x != 1)e[x]++;
    return e;
}

// 最小公倍数を因数分解された形で持つ
// 入力のmap_を適宜更新していく
template <typename T>
void lcm_map(T x, map<T, int> &map_) {
    for(ll i = 2; i * i <= x; i++){
        if(i <= 1)continue;
        ll cnt = 0;
        while(x % i == 0){
            cnt++;
            if(map_[i] < cnt)map_[i] = cnt;
            x /= i;
        }
    }
    if(x != 1)if(map_[x] < 1)map_[x]++;
    // return map_;
}

// xと元の数をかけた時の値を因数分解された形で更新する
template <typename T>
void prime_map(T x, map<T, int> &map_) {
    for(ll i = 2; i * i <= x; i++){
        while(x % i == 0){
            map_[i]++;
            x /= i;
        }
    }
    if(x != 1)map_[x]++;
    // return map_;
}

template <typename T>
vector<T> divisor(T x) {
    auto mp = prime(x);
    vector<T> res;
    vector<pair<T, T>> v;
    for (auto p : mp) {
        debug(p);
        v.emplace_back(p);
    }
    ll n = v.size();
    auto dfs = [&](auto s, ll val = 1, ll d = 0) {
        if (d == n) {
            if (val != 1) res.emplace_back(val);
            return;
        }

        s(s, val, d + 1);
        for (int i = 0; i < v[d].second; i++) {
            val *= v[d].first;
            s(s, val, d + 1);
        }
    };
    dfs(dfs);
    return res;
}

signed main(){
    ll n; cin >> n;
    auto d = divisor(n);
    sort(all(d));
    debug(d.size(), d);
}