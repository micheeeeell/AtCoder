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
    ll n,K; cin >> n >> K;
    K--;
    vector<ll> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<ll> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    ll LOG = 31;
    vector<vector<ll>> table(LOG, vector<ll>(n)), to(LOG, vector<ll>(n));

    to[0] = p;
    rep(k,0,LOG-1){
        rep(i,0,n){
            to[k+1][i] = to[k][to[k][i]];
        }
    }
    rep(i,0,n)table[0][i] = c[p[i]];
    rep(k,0,LOG-1){
        rep(i,0,n){
            table[k+1][i] = table[k][i] + table[k][to[k][i]];
        }
    }

    debug(to);
    debug(table);
    
    ll ans = -INF;
    rep(i,0,n){
        ll tmp = c[p[i]];
        ll pos = p[i];
        
        bool is_small = false;
        rrep(j, LOG, 0){
            if(!is_small && ((K >> j) & 1)){
                if(table[j][pos] > 0){
                    tmp += table[j][pos];
                    pos = to[j][pos];
                }
                else{
                    is_small = true;
                }
            }
            else if(is_small){
                if(table[j][pos] > 0) {
                    tmp += table[j][pos];
                    pos = to[j][pos];
                }
            }
            debug(j, pos, tmp, is_small);
        }

        chmax(ans, tmp);
    }


    cout << ans << "\n";
}