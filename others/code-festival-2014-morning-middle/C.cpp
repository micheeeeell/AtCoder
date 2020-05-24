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

using vmi = vector< long double >;
using mat = vector< vmi >;

mat mul(mat &a, mat &b){
    mat c(a.size(), vmi(b[0].size()));
    rep(i,a.size()){
        rep(k,b.size()){
            rep(j,b[0].size()){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    debug(c);
    rep(i,c[0].size()){
        ld t = 0;
        rep(j,c.size()){
            t += c[j][i];
        }
        rep(j,c.size()){
            c[j][i] = c[j][i] / t;
        }
    }
    debug(c);
    return c;
}

mat pow(mat &a, ll n){
    mat b(a.size(), vmi(a.size()));
    rep(i,a.size())b[i][i] = 1.0;
    while(n > 0){
        if(n & 1)b = mul(b,a);
        a = mul(a,a);
        n >>= 1;
    }
    return b;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    long double p;cin >> p;
    ll n; cin >> n;
    mat P = {{1.0-p, p}, {p, 1.0-p}};
    mat vec = {{1.0}, {0}};
    P = pow(P, n);
    debug(P);
    auto ans = mul(P, vec);
    cout << fixed << setprecision(15);

    cout << ans[1][0] << endl;
}