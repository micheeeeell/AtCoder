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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<vector<ll>> graph(n);
    
    for(int i = 0; i < n-1; i++) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    if(n == 2){
        cout << (a[0] == a[1] ? "YES" : "NO") << endl;
        return 0;
    }
    bool ok = true;
    auto dfs = [&](auto self, ll now, ll pre = -1) -> ll{
        ll ma = -1, sum = 0, cnt = 0;
        ll t;
        for(auto &to : graph[now]){
            if(to == pre)continue;
            t = self(self, to, now);
            debug(now, to, t);
            sum += t;
            chmax(ma, t);
            cnt++;
        }
        if(cnt == 0){
            return a[now];
        }
        if(a[now] > sum) ok = false;
        if(a[now] < (sum + 1) / 2) ok = false;
        ll res = 2 * a[now] - sum;
        ll m = 2 * ma - sum;
        if(m <= res)return res;
        ok = false;
        return -1;
    };
    ll root = 0;
    rep(i,0,n){
        if(graph[i].size() > 1){
            root = i;
            break;
        }
    }
    ok &= dfs(dfs, root) == 0;

    cout << (ok ? "YES" : "NO") << endl;
}