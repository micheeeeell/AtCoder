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

void f(){
    cout << "FULL" << endl;
    exit(0);
}

void e(){
    cout << "EMPTY" << endl;
    exit(0);
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll q,l; cin >> q >> l;
    vector<Pll> v;
    ll sz = 0;
    rep(_, 0, q){
        string t;cin >> t;
        if(t == "Push"){
            ll n,m; cin >> n >> m;
            v.emplace_back(n, m);
            sz += n;
            if (sz > l) f();
        }
        else if(t == "Pop"){
            ll n; cin >> n;
            ll n2 = n;
            while (!v.empty() && n) {
                auto [num, m] = v.back();
                v.pop_back();
                if (n >= num) n -= num;
                else{
                    num -= n;
                    n = 0;
                    v.emplace_back(num, m);
                }
            }
            if(v.empty() && n){
                e();
            }
            sz -= n2;
        } else if (t == "Top") {
            if (v.empty()) e();
            cout << v.back().second << "\n";
        } else {
            cout << sz << "\n";
        }
        debug(sz, v);
    }

    cout << "SAFE" << endl;
}