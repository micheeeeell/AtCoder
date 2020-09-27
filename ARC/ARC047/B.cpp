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

template <class T, class U>
void print(pair<T, U> p){
    print(p.first, p.second);
}
signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;

    vector<Pll> v(n);
    ll ma = 1e9;
    Pll xm = {ma, -ma}, ym = {ma, -ma};
    rep(i, 0, n) {
        ll x,y; cin >> x >> y;
        v[i] = {x + y, x - y};
        chmin(xm.first, v[i].first);
        chmax(xm.second, v[i].first);
        chmin(ym.first, v[i].second);
        chmax(ym.second, v[i].second);
    }

    ll d = max(xm.second - xm.first, ym.second - ym.first);
    Pll ans;

    auto dis = [&](Pll a, Pll b) {
        return max(abs(a.first - b.first), abs(a.second - b.second));
    };
    auto calc = [&](Pll p) {
        bool res = true;
        ll d = dis(p, v[0]);
        rep(i,0,n){
            res &= d == dis(p, v[i]);
        }

        return res;
    };

    auto answer = [](Pll ans) {
        ll x = (ans.first + ans.second);
        ll y = (ans.first - ans.second);
        if ((x & 1) || (y & 1)) return;
        x /= 2;
        y /= 2;
        print(x, y);
        exit(0);
        return;
    };
    if (xm.second - xm.first == ym.second - ym.first) {
        ans = {xm.first + d / 2, ym.first + d / 2};
        if(calc(ans)){
            answer(ans);
        }
    }

    if(xm.second - xm.first == d){
        ans = {xm.first + d / 2, ym.first + d / 2};
        if(calc(ans)){
            answer(ans);
        }
        ans.second = ym.second - d / 2;
        if(calc(ans)){
            answer(ans);
        }
    }

    if(ym.second - ym.first == d){
        ans = {xm.first + d / 2, ym.first + d / 2};
        if (calc(ans)) {
            answer(ans);
        }
        ans.first = xm.second - d / 2;
        if(calc(ans)){
            answer(ans);
        }
    }

    // while(1){
    //     rep(i, 0, 4) {
    //         if(i == 0){
    //             ans = {xm.first + d / 2, ym.first + d / 2};
    //         }
    //         else if(i == 1){
    //             ans = {xm.first + d / 2, ym.second - d / 2};
    //         }
    //         else if(i == 2){
    //             ans = {xm.second - d / 2, ym.first + d / 2};
    //         }
    //         else if(i == 3){
    //             ans = {xm.second - d / 2, ym.second - d / 2};
    //         }

    //         if(calc(ans)){
    //             answer(ans);
    //         }
    //     }
    //     d += 2;
    // }
}