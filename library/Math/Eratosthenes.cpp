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
constexpr ll n_max = 1e6+10;
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

// エラストテネスの篩

bitset<n_max> is_prime(0);
void build_sieve() {
    is_prime = ~is_prime;
    is_prime[0] = is_prime[1] = 0;
    for(ll i = 2; i < n_max; ++i)
        if(is_prime[i]) {
            for(ll j = 2 * i; j < n_max; j += i) is_prime[j] = 0;
        }
}

// 高速素因数分解
vector<ll> primes(n_max);
void build_prime(){
    std::iota(primes.begin(), primes.end(), 0);
    primes[0] = 1;
    for(int i = 2; i < n_max; i++){
        if(primes[i] == i){
            for(int j = i * 2; j < n_max; j += i){
                primes[j] = i;
            }
        }
    }
}

vector<int> prime_factor(int x){
    vector<int> res;
    while(x != 1){
        res.emplace_back(primes[x]);
        x /= primes[x];
    }

    return res;
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    

    build_prime();
    debug(prime_factor(70224));
    ll n;
    cin >> n;
    ll g = 0;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    rep(i, 0, n) g = gcd(g, a[i]);
    if(g != 1) {
        cout << "not coprime" << endl;
        return 0;
    }

    vector<ll> used(n_max);
    rep(i,0,n){
        auto p = prime_factor(a[i]);
        p.erase(unique(all(p)), p.end());
        debug(p);
        for(auto &j : p){
            if(used[j]){
                cout << "setwise coprime" << endl;
                return 0;
            }
            used[j] = 1;
        } 
    }

    cout << "pairwise coprime" << endl;
}