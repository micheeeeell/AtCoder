#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
// #include<atcoder/all>
// using namespace atcoder;
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

random_device rnd;
mt19937_64 mt(rnd());

template<class T>
vector<T> make_vector(int n, T max_, T min_ = 0){
    vector<T> v(n);
    T a = max_ - min_ + 1;
    assert(a > 0);
    rep(i, 0, n) {
        v[i] = mt() % a + min_;
    }
    return v;
}

template<class T>
vector<T> make_permutation(int n, T min_ = 0){
    // [0,n)のランダムな順列
    vector<T> v(n), r(n);
    iota(v.begin(), v.end(), min_);
    rep(i, 0, n) r[i] = mt();
    sort(v.begin(), v.end(),
         [&](const auto a, const auto b) { return r[a - min_] < r[b - min_];} );
    return v;
}

vector<pair<int, int>> make_star(int n){
    vector<pair<int, int>> p(n - 1);
    rep(i,2,n + 1){
        p[i - 2] = {1, i};
    }
    return p;
}

vector<pair<int, int>> make_binary(int n){
    vector<pair<int, int>> p(n - 1);
    rep(i,2,n + 1){
        p[i - 2] = {i, i / 2};
    }
    return p;
}

vector<pair<int, int>> make_random_tree(int n){
    vector<pair<int, int>> p(n - 1);
    vector<pair<int, int>> used, not_used;
    rep(i,0,n){
        not_used.emplace_back(mt(), i);
    }
    sort(all(not_used));
    auto t = not_used.back();
    not_used.pop_back();
    used.emplace_back(t);
    rep(i, 0, n - 1){
        t = not_used.back();
        not_used.pop_back();
        int id = mt() % used.size();
        p[i] = {t.second + 1, used[id].second + 1};
        used.emplace_back(t);
    }
    return p;
}

vector<pair<int, int>> make_graph(int n, int m, bool is_connected = true){
    assert(n > 1);
    vector<pair<int, int>> p;
    if(is_connected){
        p = make_random_tree(n);
        m -= n - 1;
    }
    rep(i,0,m){
        ll f = mt() % n + 1;
        ll t = mt() % n + 1;
        while(t == f){
            t = mt() % n + 1;
        }
        p.emplace_back(f, t);
    }
    return p;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    debug(make_permutation<ll>(n, 1LL));
}