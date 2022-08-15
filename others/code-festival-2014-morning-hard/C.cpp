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
struct BIT2D {
    int h, w;
    vector<vector<T>> v;

    BIT2D(const int h, const int w) : h(h), w(w), v(h + 1, vector<T>(w + 1)){};
    BIT2D(const int h, const int w, const vector<vector<T>> &vec)
        : h(h), w(w), v(h + 1, vector<T>(w + 1)) {
        init(vec);
    }

    void init(const vector<vector<T>> &vec) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                add(i + 1, j + 1, vec[i][j]);
            }
        }
    }

    // x,yは1-indexedに注意
    void add(int x, int y, T val) {
        while (x <= h) {
            int y_ = y;
            while (y_ <= w) {
                v[x][y_] += val;
                y_ += y_ & -y_;
            }
            x += x & -x;
        }
    }

    T get(int x, int y) {
        T sum = 0;
        while (x > 0) {
            int y_ = y;
            while (y_ > 0) {
                sum += v[x][y_];
                y_ -= y_ & -y_;
            }
            x -= x & -x;
        }

        return sum;
    }

    T get(int x1, int y1, int x2, int y2) {
        return get(x2, y2) - get(x1, y2) - get(x2, y1) + get(x1, y1);
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w,k; cin >> h >> w >> k;
    vector v(h, vector<ll>(w));
    rep(i, 0, h) rep(j, 0, w){
        cin >> v[i][j];
        v[i][j]--;
    }
    vector<BIT2D<ll>> bit(k, BIT2D<ll>(h, w));
    rep(i,0,h)rep(j,0,w){
        bit[v[i][j]].add(i + 1, j + 1, 1);
    }

    ll q;
    cin >> q;
    rep(i,0,q){
        ll t; cin >> t;
        ll x1,y1; cin >> x1 >> y1;
        ll x2,y2; cin >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;

        if (t == 1) {

            ll k1 = v[x1][y1];
            ll k2 = v[x2][y2];
            bit[k1].add(x1 + 1, y1 + 1, -1);
            bit[k1].add(x2 + 1, y2 + 1, 1);
            bit[k2].add(x1 + 1, y1 + 1, 1);
            bit[k2].add(x2 + 1, y2 + 1, -1);
            swap(v[x1][y1], v[x2][y2]);
        }
        else{
            Pll ans = {0, 0};
            rep(j,0,k){
                Pll p = {bit[j].get(x1, y1, x2 + 1, y2 + 1), j + 1};
                debug(p);
                chmax(ans, p);
            }
            cout << ans.second << " " << ans.first << "\n";
        }
    }
}