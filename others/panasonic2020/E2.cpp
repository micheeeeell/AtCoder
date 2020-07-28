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
    string a;cin >> a;
    string b;cin >> b;
    string c;cin >> c;

    ll base = 10000;
    ll A = a.size(), B = b.size(), C = c.size();
    vector<ll> ab(base*2, 1), ac(base*2, 1), bc(base*2, 1);
    auto match = [&](char c, char d){
        return c == '?' || d == '?' || c == d;
    };
    rep(i,0,a.size())rep(j,0,b.size()){
        ab[i-j+base] &= match(a[i], b[j]);
    }
    rep(i,0,a.size())rep(j,0,c.size()){
        ac[i-j+base] &= match(a[i], c[j]);
    }
    rep(i,0,b.size())rep(j,0,c.size()){
        bc[i-j+base] &= match(b[i], c[j]);
    }
    rep(i,-10,10)debug(i, ab[i+base], ac[i+base], bc[i+base]);
    ll ans = 6000;
    for(int i = -4000; i <= 4000; i++){
        for(int j = -4000; j <= 4000; j++){
            if(ab[i+base] && ac[i+j+base] && bc[j+base]){
                ll l = min({0LL, i, i+j});
                ll r = max({A, i+B, i+j+C});
                chmin(ans, r-l); 
            }
        }
    }

    cout << ans << "\n";
}