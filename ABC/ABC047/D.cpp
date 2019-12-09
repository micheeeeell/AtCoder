#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = LLONG_MAX/4;
const int n_max = 1e5+10;

struct SegmentTree {
private:
    int n;
    vector<ll> node;

public:
    // 元配列 v をセグメント木で表現する
    SegmentTree(vector<ll> v) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        ll sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, -INF);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }

    void update(ll x, ll val){
        //最下段のノードにアクセスする
        x += (n - 1);

        //最下段のノードを更新したら，あとは親に上って更新していく
        node[x] = val;
        while(x > 0){
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1],node[2*x+2]);
        }
    }

    //要求区間[a,b)中の要素の最小値を答える
    //k := 自分がいるノードのインデックス
    //対象区間は[l,r)に当たる

    ll getmax(ll a, ll b, ll k=0, ll l=0, ll r=-1){
        //最初に呼び出されたときの対象区間は[0,n);
        if(r < 0) r = n;

        //要求区間と対象区間が交わらない -> INFを返す
        if(r <= a || b <= l) return -INF;

        //要求区間が対象を完全に被覆している -> 対象区間の答えを計算に使う
        if(a <= l && r <= b) return node[k];

        //要求区間が対象区間の一部を被覆 -> 子について探索を行う
        //左側の子を vl，右側の子を vr としている
        //新しい対象区間は，現在の対象区間を半分に割ったもの
        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl,vr);
    }
};

int main(){
    ll n,t; cin >> n >> t;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    SegmentTree seg(a);
    map<ll, ll> m;
    rep(i,n-1){
        ll ma = seg.getmax(i+1, n);
        m[a[i] - ma]++;
    }

    ll res = 0;
    auto itr = m.begin();
    debug((*itr).first);
    if((*itr).first < 0)res = (*itr).second;

    cout << res << endl;

}