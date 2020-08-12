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

struct SegmentTree {
   private:
    int n;
    vector<bitset<n_max>> node;

   public:
    // 元配列 v をセグメント木で表現する
    SegmentTree(ll m) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n
        // とおく セグメント木全体で必要なノード数は 2n-1 個である
        int sz = m;
        n = 1;
        while(n < sz) n *= 2;
        node.resize(2 * n - 1);


    }

    bitset<n_max> f(bitset<n_max> &a, bitset<n_max> &b){
        return a | b;
    }

    void update(int x, int val) {
        //最下段のノードにアクセスする
        x += (n - 1);

        //最下段のノードを更新したら，あとは親に上って更新していく
        node[x][val] = 1;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = f(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    //要求区間[a,b)中の要素の最小値を答える
    // k := 自分がいるノードのインデックス
    //対象区間は[l,r)に当たる

    bitset<n_max> getmin(int a, int b, int k = 0, int l = 0, int r = -1) {
        //最初に呼び出されたときの対象区間は[0,n);
        if(r < 0) r = n;

        //要求区間と対象区間が交わらない -> INFを返す
        if(r <= a || b <= l) return 0;

        //要求区間が対象を完全に被覆している -> 対象区間の答えを計算に使う
        if(a <= l && r <= b) return node[k];

        //要求区間が対象区間の一部を被覆 -> 子について探索を行う
        //左側の子を vl，右側の子を vr としている
        //新しい対象区間は，現在の対象区間を半分に割ったもの
        bitset<n_max> vl = getmin(a, b, 2 * k + 1, l, (l + r) / 2);
        bitset<n_max> vr = getmin(a, b, 2 * k + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
};

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,q; cin >> n >> q;
    SegmentTree seg(n);
    vector<ll> c(n);
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
    rep(i, 0, n) {
        seg.update(i, c[i]);
    }
    rep(_,0,q){
        ll l,r; cin >> l >> r;
        l--;
        bitset<n_max> bs = seg.getmin(l, r);
        cout << bs.count() << "\n";
    }
}