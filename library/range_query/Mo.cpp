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
constexpr ll n_max = 5e5+10;
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

// 以下の条件が必要
// 配列の要素が不変.
// クエリを先読みできる(オフライン).
// 区間 [l,r) の結果から区間 [l+1,r), [l−1,r), [l,r−1), [l,r+1) の結果を容易に計算できる.
// add, delは随時実装
// 計算量はadd, delの計算量をαとするとO(α(N+Q)*sqrt(N))
struct Mo{
    vector<int> left, right, order;
    bitset<n_max> v;
    int width;
    int nl, nr, ptr;
    
    Mo(int n) : width((int)sqrt(n)), nl(0), nr(0), ptr(0) {}

    void insert(int l, int r){
        left.emplace_back(l);
        right.emplace_back(r);
    }

    void build(){
        order.resize(left.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            if(left[a] / width != left[b] / width) return left[a] < left[b];
            return right[a] < right[b];
        });
    }

    int process(){
        if(ptr == order.size()) return -1;
        const auto id = order[ptr];
        while(nl > left[id]) distribute(--nl);
        while(nr < right[id]) distribute(nr++);
        while(nl < left[id]) distribute(nl++);
        while(nr > right[id]) distribute(--nr);
        return order[ptr++];
    }

    inline void distribute(int idx){
        v[idx].flip();
        if(v[idx]) add(idx);
        else
            del(idx);
    }

    void add(int idx);
    void del(int idx);
};

ll sum = 0;
vector<int> cnt(n_max), c;

void Mo::add(int idx){
    cnt[c[idx]]++;
    if(cnt[c[idx]] == 1) sum++;
}

void Mo::del(int idx){
    cnt[c[idx]]--;
    if(cnt[c[idx]] == 0) sum--;
}


signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,q; cin >> n >> q;
    c.resize(n);
    rep(i, 0, n) {
        cin >> c[i];
        c[i]--;
    }
    Mo mo(n);
    rep(i, 0, q) {
        ll l, r;
        cin >> l >> r;
        mo.insert(--l, r);
    }

    mo.build();
    debug(mo.order);
    vector<ll> ans(q);
    rep(i,0,q){
        ll id = mo.process();
        debug(id, sum);
        ans[id] = sum;
    }
    for(auto &i : ans){
        cout << i << "\n";
    }
}