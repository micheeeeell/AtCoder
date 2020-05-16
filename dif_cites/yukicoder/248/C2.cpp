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

struct UnionFind {
    int n;
    vector<int> p, r;
    vector<ll> val;
    UnionFind(int _n = 0) : n(_n), p(n, -1), r(n, 1), val(n) {}
    void merge(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        int x = group(a), y = group(b);
        if (x == y) return; // same
        if (r[x] < r[y]) {
            p[x] = y;
            val[x] -= val[y];
        } else {
            p[y] = x;
            val[y] -= val[x];
            if (r[x] == r[y]) r[x]++;
        }
    }
    void add(int a, ll z) {
        val[group(a)] += z;
    }
    ll get(int a) {
        if (p[a] == -1) return val[a];
        return val[a] + get(p[a]);
    }
    int group(int a) {
        assert(0 <= a && a < n);
        if (p[a] == -1) return a;
        return group(p[a]);
    }
    bool same(int a, int b) {
        assert(0 <= a && a < n);
        assert(0 <= b && b < n);
        return group(a) == group(b);
    }

};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,q; cin >> n >> q;
    UnionFind uf(n);
    while(q--){
        ll t,a,b; cin >> t >> a >> b;
        if(t == 1){
            a--;b--;
            uf.merge(a,b);
        }
        if(t == 2){
            a--;
            uf.add(a, b);
        }
        if(t == 3){
            a--;
            cout << uf.get(a) << "\n";
        }
        debug(uf.val);
    }
}