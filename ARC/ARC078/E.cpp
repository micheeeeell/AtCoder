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

template<class T>
bool query(T x){
    cout << "? " << x << endl;
    char ret; cin >> ret;
    return ret == 'Y';
}

template<class T>
void ans(T x){
    cout << "! " << x << endl;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll x = 1e10-1;
    debug(x);
    ll ma = 0;
    rep(i,1,10){
        string s = to_string(i);
        s += to_string(x);
        debug(s);
        bool t = query(s);
        if(t){
            ma = i; break;
        }
    }
    x = 1e10;
    x *= ma;
    debug(x);
    // N = ma * 10^iのパターン
    if(query(x)){
        if(ma == 1){
            x = 2e10;
            while(x && query(x)){
                x /= 10;
            }
            if(x == 0){
                ans(1);
                return 0;
            }
            else{
                ans(x*10/2);
                return 0;
            }
        }
        else{
            x = (ma-1) * 1e10;
            while(!query(x)){
                x /= 10;
            }
            x = (x / (ma-1)) * ma;
            ans(x);
            return 0;
        }

    }
    x /= 10;
    while(!query(x)){
        x /= 10;
    }

    ll ng = x, ok = (x / ma) * (ma+1)-1;
    debug(ok, ng);
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if(query(to_string(mid) + '0'))ok = mid;
        else ng = mid;
    }

    ans(ok);
}