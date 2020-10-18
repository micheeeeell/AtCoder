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
    ll n; cin >> n;
    vector<ll> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    ll l; cin >> l;
    const ll LOG = 32;
    vector table(LOG+1, vector<ll>(n));
    ll right = 0;
    rep(i,0,n){
        while(right < n && x[right] <= x[i] + l){
            right++;
        }
        table[0][i] = right-1;
        if(i == right)right++;
    }
    debug(table[0]);
    rep(k,0,LOG){
        rep(i,0,n){
            table[k+1][i] = table[k][table[k][i]];
        }
    }

    auto c = [&](ll f, ll t, ll x){
        rrep(k,LOG,0){
            if((x >> k) & 1)f = table[k][f];
        }
        return f >= t;
    };
    ll q; cin >> q;
    rep(_,0,q){
        ll f,t; cin >> f >> t;
        f--;t--;
        if(!(f < t))swap(f, t);
        ll ng = 0, ok = 1e5+10;
        while(abs(ok - ng) > 1){
            ll x = (ok + ng) / 2;
            if(c(f, t, x))ok = x;
            else ng = x;
        }


        cout << ok << "\n";
    }
}