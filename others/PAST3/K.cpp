#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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

struct Node{
    ll par, child;
    Node(){
        par = -1;
        child = -1;
    }
};

string to_string(Node p){return "(" + to_string(p.par) + ", " + to_string(p.child) + ")";}
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
    
    ll n,q; cin >> n >> q;
    // tableはpairで最初と最後を持つ
    vector<Pll> table(n);
    rep(i,n){
        table[i] = {i, i};
    }
    vector<Node> v(n);
    while(q--){
        ll f,t,x; cin >> f >> t >> x;
        f--;t--;x--;

        ll pt = v[x].par;
        // table更新
        // 合体
        if(table[t].second != -1)v[table[t].second].child = x;
        v[x].par = table[t].second;
        table[t].second = table[f].second;
        if(table[t].first == -1)table[t].first = x;

        // 切り離す
        table[f].second = pt;
        if(table[f].first == x)table[f].first = -1;
        if(pt != -1)v[pt].child = -1;


        debug(table);
        debug(v);
        debug();
    }

    vector<ll> ans(n);
    rep(i,n){
        if(table[i].first == -1)continue;
        ll t = table[i].first;
        while(t != -1){
            ans[t] = i+1;
            t = v[t].child;
            // debug(t);
        }
    }

    print(ans);
}