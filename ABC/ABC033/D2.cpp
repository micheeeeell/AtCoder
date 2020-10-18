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
const long double eps = 1e-11;

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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<Pll> v(n);
    rep(i, 0, n) cin >> v[i].first >> v[i].second;

    ll right = 0, obtuse = 0;

    auto count = [&](ll id) {
        vector<Pll> tv;
        rep(i, 0, n) {
            if (i == id) continue;
            tv.emplace_back(v[i].first - v[id].first,
                            v[i].second - v[id].second);
        }
        sort(all(tv), [](const auto &a, const auto &b) {
            return atan2(a.second, a.first) < atan2(b.second, b.first);
        });
        ll m = 2 * n - 2;
        vector<ld> rad(2 * n - 2);
        {
            auto tmp = tv;
            copy(all(tmp), back_inserter(tv));
            ll m = tv.size();
            rep(i,0,n-1){
                rad[i] = atan2(tv[i].second, tv[i].first);
            }
            rep(i,n-1,2*n-2){
                rad[i] = atan2(tv[i].second, tv[i].first) + 2 * pi;
            }
        }

        debug(rad);

        ll l = 0, r = 0;
        rep(i, 0, n - 1) {
            auto phi = rad[i];
            l = lower_bound(all(rad), phi + pi * 0.5L - eps) - rad.begin();
            r = lower_bound(all(rad), phi + pi - eps) - rad.begin();
            debug(id, i, l, r);
            obtuse += (r - l);
            if(l < m && abs(rad[l] - phi - pi * 0.5L) < eps){
                right++;
                obtuse--;
            }
        }
    };
    rep(i, 0, n) {
        count(i);
    }

    debug(right, obtuse);
    ll ans = n * (n - 1) * (n - 2) / 6;
    ans -= right + obtuse;
    print(ans, right, obtuse);
}