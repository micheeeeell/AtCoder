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
constexpr ll INF = numeric_limits<ll>::max();
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
    vector<vector<ll>> graph(n);
    vector<ll> in(n);
    vector<Pll> edges(n - 1);
    for(int i = 0; i < n - 1; i++) {
        ll a,b;cin >> a >> b;
        a--;b--;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        in[a]++;
        in[b]++;
        edges[i] = {a, b};
    }
    vector<ll> dep(n);
    auto dfs = [&](auto self, ll now, ll par = -1)-> void {
        ll c = dep[now];
        for(auto &to : graph[now]) {
            if(to == par) continue;
            dep[to] = c + 1;
            self(self, to, now);
        }
    };
    dfs(dfs, 0);
    debug(dep);
    ll ma = *max_element(all(dep));
    ll r = 0;
    rep(i, 0, n) if(ma == dep[i]){
        r = i;
        break;
    }
    fill(all(dep), 0);
    dfs(dfs, r);
    debug(dep);
    ma = *max_element(all(dep));
    debug(ma, r);
    ll l = 0;
    rep(i,0,n)if(dep[i] == ma){
        l = i;
        break;
    }

    auto med = [&]() -> Pll{
        ll d = dep[l];

        queue<ll> que;
        que.emplace(l);
        while(1){
            ll t = que.front();
            que.pop();
            ll c = dep[t];
            for(auto &to : graph[t]){
                if(dep[to] == c - 1){
                    que.emplace(to);
                    if((d & 1) && c + c - 1 == d) return {t, to};
                    if((~d & 1) && c - 1 == d / 2) return {to, -1};
                }
            }
        }
    };
    vector<ll> dat(n, 1);
    auto bfs = [&](ll root, ll root2 = -1) -> void {
        queue<Pll> que;
        vector<ll> used(n);
        if(root2 != -1) {
            que.emplace(root, 1);
            que.emplace(root2, 1);
            used[root2] = 1;
            used[root] = 1;
            dat[0] = 2;
        }
        else{
            que.emplace(root, 0);
            used[root] = 1;
            dat[0] = in[root];
        }
        while(!que.empty()){
            auto [t, d] = que.front();
            chmax(dat[d], in[t] - 1);
            que.pop();
            for(auto &to : graph[t]){
                if(used[to]) continue;
                que.emplace(to, d + 1);
                used[to] = 1;
            }
        }
    };
    auto calc = [&]() {
        ll ans = 1;
        rep(i, 0, n) ans *= dat[i];
        fill(all(dat), 1);
        return ans;
    };
    ll ans = INF;
    if(ma & 1) {
        Pll p = med();

        debug(p, dep[p.first], dep[p.second]);
        bfs(p.first, p.second);
        debug(dat);
        ans = calc();
    } else {
        ll m = med().first;

        debug(m);
        bfs(m);
        chmin(ans, calc());
        for(auto &to : graph[m]){
            bfs(to, m);
            chmin(ans, calc());
        }
    }

    cout << (ma + 2) / 2 << " " << ans << "\n";
}