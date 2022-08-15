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

// Sparse Table
// 最小値、最大値で使える（区間が被るので加算などは無理）
template<class MeetSemiLattice> 
struct SparseTable {
    using F = function<MeetSemiLattice(MeetSemiLattice, MeetSemiLattice)>;
    F f;
    MeetSemiLattice M0;
    vector<vector<MeetSemiLattice> > dat;
    vector<int> height;
    
    SparseTable(const int n, const F f, const MeetSemiLattice &M0): f(f), M0(M0){
        init(vector<MeetSemiLattice>(n, M0));
    }
    SparseTable(const F f, const MeetSemiLattice &M0, 
                const vector<MeetSemiLattice> &vec):f(f), M0(M0) {
        init(vec);
    }
    void init(const vector<MeetSemiLattice> &vec) {
        int n = (int)vec.size(), h = 0;
        while ((1<<h) < n) ++h;
        dat.assign(h, vector<MeetSemiLattice>(1<<h, M0));
        height.assign(n+1, 0);
        for (int i = 2; i <= n; i++) height[i] = height[i>>1]+1;
        for (int i = 0; i < n; ++i) dat[0][i] = vec[i];
        for (int i = 1; i < h; ++i)
            for (int j = 0; j < n; ++j)
                dat[i][j] = f(dat[i-1][j], dat[i-1][min(j+(1<<(i-1)),n-1)]);
    }

    MeetSemiLattice get(int a, int b) {
        return f(dat[height[b-a]][a], dat[height[b-a]][b-(1<<height[b-a])]);
    }
};


signed main(){
    vector<int> vec = {2,3,42,6,3,792,465,654,2,41,244,3};
    ll n = vec.size();
    auto f = [](ll a, ll b) { return min(a, b); };
    SparseTable<ll> st(f, 0, vec);
    st.init(vec);
    int len = vec.size();

    rep(i,0,n)rep(j,i + 1, n + 1){
        debug(i, j, st.get(i, j));
    }
}