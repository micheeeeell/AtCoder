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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

// 2つの素数でModulo演算を行う
// 構築O(N),比較O(1)
// 比較は渡した文字列の中で行うので、文字列を結合して渡すか、2つ作ってhash値から直接比較する
// 比較、hash値計算などのl,rは[l, r)
// verify: AOJ ALDS1_14_B "String Search"
const ll MS = 2;
const ll mod[] = {999999937LL, 1000000007LL}, base = 9937;

struct RollingHash {
    ll n, base;
    vector<ll> hs[MS], pw[MS];
    RollingHash(){};
    RollingHash(const string &s, const ll base):base(base) {
        n = s.size();
        for(int i = 0; i < MS; i++){
            hs[i].assign(n+1, 0);
            pw[i].assign(n+1, 0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            for(int j = 0;j < n; j++){
                pw[i][j + 1] = pw[i][j] * base % mod[i];
                hs[i][j+1] = (hs[i][j] * base + s[j]) % mod[i];
            }
        }
    }

    long long hash(int l, int r, int i){
        return ((hs[i][r] - hs[i][l] * pw[i][r-l]) % mod[i] + mod[i]) % mod[i];
    }

    bool match(int l1, int r1, int l2, int r2) {
        bool ret = true;
        for(int i = 0; i < MS; i++) ret &= hash(l1, r1, i) == hash(l2, r2, i);
        return ret;
    }

    bool match(int l, int r, long long h[]){
        bool ret = true;
        for(int i = 0; i < MS; i++) ret &= hash(l, r, i) == h[i];
        return ret;
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string t, p;cin >> t >> p;
    RollingHash rh1(t, base);
    RollingHash rh2(p, base);
    ll n = t.size();
    ll m = p.size();
    ll h[2];
    rep(i,0,2)h[i] = rh2.hash(0, m, i);
    rep(i,0,n){
        if(i + m > n)break;
        auto ok = rh1.match(i, i + m, h);
        if(ok){
            cout << i << "\n";
        }
    }
}