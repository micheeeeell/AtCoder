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

ld klab(vector<Pll> &v){
    ld res = 0;
    ll n = v.size();
    vector<ll> used(n);
    ll cnt = 1;
    ll now = 0;
    used[0] = 1;
    using Pld = pair<ld, ll>;
    while (cnt < n) {
        // debug(cnt, now);
        Pld p = {INF, -1};
        rep(i,0,n){
            if (used[i]) continue;
            chmin(p, Pld{hypot(v[now].first - v[i].first,
                               v[now].second - v[i].second), i});
        }
        res += p.first;
        now = p.second;
        used[now] = 1;
        cnt++;
        // debug(cnt, now, res, p);
    }

    return res;
}
ld taka(vector<Pll> &v) {
    ld res = 0;
    ll n = v.size();
    vector<ll> used(n);
    ll cnt = 1;
    ll now = 0;
    used[0] = 1;
    using Pld = pair<ld, ll>;

    while (cnt < n) {
        Pld f = {INF, -1}, s = {INF, -1};

        rep(i, 0, n) {
            if (used[i]) continue;
            chmin(s, Pld{hypot(v[now].first - v[i].first,
                               v[now].second - v[i].second),
                         i});
            if (f > s) swap(f, s);
        }
        if(cnt >= n - 2){
            res += f.first;
            now = f.second;
        }
        else {
            res += s.first;
            now = s.second;
        }

        used[now] = 1;
        cnt++;
        // debug(cnt, now, res, f, s);
    }

    return res;
}

void print(vector<Pll> &V){
    for(auto p : V){
        cout << p.first << " " << p.second << "\n";
    }
}
void test(){
    ll n;
    // cin >> n;
    n = 49;
    vector<Pll> v;
    rep(i,0,n){
        v.emplace_back(Pll{0, i});
    }
    rep(i,0,n){
        v.emplace_back(Pll{1, i});
    }
    v.emplace_back(Pll{0, 49});
    v.emplace_back(Pll{1, 49});

    ld k = klab(v);
    ld t = taka(v);
    debug(k, t, t - k, v.size());
    cout << v.size() << endl;
    print(v);
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    test();
}