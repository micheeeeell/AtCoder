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

const ll N = 5e6+10;
bitset<N> is_prime(0);
void build_sieve(){
    is_prime = ~is_prime;
    is_prime[0] = is_prime[1] = 0;
    for(ll i = 2; i < N; ++i)if(is_prime[i]){
        for(ll j = 2*i; j < N; j+=i)is_prime[j] = 0;
    }
}

ll hs_pow(ll x, ll n, ll MOD){
    ll ret = 1;
    while(n){
        if((n % 2) == 0){
            x = x*x % MOD;
            n >>= 1;
        }
        else{
            ret = ret * x % MOD;
            n >>= 1;
        }
        // cout << ret  << ' ' << n  << ' ' << x << endl;
    }
    return ret;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    build_sieve();
    ll t; cin >> t;
    while(t--){
        ll a,p; cin >> a >> p;
        if(!is_prime[p]){
            cout << -1 << "\n";
            continue;
        }
        if(a % p == 0){
            cout << 0 << "\n";
        }
        else cout << 1 << "\n";
    }
}