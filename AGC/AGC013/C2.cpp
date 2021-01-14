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
        if (&a != &vec.back()) cout << "\n";
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,l,t; cin >> n >> l >> t;
    t *= 2;
    vector<Pll> v(n);
    for (auto &[x, w] : v) cin >> x >> w;

    ll cnt = 0;
    rep(i,0,n){
        if (v[i].second == v[0].second) continue;
        if(v[0].second == 1){
            ll tt = t;
            ll tc = 1;
            tt -= (v[i].first - v[0].first);
            if (tt < 0) tc = 0;
            else{
                tc += tt / l;
            }
            cnt += tc;
        }
        else {
            ll tt = t;
            ll tc = 1;
            tt -= (v[0].first + l - v[i].first);
            if (tt < 0) tc = 0;
            else
                tc += tt / l;
            cnt += tc;
        }
    }

    debug(cnt);
    ll pos = 0;
    if (v[0].second == 1) {
        pos = cnt % n;
    }
    else{
        pos = -cnt % n;
        pos += n;
    }

    t /= 2;
    ll lpos = v[0].first + (v[0].second == 1 ? t : -t);
    lpos %= l;
    if (lpos < 0) lpos += l;

    vector<ll> p(n);
    rep(i,0,n){
        ll tmp = v[i].first + (v[i].second == 1 ? t : -t);
        tmp %= l;
        if (tmp < 0) tmp += l;
        p[i] = tmp;
    }

    sort(all(p));
    ll id = lower_bound(all(p), lpos) - p.begin();
    debug(id, pos, lpos, p);
    if (id < n - 1 && p[id + 1] == p[id]) {
        if (v[0].second == 1) id++;
    }

    vector<ll> ans(n);
    rep(i,0,n){
        ans[(i + pos) % n] = p[(id + i) % n];
    }

    print(ans);
}