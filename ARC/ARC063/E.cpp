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

vector<vector<ll>> graph;
vector<Pll> dat;
void dfs(ll now, ll par = -1){
    if(par != -1){
        auto& [ma, mi] = dat[now];
        chmin(ma, dat[par].first+1);
        chmax(mi, dat[par].second-1);
    }

    for(auto &to : graph[now]){
        if(to == par) continue;
        dfs(to, now);
    }
}

void leaf_dfs(ll now, ll par = -1){
    for(auto to : graph[now]){
        if(to == par)continue;
        leaf_dfs(to, now);
        chmin(dat[now].first, dat[to].first+1);
        chmax(dat[now].second, dat[to].second-1);
    }
}

vector<ll> color;
bool cok = true;
void c_dfs(ll now, ll par = -1){
    ll c = color[now] ^ 1;
    for(auto &to : graph[now]){
        if(to == par)continue;
        if(color[to] != -1 && color[to] != c){
            cok = false;
            continue;
        }
        color[to] = c;
        c_dfs(to, now);
    }
}
void YES(bool ok){
    cout << (ok ? "Yes" : "No") << endl;
}

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << "\n";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}
vector<ll> ans;
void make_ans(ll now, ll par = -1){
    ll c = ans[now];
    for(auto &to : graph[now]){
        if(to == par)continue;
        if(c + 1 <= dat[to].first && c + 1 >= dat[to].second){
            ans[to] = c + 1;
        }
        else ans[to] = c - 1;
        make_ans(to, now);
    }
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    graph.resize(n);dat.resize(n, {INF, -INF});
    color.resize(n, -1);
    for(int i = 0; i < n-1; i++) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    ll k; cin >> k;
    ll root;
    ans.resize(n, -1);
    rep(i,0,k){
        ll v,p; cin >> v >> p;
        v--;
        dat[v] = {p, p};
        color[v] = p & 1;
        ans[v] = p;
        root = v;
    }

    c_dfs(root);
    debug(color);
    if(!cok){
        YES(false);
        return 0;
    }
    debug(root);
    dfs(root);
    debug(dat);
    leaf_dfs(root);
    debug(dat);

    bool ok = true;
    rep(i,0,n)ok &= dat[i].first >= dat[i].second;
    YES(ok);



    auto check = [&](vector<ll> &ans){
        bool ok = true;
        rep(i,0,n){
            for(auto &to : graph[i]){
                ok &= abs(ans[i] - ans[to]) == 1;
            }
        }

        return ok;
    };
    if(ok){
        
        make_ans(root);
        assert(check(ans));

        print(ans);
    }
}