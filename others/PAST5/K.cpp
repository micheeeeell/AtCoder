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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h = 4, w = 4;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    auto id = [](ll i, ll j) { return i * 4 + j; };
    auto rev = [](ll i) { return Pll{i / 4, i % 4}; };

    ll dx[] = {0,1,-1,0,0,1,-1,-1};
    ll dy[] = {1,0,0,-1,0,-1,1,-1};
    auto is_out = [&](ll x, ll y){
       if(x < 0 || x >= h || y < 0 || y >= w)return true;
       return false;
    };

    vector<ld> memo(1LL << 16, INF), flag(1LL << 16);
    memo[0] = 0;
    auto dfs = [&](auto self, ll mask) -> ld {
        if (flag[mask]) return memo[mask];
        if (__builtin_popcountll(mask) == 0) return 0;

        ld res = INF;
        rep(i, 0, h) rep(j, 0, w) {
            ll cnt = 0;
            ld tmp = 0;
            vector<ll> v;
            rep(k, 0, 4) {
                ll nx = i + dx[k], ny = j + dy[k];
                if (is_out(nx, ny)) continue;
                if ((mask >> id(nx, ny)) & 1) {
                    cnt++;
                    v.emplace_back(k);
                }
            }
            if ((mask >> id(i, j)) & 1) {
                cnt++;
                v.emplace_back(4);
            }
            if (cnt == 0) continue;

            for(auto k : v){
                ll nx = i + dx[k], ny = j + dy[k];
                tmp += self(self, mask ^ (1LL << id(nx, ny)));
            }
            chmin(res, (tmp + 5) / ld(cnt));
        }

        flag[mask] = 1;
        return memo[mask] = res;
    };

    ll mask = 0;
    rep(i,0,h)rep(j,0,w){
        if (s[i][j] == '#') mask |= (1LL << id(i, j));
    }
    cout << fixed << setprecision(15);
    cout << dfs(dfs, mask) << endl;
}