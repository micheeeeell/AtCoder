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
    ll w,h,q; cin >> w >> h >> q;
    vector<Pll> x, y;
    rep(i,0,q){
        ll t,d,p; cin >> t >> d >> p;
        p--;
        if(d == 0){
            x.emplace_back(t, p);
        }
        else{
            y.emplace_back(t, p);
        }
    }
    sort(all(x));sort(all(y));
    debug(x, y);
    vector<ll> dp(w);
    ll ans = 0;
    rep(i,0,x.size()){
        vector<ll> t;
        dp[x[i].second] = INF;
        t.emplace_back(x[i].second);
        while(i+1 < x.size() && x[i+1].first == x[i].first){
            dp[x[i+1].second] = INF;
            t.emplace_back(x[i+1].second);
            i++;
        }
        debug(t, dp);
        for(auto &j : t){
            if(j != 0)chmin(dp[j], dp[j-1] + 1);
        }
        for(auto it = t.rbegin(); it != t.rend(); it++){
            if(*it != w-1)chmin(dp[*it], dp[*it + 1] + 1);
        }
    }
    ans += *min_element(all(dp));
    dp.resize(h, 0);
    fill(all(dp), 0);
    rep(i,0,y.size()){
        vector<ll> t;
        dp[y[i].second] = INF;
        t.emplace_back(y[i].second);
        while(i+1 < y.size() && y[i+1].first == y[i].first){
            dp[y[i+1].second] = INF;
            t.emplace_back(y[i+1].second);
            i++;
        }
        debug(t,dp);
        for(auto &j : t){
            if(j != 0)chmin(dp[j], dp[j-1] + 1);
        }
        for(auto it = t.rbegin(); it != t.rend(); it++){
            if(*it != h-1)chmin(dp[*it], dp[*it + 1] + 1);
        }
    }
    ans += *min_element(all(dp));
    cout << (ans >= INF ? -1 : ans) << "\n";
}