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

template <typename T>
struct UnionFind {
   private:
    vector<T> par;
    vector<T> rank;
    vector<T> sz;
    int n;

   public:
    // n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n) : n(n) {
        par.resize(n, 0);
        rank.resize(n, 0);
        sz.resize(n, 1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    //木の根を求める
    int root(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = root(par[x]);
    }

    // xとyの属する集合を併合
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            swap(x, y);
        }

        par[y] = x;
        sz[x] += sz[y];
        if (rank[x] == rank[y]) rank[x]++;
    }

    // xとyが同じ集合に属するか否か
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // xが属する集合のサイズを返す
    int size(int x) {
        return sz[root(x)];
    }

    // 集合の数を返す
    int num_of_s() {
        vector<int> cnt(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!cnt[root(i)]) ans++, cnt[root(i)] = 1;
        }
        return ans;
    }
};


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll id,n,k; cin >> id >> n >> k;
    vector<string> v(n);
    rep(i, 0, n) cin >> v[i];

    auto idx = [&](ll i, ll j) { return i * n + j; };
    auto rev = [&](ll i) -> Pll { return {i / n, i % n}; };
    ll dx[] = {0,1,-1,0};
    ll dy[] = {1,0,0,-1};
    auto is_out = [&](ll x, ll y){
       if(x < 0 || x >= n || y < 0 || y >= n)return true;
       return false;
    };


    UnionFind<ll> uf(n * n);
    vector<ll> col(n * n);
    rep(i, 0, n) rep(j, 0, n) {
        rep(k,0,2){
            ll nx = i + dx[k], ny = j + dy[k];
            if (is_out(nx, ny)) continue;
            if(v[i][j] == v[nx][ny]){
                uf.unite(idx(i, j), idx(nx, ny));
            }
        }
        col[idx(i, j)] = v[i][j] - '0';
    }
    vector<tuple<ll,ll, ll>> query;

    // algo
    // 自分の隣を見て自分と異なる連結成分かつ同じ色のものが複数ある場合はその色にする
    rep(_, 0,3){
        rep(i,0,n)rep(j,0,n){
            ll root = uf.root(idx(i, j));
            ll tc = col[root];
            vector<ll> cnt(10);
            rep(k, 0, 4) {
                ll nx = i + dx[k], ny = j + dy[k];
                if (is_out(nx, ny)) continue;
                ll nc = col[uf.root(idx(nx, ny))];
                if (tc == nc) continue;
                cnt[nc]++;
            }
            rep(k,0,10)if(cnt[k] > 1){
                query.emplace_back(i, j, k);
                rep(l, 0, 4) {
                    ll nx = i + dx[l], ny = j + dy[l];
                    if (is_out(nx, ny)) continue;
                    ll nc = col[uf.root(idx(nx, ny))];
                    if (k != nc) continue;
                    uf.unite(idx(i, j), idx(nx, ny));
                }
                col[uf.root(idx(i, j))] = k;
            }
        }
    }
    debug("test", query.size());
    // 各色の現在の総数を数える
    ll color = 0;
    {
        vector<ll> cnt(10);
        vector<ll> used(n * n);
        rep(i, 0, n) rep(j, 0, n) {
            ll root = uf.root(idx(i, j));
            if (used[root]) continue;
            ll t = col[root];
            cnt[t]++;
            used[root] = 1;
        }
        ll ma = 0;
        rep(i, 0, 10) {
            if (chmax(ma, cnt[i])) color = i;
        }
        debug(cnt);
    }

    vector<ll> used(n * n);
    rep(i,0,n)rep(j,0,n){
        ll root = uf.root(idx(i, j));
        if (used[root]) continue;
        // auto [x, y] = rev(root);
        // if (v[x][y] == ('0' + color)) continue;
        if (col[root] == color) continue;
        used[root] = 1;
        query.emplace_back(i, j, color);
    }

    cout << query.size() << endl;
    for (auto [x, y, c] : query){
        cout << x + 1 << " " << y + 1 << " " << c << "\n";
    }
}