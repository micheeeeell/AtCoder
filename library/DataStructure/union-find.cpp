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


template< typename T>
struct UnionFind{
    private:
    vector<T> par;
    vector<T> rank;
    vector<T> sz;
    int n;

    public:
    //n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n): n(n) {
        par.resize(n,0);
        rank.resize(n,0);
        sz.resize(n,1);
        for(int i = 0; i < n; i++){
            par[i] = i;
        }
    }

    //木の根を求める
    int root(int x){
        if(par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    //xとyの属する集合を併合
    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        
        if(rank[x] < rank[y]){
            swap(x,y);
        }
        
        par[y] = x;
        sz[x] += sz[y];
        if(rank[x] == rank[y]) rank[x]++; 
    }

    //xとyが同じ集合に属するか否か
    bool issame(int x, int y){
        return root(x) == root(y);
    }

    //xが属する集合のサイズを返す
    int size(int x){
        return sz[root(x)];
    }

    // 集合の数を返す
    int num_of_s(){
        vector<int> cnt(n);
        int ans = 0;
        for(int i = 0; i < n;i++){
            if(!cnt[root(i)])ans++, cnt[root(i)] = 1;
        }
        return ans;
    }
};

template<class Abel>
struct WeightedUnionFind{
    vector<int> par;
    vector<int> rank;
    vector<Abel> diff_weight;
    int n;
    Abel M0;

    WeightedUnionFind(int n, Abel M0 = 0):n(n), M0(M0){
        init(n, M0);
    }

    void init(int n, Abel M0 = 0){
        par.resize(n);
        rank.resize(n);
        diff_weight.resize(n);
        for(int i = 0; i < n; i++){
            par[i] = i;
            rank[i] = 0;
            diff_weight[i] = M0;
        }
    }

    int root(int x){
        if(par[x] == x) return x;
        else{
            int r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(int x){
        root(x);
        return diff_weight[x];
    }

    // w(x) + w == w(y)となるように併合
    bool unite(int x, int y, Abel &w){
        w += weight(x) - weight(y);
        x = root(x);
        y = root(y);
        if(x == y) return w == 0;

        if(rank[x] < rank[y]){
            swap(x, y);
            w = -w;
        }

        par[y] = x;
        diff_weight[y] = w;
        if(rank[x] == rank[y])rank[x]++;
        return true;
    }

    bool issame(int x, int y){
        return root(x) == root(y);
    }


    Abel diff(int x, int y){
        return weight(y) - weight(x);
    }
};

signed main(){
    while(true){
        ll n,m; cin >> n >> m;
        if(n == 0 && m == 0)return 0;
        WeightedUnionFind<ll> uf(n);
        rep(i,0,m){
            string s;cin >> s;
            if(s == "!"){
                ll a,b,w; cin >> a >> b >> w;
                a--;b--;
                uf.unite(a, b, w);
            }
            else{
                ll a,b; cin >> a >> b;
                a--;b--;
                if(uf.issame(a, b))cout << uf.diff(a, b) << "\n";
                else cout << "UNKNOWN" << "\n";
            }
        }
    }
}