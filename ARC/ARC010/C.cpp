#define LOCAL
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
constexpr ll n_max = 2e5+10;
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

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    ll y,z; cin >> y >> z;
    vvvl dp(n+1, vvl(1LL << m, vl(m, -INF)));
    map<char, ll> mp;
    vector<ll> p(m);
    rep(i,m){
        char c;cin >> c;
        ll t; cin >> t;
        mp[c] = i;
        p[i] = t;
    }
    string s;cin >> s;
    rep(i,m)dp[0][0][i] = 0;
    rep(i,n){
        ll t = mp[s[i]];
        rep(j, (1LL << m)){
            rep(k, m){
                if(dp[i][j][k] == -INF)continue;
                chmax(dp[i+1][j][k], dp[i][j][k]);
                if((j >> t) & 1){
                    if(k == t)chmax(dp[i+1][j][t], dp[i][j][k] + y + p[t]);
                    else{
                        chmax(dp[i+1][j][t], dp[i][j][k] + p[t]);
                    }
                }
                else{
                    chmax(dp[i+1][j | (1LL << t)][t], dp[i][j][k] + p[t]);
                }
            }
        }
        // print(i+1);
        // print(dp[i+1]);
        // print();
    }

    ll ans = 0;
    rep(i, (1LL << m))rep(j,m){
        if(dp[n][i][j] == -INF)continue;
        if(i == (1LL << m) - 1){
            chmax(ans, dp[n][i][j] + z);
        }
        else{
            chmax(ans, dp[n][i][j]);
        }
    }

    cout << ans << endl;
}