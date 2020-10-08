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

vector<ll> solver(ll n, vector<ll> &x, vector<ll> &y){
    vector<ll> ida(n + 1, -1), idb(n + 1, -1);
    vector<ll> a(n), cnt(n + 1);
    a = x;
    for(int i = 0; i < n; i++) {
        cnt[a[i]]++;
        chmax(ida[a[i]], i);
    }
    vector<ll> b(n);
    b = y;
    for(int i = 0; i < n; i++) {
        cnt[b[i]]++;
        chmax(idb[b[i]], i);
    }
    rep(i, 0, n + 1) {
        if(cnt[i] > n) {
            return {};
        }
    }
    rep(i, 1, n + 1) {
        chmax(ida[i], ida[i - 1]);
        chmax(idb[i], idb[i - 1]);
    }
    // debug(ida, idb);
    ll num = 0;
    rep(i, 1, n + 1) {
        chmax(num, ida[i] - idb[i - 1]);
    }
    // debug(num);
    vector<ll> ans(n);
    num %= n;
    rep(i, 0, n) {
        ans[num] = b[i];
        num++;
        num %= n;
    }

    return ans;
}

ll checker(vector<ll> &a, vector<ll> &ans){
    ll n = a.size();
    rep(i,0,n){
        if(a[i] == ans[i] || ans[i] == 0){
            return i;
        }
    }

    return 0;
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    random_device rnd;
    mt19937 mt(rnd());
    rep(i,0, 10000){
        // cout << i << endl;
        ll n = 10;
        vector<ll> a(n), b(n);
        rep(i,0,n){
            a[i] = mt() % n + 1;
            b[i] = mt() % n + 1;
        }
        sort(all(a));
        sort(all(b));

        auto ans = solver(n, a, b);
        if(ans.size()){
            if(checker(a, ans)){
                debug(a);
                debug(b);
                debug(ans);
                debug(checker(a, ans));
                return 0;
            }
        }
    }

}