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
    ll n,k; cin >> n >> k;
    ll pre = (k + k + 2 * n - 1) * n;
    ll pos = (2 * k + 5 * n - 1) * n / 2;
    if(pre > pos){
        cout << -1 << "\n";
        return 0;
    }
    vector<set<ll>> st(2);
    rep(i,0,n){
        st[0].insert(-k-i);
        st[1].insert(-k-n-i);
    }
    vector<ll> a,b,c;
    rrep(i,k+3*n, k + 2*n){
        if(-*st[0].begin() - *st[1].begin() <= i){
            a.emplace_back(-*st[0].begin());
            b.emplace_back(-*st[1].begin());
            c.emplace_back(i);
            st[0].erase(st[0].begin());
            st[1].erase(st[1].begin());
            continue;
        }
        auto t = st[1].begin();
        auto itr = st[0].find(-(i + *t)); 
        debug(*t, i);
        if(itr != st[0].end()){
            a.emplace_back(-*itr);
            b.emplace_back(-*t);
            c.emplace_back(i);
            st[0].erase(itr);st[1].erase(t);
        }
        else{
            itr = st[0].begin();
            t = st[1].lower_bound(-(i + *itr));
            if(t == st[1].end()){
                t = st[1].begin();
                itr = st[0].lower_bound(-(i + *t));
            }
            a.emplace_back(-*itr);
            b.emplace_back(-*t);
            c.emplace_back(i);
            st[0].erase(itr);st[1].erase(t);
        }
    }

    rep(i,0,n){
        print(a[i], b[i], c[i]);
    }
}