#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;
#define int ll

struct UnionFind{
private:
    vector<int> par;
    vector<int> rank;
    vector<int> sz;
    ll n;

public:
    //n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n): n(n) {
        par.resize(n,0);
        rank.resize(n,0);
        sz.resize(n,1);
        rep(i,n){
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
    bool same(int x, int y){
        return root(x) == root(y);
    }

    //xが属する集合のサイズを返す
    int size(int x){
        return sz[root(x)];
    }

    // 集合の数を返す
    int num_of_s(){
        // set<int> st;
        // rep(i,par.size()) st.insert(root(i));
        // return st.size();
        bitset<n_max> bs(0);
        rep(i,n)bs[root(i)] = 1;
        return bs.count();
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n; cin >> n;
    string s;cin >> s;
    string t;cin >> t;

    auto is_num = [](const char c){
        ll t = c - '0';
        return t < 10 && 0 <= t;
    };
    auto is_alp = [](const char c){
        ll t = c - 'A';
        return t < 26 && 0 <= t;
    };

    UnionFind uf(n+1);
    rep(i,n){
        if(is_num(s[i]))uf.unite(0, i+1);
    }
    rep(i,n)rep(j,n){
        if(s[i] == s[j] && is_alp(s[i]))uf.unite(i+1, j+1);
    }
    rep(i,n){
        if(is_num(t[i]))uf.unite(0, i+1);
    }
    rep(i,n)rep(j,n){
        if(t[i] == t[j] && is_alp(t[i]))uf.unite(i+1, j+1);
    }

    rep(i,n)rep(j,n){
        if(s[i] == t[j] && is_alp(s[i]))uf.unite(i+1, j+1);
    }

    ll cnt = uf.num_of_s() - 1;
    ll ans = 1;
    if(is_alp(s[0]) && uf.root(1) != 0)ans *= 9, cnt--;
    rep(i,cnt)ans *= 10;
    cout << ans << endl;
}