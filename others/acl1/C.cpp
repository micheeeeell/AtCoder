#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vector<string> s(n);
    rep(i,0,n){
        cin >> s[i];
    }
    mcf_graph<ll, ll> g(n * m + 2);
    ll f = n * m, t = f + 1;
    ll dx[] = {0,1,-1,0};
    ll dy[] = {1,0,0,-1};
    auto is_out = [&](ll x, ll y){
       if(x < 0 || x >= n || y < 0 || y >= m)return true;
       return false;
    };
    auto id = [&](ll i, ll j) { return i * m + j; };
    
    ll base = 300, cnt = 0;
    auto bfs = [&](ll i, ll j) {
        if (s[i][j] != 'o') return;
        queue<Pll> que;
        que.emplace(i, j);
        while(!que.empty()){
            auto [x, y] = que.front();
            que.pop();
            rep(k,0,2){
                ll nx = x + dx[k], ny = y + dy[k];
                if (is_out(nx, ny) || s[nx][ny] == '#') continue;
                g.add_edge(id(i, j), id(nx, ny), 1, base - (nx - i) - (ny - j));
                que.emplace(nx, ny);
            }
        }
        return;
    };

    rep(i,0,n)rep(j,0,m){
        bfs(i, j);
        if(s[i][j] == 'o'){
            g.add_edge(f, id(i, j), 1, 0);
            g.add_edge(id(i, j), t, 1, base);
            cnt++;
        } else {
            g.add_edge(id(i, j), t, 1, 0);
        }
    }
    auto [cap, cost] = g.flow(f, t, cnt);

    debug(cap, cost);
    // for(auto e : g.edges()){
    //     if(e.flow){
    //         debug(e.from, e.to, e.cap, e.flow, e.cost);
    //     }
    // }
    cout << base * cap - cost << "\n";
}