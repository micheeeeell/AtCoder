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

struct item{
    ll f, t, c;
    item(){}
    item(ll f, ll t, ll c):f(f), t(t), c(c){}
};
vector< vector< Pll >> graph;
vector<ll> color, dat;
Pll ans = {0, INF};
bool ok = true, is_two = true;
void c_dfs(ll now, ll pre = -1, ll c = 0){
    color[now] = c;
    for(auto &tp : graph[now]){
        if(tp.first == pre)continue;

        if(color[tp.first] == -1){
            c_dfs(tp.first, now, c ^ 1);
        }
        else if(color[tp.first] == c)
            is_two = false;
    }
}

void two_dfs(ll now, ll pre = -1, ll cost = 0, ll is_plus = 1){
    if(is_plus){
        chmax(ans.first, -cost);
    }
    else{
        chmin(ans.second, cost);
    }
    dat[now] = cost;

    for(auto &tp : graph[now]){
        if(tp.first == pre)continue;
        if(dat[tp.first] == -INF){
            two_dfs(tp.first, now, tp.second-cost, is_plus^1);
        }
        else{
            if(dat[tp.first] == tp.second-cost)continue;
            else ok = false;
        }
    }
}

ll one;
vector<ll> sv(n_max, -1);
void dfs(ll now, ll pre = -1, ll cost = 0, ll is_plus = 1){
    dat[now] = cost;
    sv[now] = is_plus;
    for(auto &tp : graph[now]){
        if(tp.first == pre)continue;
        if(dat[tp.first] == -INF){
            dfs(tp.first, now, tp.second-cost, is_plus^1);
        }
        else{
            if(sv[tp.first] != is_plus && dat[tp.first] != tp.second-cost)
                ok = false;
            if(sv[tp.first] == is_plus){
                one = (dat[tp.first] - tp.second + cost) / 2;
                if(is_plus)one = -one;
            }
            debug(tp.first, now, cost, dat[tp.first], one);
        }
    }
}

void simu(ll now, ll pre, ll t){
    dat[now] = t;
    for(auto &tp:graph[now]){
        if(tp.first == pre)continue;
        if(dat[tp.first] == -INF)simu(tp.first, now, tp.second-t);
    }
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vector<item> v(m);
    graph.resize(n);
    color.resize(n, -1);dat.resize(n, -INF);

    rep(i,0,m){
        ll f,t,c; cin >> f >> t >> c;
        f--;t--;
        graph[f].emplace_back(Pll(t, c));
        graph[t].emplace_back(Pll(f, c));
        v[i] = {f,t,c};
    }

    c_dfs(0);
    if(is_two){
        two_dfs(0);
        debug(ans, color, dat);
        if(ans.first > ans.second) ok = false;
    }
    else{
        dfs(0);
        debug(one);
        fill(all(dat), -INF);
        simu(0, -1, one);
        for(auto &it : v){
            if(dat[it.f] + dat[it.t] != it.c)ok = false;
            if(dat[it.f] <= 0 || dat[it.t] <= 0)ok = false;
            debug(it.f, it.t, it.c);
        }
        debug(dat, ok);
        ans = {0,2};
    }

    cout << (ok ? ans.second - ans.first - 1 : 0) << endl;

}