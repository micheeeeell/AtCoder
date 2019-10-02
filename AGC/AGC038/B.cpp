#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;
const ll INF = INT_MAX;

struct SegmentTreeMin {
private:
    int n;
    vector<int> node;

public:
    // 元配列 v をセグメント木で表現する
    SegmentTreeMin(vector<int> v) {
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

struct SegmentTreeMax {
private:
    int n;
    vector<int> node;

public:
    // 元配列 v をセグメント木で表現する
    SegmentTreeMax(vector<int> v) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val){
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

    int getmax(int a, int b, int k=0, int l=0, int r=-1){
        //最初に呼び出されたときの対象区間は[0,n);
        if(r < 0) r = n;

        //要求区間と対象区間が交わらない -> -INFを返す
        if(r <= a || b <= l) return -INF;

        //要求区間が対象を完全に被覆している -> 対象区間の答えを計算に使う
        if(a <= l && r <= b) return node[k];

        //要求区間が対象区間の一部を被覆 -> 子について探索を行う
        //左側の子を vl，右側の子を vr としている
        //新しい対象区間は，現在の対象区間を半分に割ったもの
        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
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
    int n,k; cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    SegmentTreeMin seg_min(p);
    SegmentTreeMax seg_max(p);
    vector<int> is_sorted(n,0);
    int tmp = 0;
    for(int i = n-1;0 <= i; i--){
        if(i == n-1){tmp++;continue;}
        if(p[i] <= p[i+1])tmp++;
        else tmp = 1;
        if(k <= tmp)is_sorted[i] = 1;
        // print(i, tmp);
    }
    // print(is_sorted);
    ll res = 0;
    bool ok = false;
    if(*max_element(is_sorted.begin(), is_sorted.end()))ok = true;
    vector<int> ans(n);
    rep(i,n-k){
        // ans.push_back(res+1);
        if(seg_min.getmin(i,i+k+1) == p[i] && seg_max.getmax(i,i+k+1) == p[i+k]) continue;
        // print(i, i+k, seg_min.getmin(i,i+k+1), seg_max.getmax(i,i+k+1));
        if(is_sorted[i])continue;
        res++;
        ans[i] = res;
    }
    if(n == k){
        cout << 1 << endl;
        return 0;
    }
    if(!is_sorted[n-k])res++;
    if(ok)res++;
    ans[n-1] = res;
    // print(ans);
    cout << res << endl;
    return 0;
}