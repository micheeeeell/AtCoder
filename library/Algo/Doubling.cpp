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

// ダブリング
// {0 ~ n-1} -> {0 ~ n-1}の写像の時
// verify: https://atcoder.jp/contests/abc167/tasks/abc167_d
// https://atcoder.jp/contests/abc136/tasks/abc136_d
struct doubling {
    int n;
    int LOG = 64;
    vector<vector<int>> table;
    doubling(int n) : n(n), table(LOG, vector<int>(n)) {};
    doubling(int n, vector<int> &p): n(n), table(LOG, vector<int>(n)) {
        build(p);
    }

    void build(vector<int> &p){
        for (int k = 0; k < LOG; k++){
            for (int i = 0; i < n; i++){
                if (k == 0)
                    table[k][i] = p[i];
                else
                    table[k][i] = table[k - 1][table[k - 1][i]];
            }
        }
    }

    int query(int f, int k){
        // from f, k times
        int cnt = 0;
        while (k) {
            if(k & 1){
                f = table[cnt][f];
            }
            cnt++;
            k >>= 1;
        }
        return f;
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;cin >> s;
    ll n = s.size();
    vector<ll> p(n);
    rep(i,0,n){
        if (s[i] == 'R') p[i] = i + 1;
        else
            p[i] = i - 1;
    }
    doubling db(n);
    db.build(p);
    vector<ll> ans(n);
    rep(i,0,n){
        ans[db.query(i, 1LL << 30)]++;
    }
    auto print = [](vector<ll> &v) {
        for(auto &i : v){
            cout << i;
            if (&i != &v.back()) cout << " ";
        }
        cout << "\n";
    };
    auto print2 = [&print](vector<vector<ll>> &v) {
        for (auto x : v) print(x);
    };

    print(ans);
}