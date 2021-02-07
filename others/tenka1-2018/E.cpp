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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w; cin >> h >> w;
    vector<string> s(h);
    rep(i, 0, h) cin >> s[i];
    vector sum(h + 1, vector<ll>(w + 1));
    rep(i,0,h)rep(j,0,w){
        sum[i + 1][j + 1] = sum[i][j] + (s[i][j] == '#');
    }

    ll dx[] = {0,1,-1,0,1,1,-1,-1};
    ll dy[] = {1,0,0,-1,1,-1,1,-1};
    auto is_out = [&](ll x, ll y){
       if(x < 0 || x >= h || y < 0 || y >= w)return true;
       return false;
    };

    ll ans = 0;
    auto calc = [&](ll x, ll y) {
        vector<Pll> v;
        while(!is_out(x, y)){
            if(s[x][y] == '#'){
                v.emplace_back(Pll(x, y));
            }
            x++;
            y++;
        }
        ll m = v.size();
        ll res = 0;
        rep(i, 0, m) rep(j, i + 1, m) {
            auto [x1, y1] = v[i];
            auto [x2, y2] = v[j];
            ll d = x2 - x1;

            ll d1 = (x1 + 1) - (y2 + d + 1);
            ll d2 = (x2 + d + 1) - (y1 + 1);

            debug(x1, y1, x2, y2, d, d1, d2);
            if (min(w, y2 + d + 1) + d1 <= h && min(w, y2 + d + 1) + d1 >= 0){
                ans += sum[min(w, y2 + d + 1) + d1][min(w, y2 + d + 1)] -
                       sum[max(0LL, x1 - d)][max(0LL, x1 - d) - d1];
            }
            if (min(h, x2 + d + 1) - d2 <= w && min(h, x2 + d + 1) - d2 >= 0){
                ans += sum[min(h, x2 + d + 1)][min(h, x2 + d + 1) - d2] -
                       sum[max(0LL, y1 - d) + d2][max(0LL, y1 - d)];
            }

            if (!is_out(x1, y2 + d)) res += s[x1][y2 + d] == '#';
            if (!is_out(x1 - d, y2)) res += s[x1 - d][y2] == '#';
            if (!is_out(x2 + d, y1)) res += s[x2 + d][y1] == '#';
            if (!is_out(x2, y1 - d)) res += s[x2][y1 - d] == '#';
            debug(ans);
        }
        return res;
    };

    rep(i,0,h){
        calc(i, 0);
        debug(ans);
    }
    rep(j,1,w){
        calc(0, j);
    }
    debug(ans);

    vector<string> sd(w, string(h, '.'));
    vector sumd(w + 1, vector<ll>(h + 1));
    rep(i,0,h)rep(j,0,w){
        sd[j][h - i - 1] = s[i][j];
    }
    rep(i,0,w)rep(j,0,h){
        sumd[i + 1][j + 1] = sumd[i][j] + (sd[i][j] == '#');
    }
    swap(s, sd);
    swap(sum, sumd);
    swap(h, w);
    debug(s, sum);
    rep(i, 0, h) {
        ll r = calc(i, 0);
        ans -= r;
        debug(ans);
    }
    rep(j, 1, w) {
        ll r = calc(0, j);
        ans -= r;
    }
    debug(ans);

    cout << ans << endl;
}