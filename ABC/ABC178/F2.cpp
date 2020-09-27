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

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> cnt(n + 1);
    vector<Pll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        cnt[a[i].first]++;
    }
    vector<ll> b(n), cntb(n+1);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        cnt[b[i]]++;
        cntb[b[i]]++;
    }
    sort(all(a), [&](auto const &a, auto const &b) {
        return cnt[a.first] > cnt[b.first] ||
               (cnt[a.first] == cnt[b.first] && a.first > b.first);
    });
    debug(a);

    vector<ll> ans(n);
    rep(i, 0, n + 1) {
        if(cnt[i] > n) {
            cout << "No" << "\n";
            return 0;
        }
    }
    cout << "Yes" << "\n";
    priority_queue<Pll> pq;
    rep(i,0,n+1){
        if(cntb[i])pq.emplace(Pll{cntb[i], i});
    }

    rep(i,0,n){
        auto [val, idx] = a[i];
        Pll x, y = {0, 0};
        x = pq.top();
        pq.pop();
        if(!pq.empty()){
            y = pq.top();
            pq.pop();
        }
        if(val != x.second){
            ans[idx] = x.second;
            x.first--;
        }
        else{
            ans[idx] = y.second;
            y.first--;
        }
        if(x.first)pq.emplace(x);
        if(y.first)pq.emplace(y);
    }

    print(ans);
}