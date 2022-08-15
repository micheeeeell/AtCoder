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

template <class T>
struct point {
    T x = 0, y = 0;
    point(){};
    point(T x, T y) : x(x), y(y){};
    friend string to_string(point<T> p) {
        return "{" + to_string(p.x) + ", " + to_string(p.y) + "}";
    }
};

template <class T>
struct circle {
    point<T> c = {0, 0};
    T r = 0;
    circle(){};
    circle(point<T> p, T r) : c(p), r(r){};
    circle(T x, T y, T r) : c(x, y), r(r){};
    friend string to_string(circle<T> p) {
        return "{" + to_string(p.c) + ", " + to_string(p.r) + "}";
    }
};
// 円同士の交点
template <class T>
vector<point<T>> ccinter(circle<T> &a, circle<T> &b) {
    auto [ac, ar] = a;
    auto [bc, br] = b;
    bc.x -= ac.x;
    bc.y -= ac.y;
    T s = bc.x * bc.x + bc.y * bc.y;
    T t = (s + ar * ar - br * br) / T(2);
    T d = s * ar * ar - t * t;
    if (comp(d, (T)0) < 0) {
        return {};
    }
    if (comp(d, (T)0) == 0) {
        return {{t * bc.x / s, t * bc.y / s}};
    }
    T px = t * bc.x / s;
    T py = t * bc.y / s;
    return {{px + bc.y * sqrt(d) / s + ac.x, py - bc.x * sqrt(d) / s + ac.y},
            {px - bc.y * sqrt(d) / s + ac.x, py + bc.x * sqrt(d) / s + ac.y}};
};

template <class T>
long double dist(point<T> a, point<T> b) {
    return hypot(a.x - b.x, a.y - b.y);
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    using T = tuple<point<ld>, ll>;
    vector<T> v(n);
    for(auto &&[p, c] : v){
        auto &&[x, y] = p;
        cin >> x >> y >> c;
    }

    auto check = [&](ld X) {
        vector<circle<ld>> c(n);
        rep(i, 0, n) {
            auto [p, C] = v[i];
            c[i] = {p, X / (ld)C};
        }

        vector<point<ld>> p;
        rep(i,0,n){
            p.emplace_back(c[i].c);
            rep(j,i+1, n){
                auto r = ccinter(c[i], c[j]);
                for (auto P : r){
                    p.emplace_back(P);
                }
            }
        }

        debug(X, p, c);
        for (auto &&[x, y] : p) {
            ll cnt = 0;
            for (auto [P, C] : v) {
                ld time = C * dist(P, point(x, y));
                if (comp(X, time) >= 0) cnt++;
            }
            if (cnt >= k) return true;
        }

        return false;
    };

    ld ok = 1e9, ng = 0;
    rep(i,0,100){
        ld x = (ok + ng) / 2;
        if (check(x)) ok = x;
        else
            ng = x;
    }

    cout << fixed << setprecision(15);
    cout << ok << endl;
}