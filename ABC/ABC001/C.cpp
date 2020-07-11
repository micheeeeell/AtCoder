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
    ll d,w; cin >> d >> w;
    vector<string> ds = {
        "N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW","C"
    };
    debug(ds.size(), ds);
    if(d <= 112){
        d = 0;
    }
    else{
        d -= 113;
        d /= 225;
        d = (d + 1) % 16;
    }
    ll v = 0;
    if(w < 3 * 6 - 3){
        d = 16;
        v = 0;
    }
    else if(w < 16 * 6 - 3){
        v = 1;
    }
    else if(w < 34 * 6 - 3){
        v = 2;
    }
    else if(w < 55 * 6 - 3){
        v = 3;
    }
    else if(w < 80 * 6 - 3){
        v = 4;
    }
    else if(w < 108 * 6 - 3){
        v = 5;
    }
    else if(w < 139 * 6 - 3){
        v = 6;
    }
    else if(w < 172 * 6 - 3){
        v = 7;
    }
    else if(w < 208 * 6 - 3){
        v = 8;
    }
    else if(w < 245 * 6 - 3){
        v = 9;
    }
    else if(w < 285 * 6 - 3){
        v = 10;
    }
    else if(w < 327 * 6 - 3){
        v = 11;
    }
    else v = 12;

    cout << ds[d] << " " << v << "\n";
}