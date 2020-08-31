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
    ll a,b,q; cin >> a >> b >> q;
    vector<ll> s(a);
    for(int i = 0; i < a; i++) cin >> s[i];
    vector<ll> t(b);
    for(int i = 0; i < b; i++) cin >> t[i];

    auto sr = [&](ll x) -> ll{
        ll sid = lower_bound(all(s), x) - s.begin();
        if(sid != a){
            return s[sid];
        }
        else return -1;
    };
    auto sl = [&](ll x) -> ll{
        ll sid = lower_bound(all(s), x) - s.begin();
        if(sid != a && s[sid] == x){
            return s[sid];
        }
        else if(sid != 0){
            sid--;
            return s[sid];
        }
        else{
            return -1;
        }
    };

    auto tr = [&](ll x) -> ll{
        ll id = lower_bound(all(t), x) - t.begin();
        if(id != b){
            return t[id];
        }
        else return -1;
    };
    auto tl = [&](ll x) -> ll{
        ll id = lower_bound(all(t), x) - t.begin();
        if(id != b && t[id] == x){
            return t[id];
        }
        else if(id != 0){
            id--;
            return t[id];
        }
        else{
            return -1;
        }
    };

    rep(i,0,q){
        ll x; cin >> x;
        ll ans = INF;
        ll tmp = 0;
        ll xt1 = sr(x), xt2;
        if(xt1 != -1){
            tmp += abs(xt1 - x);
            xt2 = tr(xt1);
            debug(x, xt1, xt2);
            if(xt2 != -1){
                tmp += abs(xt2 - xt1);
                chmin(ans, tmp);
            }
            tmp = abs(xt1 - x);
            xt2 = tl(xt1);
            debug(x, xt1, xt2);
            if(xt2 != -1) {
                tmp += abs(xt2 - xt1);
                chmin(ans, tmp);
            }
        }
        tmp = 0;
        xt1 = sl(x);
        if(xt1 != -1){
            tmp = abs(xt1 - x);
            xt2 = tr(xt1);
            debug(x, xt1, xt2);
            if(xt2 != -1) {
                tmp += abs(xt2 - xt1);
                chmin(ans, tmp);
            }

            tmp = abs(xt1 - x);
            xt2 = tl(xt1);
            debug(x, xt1, xt2);
            if(xt2 != -1) {
                tmp += abs(xt2 - xt1);
                chmin(ans, tmp);
            }
        }

        tmp = 0;
        xt1 = tr(x);
        if(xt1 != -1) {
            tmp = abs(xt1 - x);
            xt2 = sr(xt1);
            debug(x, xt1, xt2);
            if(xt2 != -1) {
                tmp += abs(xt2 - xt1);
                chmin(ans, tmp);
            }

            tmp = abs(xt1 - x);
            xt2 = sl(xt1);
            debug(x, xt1, xt2);
            if(xt2 != -1) {
                tmp += abs(xt2 - xt1);
                chmin(ans, tmp);
            }
        }
        tmp = 0;
        xt1 = tl(x);
        if(xt1 != -1) {
            tmp = abs(xt1 - x);
            xt2 = sr(xt1);
            debug(x, xt1, xt2);
            if(xt2 != -1) {
                tmp += abs(xt2 - xt1);
                chmin(ans, tmp);
            }

            tmp = abs(xt1 - x);
            xt2 = sl(xt1);
            debug(x, xt1, xt2);
            if(xt2 != -1) {
                tmp += abs(xt2 - xt1);
                chmin(ans, tmp);
            }
        }
        cout << ans << "\n";   
    }
}