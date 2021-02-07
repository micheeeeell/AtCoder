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
    auto print = [](vector<ll> &v) {
        for(auto &i : v){
            cout << i;
            if (&i != &v.back()) cout << " ";
        }
        cout << endl;
    };
    auto print2 = [&print](vector<vector<ll>> &v) {
        for (auto x : v) print(x);
    };
    auto query = [&](vector<ll> &v) {
        cout << "?" << " ";
        print(v);
        string s;
        cin >> s;
        if(s == "-1"){
            exit(0);
        }
        return s == "Red" ? 1 : 2;
    };
    vector<ll> ans(2 * n);
    vector<ll> v(n);
    ll l = 0, r = n;
    iota(all(v), 1);
    ll lc = query(v);
    iota(all(v), n + 1);
    ll rc = query(v);
    while(r - l > 1){
        ll x = (l + r) / 2;
        iota(all(v), x + 1);
        if(lc == query(v)){
            l = x;
        }
        else{
            r = x;
        }
    }
    ans[l] = lc;
    ans[r + n - 1] = rc;
    vector<ll> t1(n), t2(n);
    iota(all(t1), r + 1);
    iota(all(t2), r + n + 1);
    rep(i,0,n){
        if (t2[i] > 2 * n) t2[i] -= 2 * n;
    }
    debug(t1, t2);
    rep(i,0,2 * n){
        if (ans[i] != 0) continue;
        if(r <= i && i <= l + n - 1){
            t2[n - 1] = i + 1;
            ans[i] = query(t2);
        }
        else{
            t1[n - 1] = i + 1;
            ans[i] = query(t1);
        }
    }

    string a(2 * n, '.');
    rep(i,0,2 * n){
        a[i] = ans[i] == 1 ? 'R' : 'B';
    }

    cout << "! " << a << endl;
    return 0;
}