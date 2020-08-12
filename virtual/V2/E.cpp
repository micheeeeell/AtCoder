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
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += abs(a[i]);
    }
    ll p = 0, m;
    rep(i, 0, n) {
        if(a[i] >= 0) p++;
    }
    m = n - p;
    ll ans = 0;
    vector<ll> x(n-1), y(n-1);
    if(p == 0) {
        ll mi = *max_element(all(a));
        debug(sum, mi);
        ans = sum + 2 * mi;
        ll id = 0;
        rep(i, 0, n) if(mi == a[i]) id = i;
        ll pos = 0;
        rep(i, 0, n - 1) {
            if(pos == id) pos++;
            x[i] = mi;
            y[i] = a[pos];
            mi -= a[pos];
            pos++;
        }
    }
    else if(p == n) {
        ll mi = *min_element(all(a));
        ans = sum - mi * 2;
        ll id = 0;
        rep(i, 0, n) if(mi == a[i]) id = i;
        debug(id);
        ll pos = 0;
        rep(i, 0, n - 2) {
            if(pos == id) pos++;
            x[i] = mi;
            y[i] = a[pos];
            mi -= a[pos];
            pos++;
        }
        x[n - 2] = a[pos];
        y[n - 2] = mi;
    } else {
        vector<ll> plus, minus;
        rep(i, 0, n) {
            if(a[i] >= 0) plus.emplace_back(a[i]);
            else
                minus.emplace_back(a[i]);
        }

        ans = sum;
        ll X = plus.back();
        plus.pop_back();
        ll Y = minus.back();
        minus.pop_back();
        ll i = 0;
        while(!plus.empty()) {
            x[i] = Y;
            y[i] = plus.back();
            plus.pop_back();
            Y -= y[i++];
        }
        while(!minus.empty()) {
            x[i] = X;
            y[i] = minus.back();
            minus.pop_back();
            X -= y[i++];
        }
        x[i] = X;
        y[i] = Y;
    }
    cout << ans << "\n";
    rep(i, 0, n - 1) {
        cout << x[i] << " " << y[i] << "\n";
    }
}
    