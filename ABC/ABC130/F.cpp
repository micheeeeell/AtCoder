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

struct item{
    double x, y;
    char c;
    item(){}
    item(double x, double y, char c):x(x), y(y), c(c){}
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<item> v(n);
    rep(i,0,n){
        double x,y; cin >> x >> y;
        char c; cin >> c;
        v[i] = {x, y, c};
    }
    auto calc = [&](double k){
        double xmin = INF, xmax = -INF, ymin = INF, ymax = -INF;
        rep(i,0,n){
            double x = v[i].x, y = v[i].y;
            if(v[i].c == 'R')x += k;
            if(v[i].c == 'L')x -= k;
            if(v[i].c == 'U')y += k;
            if(v[i].c == 'D')y -= k;
            chmin(xmin, x), chmax(xmax, x);
            chmin(ymin, y), chmax(ymax, y);
        }
        return (xmax - xmin) * (ymax - ymin);
    };
    
    double ma = 1e9, mi = 0;
    rep(_,0,300){
        double le = mi + (ma - mi) / 3.0;
        double ri = ma - (ma - mi) / 3.0;

        if(calc(le) > calc(ri))mi = le;
        else ma = ri;
    }

    cout << fixed << setprecision(15);
    cout << calc(ma) << "\n";
}