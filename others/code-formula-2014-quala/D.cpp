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
    string s;cin >> s;
    string k;cin >> k;
    vector<ll> used(36);
    ll m = k.size();
    rep(i,0,m){
        ll t = k[i] - '0';
        if(t < 0 || t > 9){
            t = k[i] - 'a';
            used[t + 10] = 1;
        }
        else{
            used[t] = 1;
        }
    }

    debug(used);

    vector<ll> app(36);
    ll n = s.size();
    rep(i,0,n){
        ll t = s[i] - '0';
        if(t < 0 || t > 9){
            t = s[i] - 'a';
            app[t + 10] = 1;
        }
        else {
            app[t] = 1;
        }
    }

    ll all = 0, feat = 0;
    rep(i,0,36){
        if(!used[i]){
            all++;
            if (app[i]) feat++;
        }
    }

    vector dp(feat + 10, vector(feat + 10, vector<ld>(all + 10, 0)));
    vector flag(feat + 10, vector(feat + 10, vector<ll>(all +10, 0)));

    auto dfs = [&](auto self, ll i, ll j, ll l) -> ld{
        debug(i, j, l);
        if (flag[i][j][l]) return dp[i][j][l];
        if(i == feat){
            flag[i][j][l] = 1;
            return ld(0);
        }
        if(j == 0){
            flag[i][j][l] = 1;
            dp[i][j][l] = self(self, i + 1, j, l) + ld(1);
            return dp[i][j][l];
        }
        ld res = 0;
        rep(ii, 0, l){
            if(ii == 0){
                res += (self(self, i + 1, j - 1, l - 1) + ld(1)) / ld(l);
            }
            else if(ii < j){
                res += (self(self, i, j - 1, l - 1) + ld(2)) / ld(l);
            }
            else{
                res += (self(self, i, j, l - 1) + ld(2)) / ld(l);
            }
            debug(ii, res);
        }

        flag[i][j][l] = 1;
        dp[i][j][l] = res;
        return dp[i][j][l];
    };
    debug(dfs(dfs, 0, feat, all), feat, all);
    cout << fixed << setprecision(15);
    cout << dfs(dfs, 0, feat, all) + ld(n - feat) << endl;
}