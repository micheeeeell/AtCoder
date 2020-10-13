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

template <typename T, typename Compare = less<T>,
          typename Rcompare = greater<T> >
struct PrioritySumStructure {
    size_t k;
    T sum;

    priority_queue<T, vector<T>, Compare> in, d_in;
    priority_queue<T, vector<T>, Rcompare> out, d_out;

    PrioritySumStructure(int k) : k(k), sum(0) {}

    void modify() {
        while (in.size() - d_in.size() < k && !out.empty()) {
            auto p = out.top();
            out.pop();
            if (!d_out.empty() && p == d_out.top()) {
                d_out.pop();
            } else {
                sum += p;
                in.emplace(p);
            }
        }
        while (in.size() - d_in.size() > k) {
            auto p = in.top();
            in.pop();
            if (!d_in.empty() && p == d_in.top()) {
                d_in.pop();
            } else {
                sum -= p;
                out.emplace(p);
            }
        }
        while (!d_in.empty() && in.top() == d_in.top()) {
            in.pop();
            d_in.pop();
        }
    }

    T query() const {
        return sum;
    }

    void insert(T x) {
        in.emplace(x);
        sum += x;
        modify();
    }

    void erase(T x) {
        assert(size());
        if (!in.empty() && in.top() == x) {
            sum -= x;
            in.pop();
        } else if (!in.empty() && Rcompare()(in.top(), x)) {
            sum -= x;
            d_in.emplace(x);
        } else {
            d_out.emplace(x);
        }
        modify();
    }
    void set_k(size_t kk) {
        k = kk;
        modify();
    }

    size_t get_k() const {
        return k;
    }

    size_t size() const {
        return in.size() + out.size() - d_in.size() - d_out.size();
    }
};

template <typename T>
using MaximumSum = PrioritySumStructure<T, greater<T>, less<T> >;

template <typename T>
using MinimumSum = PrioritySumStructure<T, less<T>, greater<T> >;

template <typename T>
struct UnionFind {
   private:
    vector<int> par;
    vector<int> rank;
    vector<int> sz;
    vector<int> left, right;
    vector<T> value;
    int n;

   public:
    // n要素で親を初期化、par[x]はxの親を表す
    UnionFind(int n) : n(n) {
        par.resize(n, 0);
        rank.resize(n, 0);
        sz.resize(n, 1);
        left.resize(n);
        right.resize(n);
        value.resize(n, 0);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            left[i] = i;
            right[i] = i;
        }
    }

    void build(vector<T> &v){
        for (int i = 0; i < n; i++){
            value[i] = v[i];
        }
    }

    //木の根を求める
    int root(int x) {
        if (par[x] == x)
            return x;
        else
            return par[x] = root(par[x]);
    }

    // xとyの属する集合を併合
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;

        if (rank[x] < rank[y]) {
            swap(x, y);
        }

        par[y] = x;
        sz[x] += sz[y];
        left[x] = min(left[x], left[y]);
        right[x] = max(right[x], right[y]);
        value[x] = value[x] + value[y];
        if (rank[x] == rank[y]) rank[x]++;
    }

    // xとyが同じ集合に属するか否か
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // xが属する集合のサイズを返す
    int size(int x) {
        return sz[root(x)];
    }

    // 集合の数を返す
    int num_of_s() {
        vector<int> cnt(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!cnt[root(i)]) ans++, cnt[root(i)] = 1;
        }
        return ans;
    }

    void set_value(int k, T v){
        value[root(k)] = v;
    }

    T get_value(int k){
        return value[root(k)];
    }

    int get_left(int k){
        return left[root(k)];
    }

    int get_right(int k){
        return right[root(k)];
    }

    void set_right(int k, int r){
        right[root(k)] = r;
    }

    void set_left(int k, int l){
        left[root(k)] = l;
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,k; cin >> n >> k;
    vector<Pll> c(n);
    rep(i,0,n){
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(all(c));

    MaximumSum<ll> psum(k - 1);

    vector<ll> sub(n + 1), rev(n, -1);
    rep(i, 0, n - 1) {
        sub[i + 1] = c[i + 1].first - c[i].first;
        psum.insert(sub[i + 1]);
        rev[c[i].second] = i + 1;
    }

    UnionFind<ll> uf(n + 1);
    uf.build(sub);
    uf.unite(0, 1);

    ll sum = c.back().first - c[0].first;
    cout << sum - psum.query() << "\n";
    debug(sum, psum.query());

    ll q;
    cin >> q;
    while(q--){
        ll d; cin >> d;
        d--;
        ll index = rev[d];
        debug(index);
        if (index == -1 || uf.get_right(index) == n) {
            ll r = uf.get_left(n) - 1;
            sum -= uf.get_value(r);
            psum.erase(uf.get_value(r));
            uf.unite(r, n);
        } else {
            if(uf.get_left(index) == 0){
                sum -= uf.get_value(index);
                psum.erase(uf.get_value(index));
                ll l = uf.get_right(index) + 1;
                uf.set_value(index, 0);
                uf.unite(0, l);
            }
            else{
                ll l = uf.get_left(index) - 1;
                ll r = index;
                psum.erase(uf.get_value(l));
                psum.erase(uf.get_value(r));
                uf.unite(l, r);
                psum.insert(uf.get_value(l));
            }
        }
        debug(sum, psum.query());
        cout << sum - psum.query() << "\n";
    }
}