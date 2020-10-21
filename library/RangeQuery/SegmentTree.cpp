#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
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


struct SegmentTree {
private:
    int n;
    vector<int> node;

public:
    // 元配列 v をセグメント木で表現する
    SegmentTree(vector<int> v) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val){
        //最下段のノードにアクセスする
        x += (n - 1);

        //最下段のノードを更新したら，あとは親に上って更新していく
        node[x] = val;
        while(x > 0){
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1],node[2*x+2]);
        }
    }

    //要求区間[a,b)中の要素の最小値を答える
    //k := 自分がいるノードのインデックス
    //対象区間は[l,r)に当たる

    int getmin(int a, int b, int k=0, int l=0, int r=-1){
        //最初に呼び出されたときの対象区間は[0,n);
        if(r < 0) r = n;

        //要求区間と対象区間が交わらない -> INFを返す
        if(r <= a || b <= l) return INF;

        //要求区間が対象を完全に被覆している -> 対象区間の答えを計算に使う
        if(a <= l && r <= b) return node[k];

        //要求区間が対象区間の一部を被覆 -> 子について探索を行う
        //左側の子を vl，右側の子を vr としている
        //新しい対象区間は，現在の対象区間を半分に割ったもの
        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl,vr);
    }
};


// 抽象化再帰セグ木
template< typename Monoid >
struct AbsSegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;

    const F f;
    vector<Monoid> seg;
    int sz;
    const Monoid M1;

    AbsSegmentTree(vector< Monoid > &v, const F f, const Monoid &M1) : f(f), M1(M1) {
        int n = v.size();
        sz = 1;
        while(sz < n)sz <<= 1;
        seg.assign(2*sz, M1);
    }

    void build(vector < Monoid > &v){
        for(int i = 0; i < v.size(); i++)seg[i + sz] = v[i];

        for(int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[k * 2 + 0], seg[k * 2 + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }


    Monoid query(int a, int b, int k=1, int l=0, int r=-1) {
        if(r < 0)r = sz;
        if(a >= r || b <= l)return M1;
        if(a <= l && r <= b)return seg[k];

        Monoid L = query(a,b,k * 2 + 0, l, (l+r) / 2);
        Monoid R = query(a,b,2 * k + 1, (l+r)/2, r);
        return f(L, R);
    }
};

int main(){
    // int n,q;cin >> n >> q;
    // vector<int> xy[q];
    // rep(i,q){
    //     int com,x,y;cin >> com >> x >> y;
    //     // xy[i] = {com,x,y};
    //     xy[i].pb(com);xy[i].pb(x);xy[i].pb(y);
    // }
    // vector<int> a(n,INF);

    // SegmentTree seg(a);
    // rep(i,q){
    //     int com,x,y;
    //     com = xy[i][0];x = xy[i][1];y = xy[i][2];
    //     if(!com)seg.update(x,y);
    //     else cout << seg.getmin(x,y+1) << endl;

    // }
    // return 0;
    
    ll n,q; cin >> n >> q;
    vector<ll> a(n,numeric_limits<int>::max());
    AbsSegmentTree<ll> seg(a, [&](ll a, ll b){ return min(a,b); }, numeric_limits<int>::max());
    seg.build(a);
    rep(i,q){
        ll c,x,y; cin >> c >> x >> y;
        if(c == 0)seg.update(x, y);
        else cout << seg.query(x,y+1) << "\n";
    }
}