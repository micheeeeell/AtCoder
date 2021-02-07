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
void print(vector<Pll> &a) {
    for (auto [u, v] : a) {
        cout << u + 1 << " " << v + 1 << "\n";
    }
}

vector<Pll> solve(ll h, ll w, vector<string> &s) {


    ll cnt = 0;
    rep(i, 0, h) rep(j, 0, w) {
        if (s[i][j] == '#') cnt++;
    }
    ll dx[] = {0, 1, -1, 0, 1, 1, -1, -1};
    ll dy[] = {1, 0, 0, -1, 1, -1, 1, -1};
    auto is_out = [&](ll x, ll y) {
        if (x < 0 || x >= h || y < 0 || y >= w) return true;
        return false;
    };
    vector used(h, vector<ll>(w));
    vector<Pll> ans;
    auto dfs = [&](auto self, Pll now, vector<Pll> &a) -> bool {
        auto [x, y] = now;
        bool nxt = false, res = false;
        a.emplace_back(now);
        used[x][y] = 1;
        rep(k, 0, 4) {
            ll nx = x + dx[k];
            ll ny = y + dy[k];
            if (is_out(nx, ny)) continue;
            if (s[nx][ny] == '.') continue;
            if (used[nx][ny]) continue;
            res |= self(self, Pll{nx, ny}, a);
            // nxt = true;
            if (res) break;
        }

        if (!nxt) {
            if (a.size() == cnt) {
                return true;
            } else {
                a.pop_back();
                used[x][y] = 0;
            }
        }

        return res;
    };

    rep(i, 0, h) rep(j, 0, w) {
        rep(ii, 0, h) rep(jj, 0, w) used[ii][jj] = 0;
        ans.clear();
        if (s[i][j] == '#') {
            if(dfs(dfs, Pll{i, j}, ans)){
                return ans;
            }
        }
    }
}

bool check(ll h, ll w, vector<string> &s, vector<Pll> &v) {
    ll cnt = 0;
    rep(i, 0, h) rep(j, 0, w) if (s[i][j] == '#') cnt++;
    bool res = true;
    res &= v.size() == cnt;
    ll n = v.size();
    rep(i,0,n - 1){
        ll t = abs(v[i].first - v[i + 1].first) +
               abs(v[i].second - v[i + 1].second);
        res &= t == 1;
    }
    vector used(h, vector<ll>(w));
    rep(i, 0, n) {
        auto [x, y] = v[i];
        res &= used[x][y] == 0;
        used[x][y] == 1;
        res &= s[x][y] == '#';
    }

    return res;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    random_device rnd;
    mt19937 mt(rnd());
    ll h = 4, w = 4;
    ll dx[] = {0, 1, -1, 0, 1, 1, -1, -1};
    ll dy[] = {1, 0, 0, -1, 1, -1, 1, -1};
    auto is_out = [&](ll x, ll y) {
        if (x < 0 || x >= h || y < 0 || y >= w) return true;
        return false;
    };
    rep(_, 0, 100) {
        vector<string> s(4, string(4, '.'));
        ll n = mt() % 13 + 1;
        ll x = mt() % 4, y = mt() % 4;
        rep(i,0,n){
            s[x][y] = '#';
            ll k = mt() % 4;
            bool nxt = false;
            ll cnt = 0;
            while (!nxt) {
                k = mt() % 4;
                ll nx = x + dx[k];
                ll ny = y + dy[k];
                cnt++;
                if (cnt > 10) break;
                if (is_out(nx, ny) || s[nx][ny] == '#') continue;
                nxt = true;
                x = nx;
                y = ny;
                
                
            }
        }
        // debug(n, s);
        auto a = solve(h, w, s);
        auto c = check(h, w, s, a);
        // debug(a, c);
        if(!c){
            debug(n, s);
            debug(a);
            return 0;
        }
    }
}