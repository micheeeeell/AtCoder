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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w; cin >> h >> w;
    mf_graph<int> graph(h * w + 2);
    ll dx[] = {0,0,1,-1};
    ll dy[] = {1,-1,0,0};
    auto is_out = [&](ll x, ll y){
    if(x < 0 || x >= h || y < 0 || y >= w)return true;
    return false;
    };

    auto id = [&](ll x, ll y){
        return x * w + y;
    };
    auto rev = [&](const ll id) -> const Pll{
        Pll res;
        res.first = id / w;
        res.second = id % w;
        return res;
    };
    ll st = h * w, ed = h * w + 1;
    vector<string> s(h);
    rep(i,0,h)cin >> s[i];
    rep(i,0,h)rep(j,0,w){
        if(s[i][j] == '#')continue;
        if((i + j) & 1){
            rep(k,0,4){
                ll nx = i + dx[k], ny = j + dy[k];
                if(is_out(nx, ny))continue;
                if(s[nx][ny] == '#')continue;
                graph.add_edge(id(i,j), id(nx, ny), 1);
            }
        }
        if((i + j) & 1)graph.add_edge(st, id(i,j), 1);
        else graph.add_edge(id(i,j), ed, 1);
    }

    ll ans = graph.flow(st, ed);
    debug(ans);
    auto edges = graph.edges();

    for(auto &i : edges){
        debug(i.from, i.to, i.cap, i.flow);
        if(i.from >= h*w || i.to >= h*w || i.flow == 0)continue;
        auto [fx, fy] = rev(i.from);
        auto [tx, ty] = rev(i.to);
        if(fx > tx || fy > ty){
            swap(fx, tx);
            swap(fy, ty);
        }
        if(fx == tx){
            s[fx][fy] = '>';
            s[tx][ty] = '<';
        }
        else{
            s[fx][fy] = 'v';
            s[tx][ty] = '^';
        }
        debug(fx, fy,tx,ty);
        // print(s);
    }
    cout << ans << "\n";
    print(s);
}