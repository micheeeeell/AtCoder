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
constexpr ll n_max = 5e5+10;
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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int V;
vector<vector<ll>> g;
vector<vector<ll>> rg;
vector<ll> vs;
bool used[n_max];
vector<ll> cmp;
vector<vector<ll>> dag;
void add_edge(int f, int t){
    g[f].emplace_back(t);
    rg[t].emplace_back(f);
}

void dfs(ll v){
    used[v] = 1;
    for(auto &to : g[v]){
        if(!used[to]) dfs(to);
    }
    vs.emplace_back(v);
}

void rdfs(ll v, ll k){
    used[v] = 1;
    cmp[v] = k;
    for(auto &to : rg[v]){
        if(!used[to]) rdfs(to, k);
    }
}

int scc(){
    fill(used, used + n_max, 0);
    vs.clear();
    for(int v = 0; v < V; v++){
        if(!used[v])dfs(v);
    }
    fill(used, used + n_max, 0);
    ll k = 0;
    for(int i = vs.size()-1; i >= 0; i--){
        if(!used[vs[i]]) rdfs(vs[i], k++);
    }
    dag.resize(k);
    for(int i = 0; i < V; i++){
        for(auto &to : g[i]){
            int x = cmp[i], y = cmp[to];
            if(x == y)continue;
            dag[x].emplace_back(y);
        }
    }
    return k;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<ll> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    vector<ll> u(n);
    for(int i = 0; i < n; i++) cin >> u[i];
    rep(i,0,n){
        s[i]--;t[i]--;
    }
    auto node = [&](ll i, ll j, ll k){
        return 2 * (i * n + j) + k;
    };
    auto rev = [&](ll nd, ll* k) -> pair<ll, ll>{
        if(nd & 1){
            *k = 1;
            nd--;
        }
        else{
            *k = 0;
        }
        nd /= 2;
        return {nd / n, nd % n};
    };

    // ll k = 1;
    // debug(rev(10, &k));
    // debug(k);
    g.resize(n*n*2);rg.resize(n*n*2);cmp.resize(n*n*2);
    V = n * n * 2;
    rep(i,0,n)rep(j,0,n){
        ll f1, f2, t1, t2;

        if(u[i] == 0){
            f1 = f2 = 0;
            t1 = t2 = 1;
        }
        if(u[i] == 1){
            f1 = t1 = 1;
            f2 = t2 = 0;
        }
        if(u[i] == 2){
            f1 = t1 = 0;
            f2 = t2 = 1;
        }
        if(u[i] == 3){
            f1 = f2 = 1;
            t1 = t2 = 0;
        }
        // debug(s[i], j, t[i], node(s[i], j, f1), node(j, t[i], t1));
        add_edge(node(s[i], j, f1), node(j, t[i], t1));
        add_edge(node(j, t[i], f2), node(s[i], j, t2));
    }

    scc();
    debug(g);
    debug(cmp);

    rep(v,0,n*n){
        if(cmp[v*2] == cmp[v*2 + 1]){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<vector<ll>> ans(n, vector<ll>(n));
    ll k = 0;
    rep(v, 0, n*n){
        if(cmp[v*2] > cmp[v*2 + 1]){
            auto p = rev(v*2, &k);
            ans[p.first][p.second] = k;
        }
        else{
            auto p = rev(v * 2 + 1, &k);
            ans[p.first][p.second] = k;
        }
    }

    for(auto &vec : ans){
        for(auto &t : vec){
            cout << t;
            if(&t != &vec.back()) cout << " ";
            else cout << "\n";
        }
    }
}