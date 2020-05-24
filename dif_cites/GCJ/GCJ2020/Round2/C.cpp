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

void Case(int x){
    cout << "Case #" << x + 1 << ": ";
}

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    rep(q,t){
        ll n; cin >> n;
        vector<Pll> v(n);
        rep(i,n){
            cin >> v[i].first >> v[i].second;
        }
        if(n > 7)continue;
        sort(all(v));
        if(n <= 4){
            Case(q);
            cout << n << "\n";
            continue;
        }

        ll ans = 0;
        do{
            ll temp = 4;
            ll x = v[2].first - v[1].first;
            ll y = v[2].second - v[1].second;
            ll tx, ty;
            for(int i= 4; i < n; i++){
                if(i & 1){
                    temp++;
                    chmax(ans, temp);
                    continue;
                }
                tx = v[i].first - v[i-1].first;
                ty = v[i].second - v[i-1].second;
                if(x == tx && y == ty){
                    temp++;
                    chmax(ans, temp);
                }
                else {
                    chmax(ans, temp);
                    break;
                }
            }
            debug(v);
            debug(temp);
        }while(next_permutation(all(v)));

        Case(q);
        cout << ans << "\n";
    }
}