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
template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1,INF);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1],node[i*2+2]);
    }

        // k 番目のノードについて遅延評価を行う
    void eval(int k, int l, int r) {

        // 遅延配列が空でない場合、自ノード及び子ノードへの
        // 値の伝播が起こる
        if(lazy[k] != 0) {
            node[k] -= lazy[k];

            // 最下段かどうかのチェックをしよう
            // 子ノードは親ノードの 1/2 の範囲であるため、
            // 伝播させるときは半分にする
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }

            // 伝播が終わったので、自ノードの遅延配列を空にする
            lazy[k] = 0;
        }
    }

    void sub(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;

        // k 番目のノードに対して遅延評価を行う
        eval(k, l, r);

        // 範囲外なら何もしない
        if(b <= l || r <= a) return;
        
        // 完全に被覆しているならば、遅延配列に値を入れた後に評価
        if(a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }

        // そうでないならば、子ノードの値を再帰的に計算して、
        // 計算済みの値をもらってくる
        else {
            sub(a, b, x, 2*k+1, l, (l+r)/2);
            sub(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1],node[2*k+2]);
        }
    }

    ll getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(b <= l || r <= a) return INF;

        // 関数が呼び出されたら評価！
        eval(k, l, r);
        if(a <= l && r <= b) return node[k];
        ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};


int main(){
    ll n; cin >> n;
    vector<ll> c(n), a;
    rep(i,n) cin >> c[i];
    rep(i,n)if(i%2 == 0)a.emplace_back(c[i]);
    rep(i,n)if(i%2 == 1)a.emplace_back(c[i]);
    ll ev = (n+2-1)/2;
    ll q; cin >> q;
    ll ans = 0;
    LazySegmentTree seg(a);
    rep(i,q){
        ll t; cin >> t;
        if(t == 1){
            ll x,num; cin >> x >> num;
            if(x%2 == 0)x = ev + x/2;
            else x = (x+1)/2;
            if(seg.getmin(x-1, x) >= num){
                // debug(seg.getmin(x-1, x));
                seg.sub(x-1, x, num);
                ans += num;
            }
        }
        else if(t == 2){
            ll num; cin >> num;
            if(seg.getmin(0,ev) >= num){
                // debug(seg.getmin(0,ev));
                seg.sub(0,ev,num);
                ans += num * ev;
            }
        }
        else{
            ll num; cin >> num;
            if(seg.getmin(0,n) >= num){
                // debug(seg.getmin(0,n))
                seg.sub(0,n,num);
                ans += n * num;
            }
        }
    }
    cout << ans << endl;
}