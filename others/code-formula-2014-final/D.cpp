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
struct state{
    ll s,e;
    state(){}
    state(ll s, ll e):s(s), e(e){};
};
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    reps(i,n-1)h[i] += h[i-1];
    map<ll, ll> mp;
    vector<vector<state>> v(n);
    rep(i,n){
        ll m,s,e; cin >> m >> s >> e;
        mp[s] = 1, mp[e] = 1;
        m--;
        v[m].emplace_back(s, e);
    }
    ll id = 0;
    for(auto itr = mp.begin(); itr != mp.end();itr++){
        itr->second = id++;
    }
    ll m = mp.size();
    vector<ll> dp(m+1);
    rep(i,n)sort(all(v[i]), [](const auto &a, const auto &b){
        return a.e < b.e;
    });
    vector<ll> now(n);
    rep(i,m){
        if(i)chmax(dp[i], dp[i-1]);
        rep(j,n){
            while(now[j] < v[j].size() && i > mp[v[j][now[j]].s])now[j]++;
            if(now[j] == v[j].size())continue;
            debug(i,j,now[j]);
            ll et = v[j][now[j]].s;
            ll cnt = 0;
            for(ll tnow = now[j];tnow < v[j].size(); tnow++){
                if(et > v[j][tnow].s) continue;
                chmax(dp[mp[v[j][tnow].e]], dp[i] + h[cnt++]);
                et = v[j][tnow].e;
            }
        }
    debug(dp);
    }


    cout << dp[m-1] << endl;
}