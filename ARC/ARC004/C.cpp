#define LOCAL
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

template <class T, class U>
ll euclid_gcd(T a, U b){
    if(a < b)return euclid_gcd(b,a);
    ll r;
    while((r = a%b)){
        a = b;
        b = r;
    }
    return b;
}


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;cin >> s;
    ll x = 0;
    ll pos = 0;
    while(s[pos] != '/'){
        ld t = s[pos++] - '0';
        x = x * 10 + t;
    }
    pos++;
    ll y = 0;
    while(pos < s.size()){
        ld t = s[pos++] - '0';
        y = y * 10 + t;
    }
    ll g = euclid_gcd(x,y);
    x = x / g;
    y = y / g;
    ld k = ld(x) / ld(y);
    bool ok = false;

    for(ll n = 2 * k - 2; n <= 2 * k + 1; n++){
        if(n <= 0)continue;
        if(n % y != 0)continue;
        ld tx = x * (n / y);
        ll m = n * (n+1) / 2 - tx;
        if(m > n)continue;
        if(m <= 0)continue;
        ok = true;
        cout << n << " " << m << endl;
    }

    if(!ok)cout << "Impossible" << endl;
}