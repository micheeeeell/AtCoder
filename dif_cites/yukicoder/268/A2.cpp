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
void YES(bool ok){
    cout << (ok ? "Yes" : "No") << endl;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    vector<ll> a(k);
    for(int i = 0; i < k; i++) cin >> a[i];
    vector<ll> next;
    map<ll, ll> mp;
    rep(i, 0, k) mp[a[i]] = 1;
    while (true) {
        ll m = a.size();
        next = a;
        bool update = false;
        rep(i, 0, m) rep(j, i + 1, m) {
            if (a[j] - a[i] == 5){
                if(!mp.count(a[j] - 6) && a[j] > 6){
                    next.emplace_back(a[j] - 6);
                    update = true;
                    mp[a[j] - 6] = 1;
                }
            }
            if (a[j] - a[i] == 3){
                if(!mp.count(a[j] - 5) && a[j] > 5){
                    next.emplace_back(a[j] - 5);
                    update = true;
                    mp[a[j] - 5] = 1;
                }
            }
            if (a[j] - a[i] == 1){
                if(!mp.count(a[j] - 4) && a[j] > 4){
                    next.emplace_back(a[j] - 4);
                    update = true;
                    mp[a[j] - 4] = 1;
                }
            }
        }
        if (!update) break;
        sort(all(next));
        a = next;
        debug(next);
    }

    YES(!mp.count(1));
}