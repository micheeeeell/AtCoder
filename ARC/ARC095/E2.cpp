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

    vector<ll> v(h, -1);
    vector<ll> used(h);

    auto check = [&](vector<ll> &v) {
        debug(v);
        vector<string> t(h);
        rep(i, 0, h) t[i] = s[v[i]];
        vector<ll> r;
        vector<ll> wused(w);
        rep(i, 0, w) {
            if (wused[i]) continue;
            rep(j,i + 1, w){
                if (wused[j]) continue;
                bool tmp = true;
                rep(k,0,h){
                    tmp &= t[k][i] == t[h - k - 1][j];
                }
                if(tmp){
                    wused[i] = 1;
                    wused[j] = 1;
                    break;
                }
            }
            if(!wused[i]){
                r.emplace_back(i);
                wused[i] = 1;
            }
        }
        if (r.size() > 1) return false;
        if (r.size() == 0) return true;
        ll j = r.back();
        bool ok = true;
        rep(i,0,h){
            ok |= s[i][j] == s[h - i - 1][j];
        }
        debug(r, ok);
        return ok;
    };
    auto dfs = [&](auto self, ll i, ll c, ll e) {
        bool ok = false;
        if (c == e) {
            return check(v);
        }
        if(~c & 1){
            rep(j,0,h){
                if(!used[j]){
                    v[i] = j;
                    used[j] = 1;
                    ok |= self(self, i, c + 1, e);
                    used[j] = 0;
                    v[i] = -1;
                    break;
                }
            }
        }
        else{
            rep(j,0,h){
                if(!used[j]){
                    v[h - 1 - i] = j;
                    used[j] = 1;
                    ok |= self(self, i + 1, c + 1, e);
                    used[j] = 0;
                    v[h - 1 - i] = -1;
                }
            }
        }
        return ok;
    };

    auto YES = [](bool ok){
        cout << (ok ? "YES" : "NO") << endl;
    };
    bool ok = false;
    if(~h & 1){
        YES(dfs(dfs, 0, 0, h));
    }
    else{
        rep(i,0,h){
            used[i] = 1;
            v[h / 2] = i;
            ok |= dfs(dfs, 0, 0, h  - 1);
            used[i] = 0;
        }
        YES(ok);
    }
}