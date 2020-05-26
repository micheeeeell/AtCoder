// #define LOCAL
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
constexpr ll INF = numeric_limits<ll>::max()/4;
constexpr ll n_max = 17;
#define int ll

template <typename A, typename B>
string to_string(pair<A, B> p);
string to_string(const string &s) {return '"' + s + '"';}
string to_string(const char c) {return to_string((string) &c);}
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

vector<ld> e((1LL << n_max));
ll n;
long double dfs(ll mask){
    if(mask == 0)return 0.0;
    if(e[mask])return e[mask];
    ld ret = INF;
    rep(i,n_max){
        ld cnt = 0;
        ld temp = 0;
        for(int j = -1; j <= 1; j++){
            if(i+j >= 0){
                if((mask >> (i+j)) & 1){
                    temp += dfs(mask & ~(1LL << (i+j))) / 3.0;
                    debug(i, i+j);
                }
                else{
                    cnt++;
                }
            }
            else{
                cnt++;
            }
        }
        debug(mask, i, temp);
        if(cnt == 3)continue;
        ld coef;
        if(cnt == 0)coef = 1;
        else if(cnt == 1)coef = 1.5;
        else if(cnt == 2)coef = 3.0;
        chmin(ret, (temp + 1) * coef);
    }
    debug(mask, ret);
    return e[mask] = ret;
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n;
    ll mask = 0;
    rep(i,n){
        ll x; cin >> x;
        mask |= (1LL << x);
    }
    cout << fixed << setprecision(15);
    cout << dfs(mask) << endl;
}