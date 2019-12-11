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
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

template<typename T>
struct SegmentTree {
private:
    ll n;
    vector<ll> node;

public:
    // 元配列 v をセグメント木で表現する
    SegmentTree(vector<ll> v) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        ll sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for(ll i=0; i<sz; i++) node[i+n-1] = v[i];
        for(ll i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
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
        if(r <= a || b <= l) return 0;

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

void print() {
    cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
    cout << head;
    if (sizeof...(tail) != 0) cout << ' ';
    print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
    for (auto& a : vec) {
        cout << a;
        if (&a != &vec.back()) cout << ' ';
    }
    cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
    for (auto& vec : df) {
        print(vec);
    }
}

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}

int main(){
    ll n; cin >> n;
    vector<Pll> pre(n);
    rep(i,n){
        ll w,h; cin >> w >> h;
        pre[i] = Pll(w,h);
    }
    sort(all(pre),
    [&](const auto &a, const auto &b){
        return (a.first < b.first) || (a.first == b.first && a.second > b.second);
    });
    vector<ll> dp(n,0);
    vector<ll> a(n_max,0);
    SegmentTree<ll> seg(a);
    dp[0] = 1;
    seg.update(pre[0].second,1);
    rep(i,n-1){
        dp[i+1] = seg.getmax(0,pre[i+1].second) + 1;
        seg.update(pre[i+1].second, dp[i+1]);
    }
    // print(dp);
    ll ret = 0;
    rep(i,n){ret = max(ret, dp[i]);}
    cout << ret << endl;
}