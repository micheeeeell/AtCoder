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

void YES(bool ok){
    cout << (ok ? "Yes" : "No") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    vector<vector<ll>> graph(n);
    vector<ll> in(n);
    for(int i = 0; i < m; i++) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        in[a]++;in[b]++;
    }
    bool ok = true;
    vector<ll> fc;
    ll oc = 0;
    rep(i,0,n){
        ok &= (~in[i] & 1);
        if(in[i] == 4)fc.emplace_back(i);
        if(in[i] == 6)oc++;
    }

    if(!ok){
        YES(false);
        return 0;
    }
    
    if(oc || fc.size() >= 3){
        YES(true);
        return 0;
    }

    if(fc.size() <= 1){
        YES(false);
        return 0;
    }

    ll st = fc[0], ed = fc[1];
    assert(fc.size() == 2);
    vector<ll> used(n);
    auto dfs = [&](auto self, ll now, ll pre = -1)->void{
        if(pre != -1)used[now] = 1;
        for(auto k&to : graph[now]){
            if(to == pre)continue;
            if(to == ed)continue;
            if(used[to])continue;
            self(self, to, now);
        }
    };

    dfs(dfs, st);
    debug(used, st, ed);
    if(used[st]){
        YES(true);
    }
    else{
        YES(false);
    }
}