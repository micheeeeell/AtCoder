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

pair<ll, vector<ll>> solve(vl &a) {
    ll n = a.size();
    ll e = 0, o = 0;
    rep(i, 0, n) {
        if (i & 1) {
            o += max(a[i], 0LL);
        } else {
            e += max(a[i], 0LL);
        }
    }
    if (o + e == 0) {
        ll id = max_element(all(a)) - a.begin();
        vector<ll> ans;
        rrep(i, n, id + 1) {
            ans.emplace_back(i + 1);
        }
        rep(i, 0, id) ans.emplace_back(1);
        return {a[id], ans};
    }

    if (o > e) {
        ll cnt = n;
        vector<ll> ans;
        rrep(i, n, 0) {
            if ((i & 1) && a[i] < 0) {
                ans.emplace_back(i + 1);
                if (i == n - 1)
                    cnt--;
                else
                    cnt -= 2;
            }
        }
        while (cnt > 2) {
            ans.emplace_back(3);
            cnt -= 2;
        }
        ans.emplace_back(1);
        return {o, ans};
    } else {
        ll cnt = n;
        vector<ll> ans;
        rrep(i, n, 1) {
            if ((~i & 1) && a[i] < 0) {
                ans.emplace_back(i + 1);
                if (i == n - 1)
                    cnt -= 1;
                else
                    cnt -= 2;
            }
        }
        if (a[0] < 0) {
            ans.emplace_back(1);
            cnt--;
            if (cnt > 1) {
                ans.emplace_back(1);
                cnt--;
            }
        }
        while (cnt > 1) {
            ans.emplace_back(2);
            cnt -= 2;
        }
        return {e, ans};
    }
}

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    auto [ma_, ans] = solve(a);
    cout << ma_ << endl;
    cout << ans.size() << endl;
    print(ans);
}