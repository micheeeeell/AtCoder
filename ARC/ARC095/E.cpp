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

void YES(bool ok) {
    cout << (ok ? "YES" : "NO") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll h,w; cin >> h >> w;
    vector<string> v(h);
    rep(i,0,h)cin >> v[i];
    auto solve = [](vector<string> &s) {
        ll h = s.size(), w = s[0].size();
        vector table(h, vector<ll>(h));
        vector cnt(h, vector<ll>(26));
        rep(i,0,h)rep(j,0,w){
            ll t = s[i][j] - 'a';
            cnt[i][t]++;
        }
        rep(i,0,h)rep(j,i + 1, h){
            if(cnt[i] == cnt[j]){
                table[i][j] = 1;
                table[j][i] = 1;
            }
        }

        debug(table);

        vector<ll> ok(h);
        rep(i,0, h){
            ll tmp = 0;
            rep(j,0,26){
                if (cnt[i][j] & 1) tmp++;
            }
            ok[i] = tmp <= 1;
        }

        vector<ll> dp((1LL << h));
        dp[0] = 1;
        rep(i,0,1LL << h){
            if (__builtin_popcountll(i) & 1) continue;

            if(__builtin_popcountll(i) == 2){
                rep(ii, 0, h) rep(jj, ii + 1, h) {
                    if (((i >> ii) & 1) && ((i >> jj) & 1)){
                         dp[i] = table[ii][jj];
                    }
                }
                continue;
            }
            for(ll t = i; ; t = (t - 1) & i){
                if(t == 0)break;
                dp[i] |= dp[t] && dp[i ^ t];
            }
        }

        debug(s, dp);
        bool res = false;
        ll mask = (1LL << h) - 1;
        if (h & 1) {
            rep(i,0,h){
                if (!ok[i]) continue;
                res |= dp[mask ^ (1LL << i)];
            }
        }
        else
            res = dp[mask];
        debug(res, h, mask);
        return res;
    };

    vector<string> v2(w, string(h, '.'));
    rep(i,0,h)rep(j,0,w){
        v2[j][i] = v[i][j];
    }

    YES(solve(v) && solve(v2));
}

