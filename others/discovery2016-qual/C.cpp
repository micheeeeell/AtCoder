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
string to_string(tuple<ll, ll, ll> &t){
    auto [a, b, c] = t;
    return "{" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + "}";
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

struct SuffixArray {
    string str;
    vector<int> sa;         // sa[i] : the starting index of the i-th smallest suffix (i = 0, 1, ..., n)
    vector<int> lcp;        // lcp[i]: the lcp of sa[i] and sa[i+1] (i = 0, 1, ..., n-1)
    inline int& operator [] (int i) {return sa[i];}
    
    SuffixArray(const string& str_) : str(str_) { buildSA(); calcLCP(); }
    void init(const string& str_) { str = str_; buildSA(); calcLCP(); }
    
    // build SA
    vector<int> rank_sa, tmp_rank_sa;
    struct CompareSA {
        int n, k;
        const vector<int> &rank;
        CompareSA(int n, int k, const vector<int> &rank_sa) : n(n), k(k), rank(rank_sa) {}
        bool operator()(int i, int j) {
            if (rank[i] != rank[j]) return (rank[i] < rank[j]);
            else {
                int rank_ik = (i + k <= n ? rank[i + k] : -1);
                int rank_jk = (j + k <= n ? rank[j + k] : -1);
                return (rank_ik < rank_jk);
            }
        }
    };
    void buildSA() {
        int n = (int)str.size();
        sa.resize(n+1), lcp.resize(n+1), rank_sa.resize(n+1), tmp_rank_sa.resize(n+1);
        for (int i = 0; i < n; ++i) sa[i] = i, rank_sa[i] = (int)str[i];
        sa[n] = n, rank_sa[n] = -1;
        for (int k = 1; k <= n; k *= 2) {
            CompareSA csa(n, k, rank_sa);
            sort(sa.begin(), sa.end(), csa);
            tmp_rank_sa[sa[0]] = 0;
            for (int i = 1; i <= n; ++i) {
                tmp_rank_sa[sa[i]] = tmp_rank_sa[sa[i - 1]];
                if (csa(sa[i - 1], sa[i])) ++tmp_rank_sa[sa[i]];
            }
            for (int i = 0; i <= n; ++i) rank_sa[i] = tmp_rank_sa[i];
        }
    }
    vector<int> rsa;
    // SparseTable<int> st;
    void calcLCP() {
        int n = (int)str.size();
        rsa.resize(n+1);
        for (int i = 0; i <= n; ++i) rsa[sa[i]] = i;
        lcp.resize(n+1);
        lcp[0] = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int pi = sa[rsa[i] - 1];
            if (cur > 0) --cur;
            for (; pi + cur < n && i + cur < n; ++cur) {
                if (str[pi + cur] != str[i + cur]) break;
            }
            lcp[rsa[i] - 1] = cur;
        }
        // st.init(lcp);
    }

    // sparce table を組み合わせることによって任意のi,jについて、lcp(i,j) := i,jの共通接頭辞長が計算できる
    // セグメント木でも可能（RMQ）
    // calc lcp
    // int getLCP(int a, int b) {          // lcp of str.sutstr(a) and str.substr(b)
    //     return st.get(min(rsa[a], rsa[b]), max(rsa[a], rsa[b]));
    // }

};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;cin >> s;
    ll k; cin >> k;
    ll n = s.size();
    vector<ll> sum(n + 1);
    rep(i,0,n){
        sum[i + 1] = sum[i] + (s[i] != 'a');
    }
    if(sum.back() <= k){
        cout << string(n - k, 'a') << endl;
        return 0;
    }

    debug(sum);
    SuffixArray sa(s);
    debug(sa.rsa);

    tuple<ll, ll, ll> t = make_tuple(0, INF, INF);
    auto comp = [&](ll i, ll j, ll k){
        auto &&[as, rs, id] = t;
        if(as < i || (as == i && j < rs)){
            return make_tuple(i, j, k);
        }
        else return t;
    };
    rep(i,0,k + 1){
        ll id = upper_bound(all(sum), i) - sum.begin();
        id--;
        t = comp(id + k - i, sa.rsa[id], id);
        debug(id, id + k - i, sa.rsa[id], id, i);
    }

    debug(t);
    auto [a, b, c] = t;
    cout << string(a, 'a') + s.substr(c) << endl;
}