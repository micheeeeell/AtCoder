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
const long double eps = 1e-12;

template <typename T>
int comp(T a){
    if (abs(a) < eps) return 0;
    return a > 0 ? 1 : -1;
}

template <typename T>
int comp(T a, T b){
    // a > b -> 1, a < b -> -1
    return comp(a - b);
}
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
auto print = [](vector<string> &v) {
    for(auto &i : v){
        cout << i;
        if (&i != &v.back()) cout << "\n";
    }
    cout << "\n";
};

pair<bool, string> solve(string &s, ll n, ll k){
    vector<ll> d(s.size());
    rep(i,0,s.size()){
        d[i] = s[i] - '0';
    }
    ll m = s.size();

    vector memo(100, vector<ll>());
    queue<ll> que;
    rep(i, 0, m) {
        memo[d[i]] = {d[i]};
        que.emplace(d[i]);
    }
    while(!que.empty()){
        ll t = que.front();
        que.pop();
        auto v = memo[t];
        if (v.size() >= k) continue;
        for (auto i : d) {
            if(t + i < 100 && memo[t + i].empty()){
                v.emplace_back(i);
                memo[t + i] = v;
                v.pop_back();
                que.emplace(t + i);
            }
        }
    }

    debug(memo);

    map<Pll, pair<bool,ll>> mp;
    map <Pll, pair<Pll, vector<ll>>> mp2;
    vector<vector<ll>> ans;
    auto dfs = [&](auto self, ll t, ll M) -> pair<bool, ll> {
        if(t == 0){
            if(M == 0)
                return mp[{0, 0}] = {true, 0};
            else
                return {false, 0};
        }
        if(mp.count({t, M})){
            return mp[{t, M}];
        }
        ll res = INF;
        Pll nxt = {0, 0};
        vector<ll> v;
        ll b = 0;
        ll l = t % 10;

        while(l < 100){
            if(memo[l].empty()){
                l += 10;
                continue;
            }
            if (t < l) break;
            ll max_ = memo[l].size();
            if(max_ > M){
                l += 10;
                continue;
            }
            rep(i,0,M + 1){
                pair<bool, ll> tmp = self(self, (t - l) / 10, i);
                auto [ok, sum] = tmp;
                ll mm = max(i, max_);
                if (mm != M) continue;

                if (ok) {
                    b = 1;
                    if (chmin(res, sum + mm)){
                        nxt = {(t - l) / 10, i};
                        v = memo[l];
                    }
                }
            }

            l += 10;
        }
        mp2[{t, M}] = {nxt, v};
        return mp[{t, M}] = {b, res};
    };

    auto [ok, p] = dfs(dfs, n, k);
    if (!ok) return {false, {}};
    // debug(mp);
    // debug(mp2);
    ll N = n, K = k;
    while (N) {
        ans.emplace_back(mp2[{N, K}].second);
        auto p = mp2[{N, K}].first;
        N = p.first;
        K = p.second;
        debug(N, K);
    }
    debug(ans);
    vector<string> res(k, string(ans.size(), '0'));
    rep(i,0,ans.size()){
        rep(j, 0, ans[i].size()) {
            res[j][i] = char('0' + ans[i][j]);
        }
    }
    string res_str;
    for (auto &&t : res) {
        while (!t.empty() && t.back() == '0') t.pop_back();
        reverse(all(t));
        res_str += t;
        res_str += '+';
    }
    // print(res);
    res_str.pop_back();
    if (k == 1) {
        return {true, res_str};
    }
    else{
        return {true, res_str + '='};
    }
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;cin >> s;
    ll n; cin >> n;
    string res = string(500, '.');
    ll max_ = INF;
    rep(i, 0, 12) {
        auto [t, str] = solve(s, n, i);
        if (!t) continue;
        if(res.size() > str.size()){
            res = str;
        }
        debug(i, str);

    }

    cout << res << endl;
}