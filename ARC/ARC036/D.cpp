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

    vector<T> get_par(){
        return par;
    }
};

void YES(bool ok){
    cout << (ok ? "YES" : "NO") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,q; cin >> n >> q;
    UnionFind<ll> uf(n), syu(n);
    vector<ll> is_bip(n, 1), g(n, -1);
    rep(i,0,q){
        ll w,x,y; cin >> w >> x >> y;
        ll z; cin >> z;
        z %= 2;
        x--;y--;
        if(w == 2){
            if(!uf.issame(x, y)){
                YES(false);
                continue;
            }
            if(!is_bip[uf.root(x)]){
                YES(true);
                continue;
            }

            if(syu.issame(x, y)){
                YES(true);
                continue;
            }
            else{
                YES(false);
                continue;
            }
        }
        else{
            
            if(uf.issame(x, y)){    // 同じ連結成分内
                // 二部グラフでないなら何もしない
                if(!is_bip[uf.root(x)])continue;
                // z=0なら同じ縮約成分、違うなら違う縮約成分でOK
                if(syu.issame(x, y) && z == 0)continue;
                if((!syu.issame(x, y)) && z == 1)continue;
                is_bip[uf.root(x)] = 0;
            }
            else{
                // どちらかが二部グラフでない場合
                if((!is_bip[uf.root(x)]) || (!is_bip[uf.root(y)])){
                    uf.unite(x, y);
                    is_bip[uf.root(x)] = 0;
                }
                else {
                    if(z == 0){
                        ll gx = g[syu.root(x)], gy = g[syu.root(y)];
                        if(gx != -1 && gy != -1){
                            uf.unite(x, y);
                            syu.unite(x, y);
                            syu.unite(gx, gy);
                            g[syu.root(x)] = syu.root(gx);
                            g[syu.root(gx)] = syu.root(x);
                        }
                        else{
                            uf.unite(x, y);
                            syu.unite(x, y);
                            if(gx != -1){
                                g[syu.root(x)] = syu.root(gx);
                                g[syu.root(gx)] = syu.root(x);
                            }
                            if(gy != -1){
                                g[syu.root(x)] = syu.root(gy);
                                g[syu.root(gy)] = syu.root(x);
                            }
                        }
                    }
                    else{
                        ll gx = g[syu.root(x)], gy = g[syu.root(y)];
                        if(gx != -1){
                            syu.unite(gx, y);
                        }
                        if(gy != -1){
                            syu.unite(gy, x);
                        }
                        uf.unite(x, y);
                        g[syu.root(x)] = syu.root(y);
                        g[syu.root(y)] = syu.root(x);
                    }
                }
            }
        }

        debug(g);
        debug(uf.get_par(), syu.get_par(), is_bip);
    }
}