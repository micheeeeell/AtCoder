#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const int n_max = 1e5+10;
#define int ll

// VerifyはEDPC Z

// Convex Hull Trick
// Li-Chao-tree
// 直線群ax + bの中から、あるx(X)について
// 最小を取る直線の値aX + bをクエリO(logN)で得られる
// update で直線を追加
// @ei1333のライブラリ、クエリが（先読み）単調増加のときなど、特殊なときにはより計算量を落とす実装が存在する
// 初期化のvector x　はクエリのvector(x[i] := i回目に聞かれるクエリの値)
// query(i) := i回目のクエリに答える（xの値を与えるわけではないことに注意）

template< typename T >
struct LiChaoTree {
    struct Line {
        T a, b;
        Line(T a, T b):a(a), b(b) {}

        inline T get(T x) const {return a * x + b;};

        inline bool over(const Line &b, const T &x) const {
            return get(x) < b.get(x);
        }
    };

    vector< T > xs;
    vector< Line > seg;
    int sz;

    LiChaoTree(const vector< T > &x, T INF): xs(x) {
        sz = 1;
        while(sz < xs.size()) sz <<= 1;
        while(xs.size() < sz) xs.emplace_back(xs.back() + 1);
        seg.assign(2 * sz - 1, Line(0,INF));
    }

    void update(Line &x, int k, int l, int r) {
        int mid = (l + r) >> 1;
        auto latte = x.over(seg[k], xs[l]), malta = x.over(seg[k], xs[mid]);
        if(malta) swap(seg[k], x);
        if(l + 1 >= r)return;
        else if(latte != malta) update(x, 2 * k + 1, l, mid);
        else update(x, 2 * k + 2, mid, r);
    }

    void update(T a, T b) { // ax + b
        Line l(a, b);
        update(l, 0, 0, sz);
    }

    T query(int k) { // xs[k]
        const T x = xs[k];
        k += sz - 1;
        T ret = seg[k].get(x);
        while(k > 0) {
            k = (k - 1) >> 1;
            ret = min(ret, seg[k].get(x));
        }
        return ret;
    }
};


signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    ll n,c; cin >> n >> c;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    vector<ll> dp(n);
    LiChaoTree<ll> lichao(h, INF);
    dp[0] = 0;
    lichao.update(-2 * h[0], h[0] * h[0]);
    reps(i,n-1){
        // debug(lichao.query(i));
        dp[i] = lichao.query(i) + c + h[i] * h[i];
        lichao.update(-2 * h[i], h[i] * h[i] + dp[i]);\
    }
    cout << dp[n-1] << endl;
}