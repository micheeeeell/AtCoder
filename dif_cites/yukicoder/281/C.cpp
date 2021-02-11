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
const long double eps = 1e-12;

template <typename T>
int comp(T a){
    if (abs(a) < eps) return 0;
    return a > 0 ? 1 : -1;
}

template <typename T>
int comp(T a, T b){
    // a > b -> 1, a < b -> -1
    return comp(a - b);
}

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
    vector<ll> c(n);
    for(int i = 0; i < n; i++) {
       cin >> c[i];
    }
    sort(all(c));
    vector memo(2, vector<ll>(2));
    rep(i,0,2)rep(j,0,2){
        ll a = 0, b = 0;
        deque<ll> deq;
        rep(i, 0, n) deq.emplace_back(c[i]);
        while (!deq.empty()){
            if(i){
                a += deq.back();
                deq.pop_back();
            }
            else{
                a += deq.front();
                deq.pop_front();
            }
            if (deq.empty()) break;
            if(j){
                b += deq.back();
                deq.pop_back();
            }
            else{
                b += deq.front();
                deq.pop_front();
            }
        }

        memo[i][j] = abs(a) - abs(b);
    }

    ll i = min(memo[0][0], memo[0][1]) > min(memo[1][0], memo[1][1]) ? 0 : 1;
    cout << min(memo[i][0], memo[i][1]) << endl;
}