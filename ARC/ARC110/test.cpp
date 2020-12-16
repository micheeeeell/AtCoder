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

vector<ll> solve(vl a){
    ll n = a.size();
    vl used(n);
    ll t = 1;
    vector<ll> ans;
    rep(i, 0, n) {
        if (a[i] == t) {
            ll j = i;
            while (j + 1 > t) {
                swap(a[j], a[j - 1]);
                ans.emplace_back(j);
                used[j] = 1;
                j--;
            }
            debug(a);
            rep(k, t, i) {
                if (a[k] != k + 1) {
                    cout << -1 << endl;
                    return {-1};
                }
            }
            t = i + 1;
        }
        debug(i, t, a);
        if (a[i] == t) t++;
    }
    debug(used);
    return a;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    random_device rnd;
    mt19937 mt(rnd());

    rep(_, 0, 1){
        vector<ll> a(20);
        iota(all(a), 1);
        debug(_);
        rep(j, 0, 19) {
            while(1){
                ll id = mt() % 19;
                if (a[id] > a[id + 1]) continue;
                swap(a[id], a[id + 1]);
                break;
            }
        }
        vl b = a;
        sort(all(b));

        if (solve(a) != b) {
            debug(a, solve(a));
            break;
        }
    }
}