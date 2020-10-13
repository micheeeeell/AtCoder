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
void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << " ";
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << " ";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

void answer(vvl &v, bool ok){
    if(!ok){
        cout << "impossible" << endl;
        exit(0);
    }

    ll n = v.size();
    cout << n << endl;
    rep(i,0,n){
        cout << v[i].size() << " ";
        print(v[i]);
    }
    exit(0);
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    auto even = [&](ll s, ll e) {
        vector<vector<ll>> res;
        while (s < e) {
            vector<ll> tmp = {s, e};
            res.emplace_back(tmp);
            s += 2;
            e -= 2;
        };
        return res;
    };
    vvl ans;
    if (n == 2) {
        answer(ans, false);
    }
    if(~n & 1){
        ans = even(1, 2 * n - 1);
        answer(ans, true);
    }
    ll p = -1;
    for (int i = 2; i * i <= n; i++){
        if(n % i == 0){
            p = i;
            break;
        }
    }
    if(p == -1){
        answer(ans, false);
    }

    vector<vector<ll>> v(p, vector<ll>(p));
    ll tmp = 1;
    rep(i, 0, p)rep(j, 0, p){
        v[i][j] = tmp;
        tmp += 2;
    }
    ans.resize(p);
    rep(i,0,p){
        ll x = 0, y = i;
        rep(j,0,p){
            ans[i].emplace_back(v[x][y]);
            x++;
            y++;
            y %= p;
        }
    }
    debug(ans);
    ll ma = 2 * n - 1;
    while (tmp < ma) {
        auto vt = even(tmp, tmp + p * 4 - 2);
        rep(i,0,p){
            rep(j,0,2){
                ans[i].emplace_back(vt[i][j]);
            }
        }
        tmp += p * 4;
    }

    answer(ans, true);
}