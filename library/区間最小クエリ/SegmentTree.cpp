#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> ivec;
const ll N = 1e9+7;
const ll INF = INT_MAX;


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

int main(){
    int n,q;cin >> n >> q;
    vector<int> xy[q];
    rep(i,q){
        int com,x,y;cin >> com >> x >> y;
        // xy[i] = {com,x,y};
        xy[i].pb(com);xy[i].pb(x);xy[i].pb(y);
    }
    vector<int> a(n,INF);

    SegmentTree seg(a);
    rep(i,q){
        int com,x,y;
        com = xy[i][0];x = xy[i][1];y = xy[i][2];
        if(!com)seg.update(x,y);
        else cout << seg.getmin(x,y+1) << endl;

    }
    return 0;

}