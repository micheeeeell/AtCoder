#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
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

// nはサイズ，fはfunction, M1はMonoidの単位元
// SegmentTree(n, f, M1):= サイズ n の初期化。
// ここで f は2つの区間の要素をマージする二項演算, M1 はモノイドの単位元である。
// set(k, x):= k 番目の要素に x を代入する。
// build():= セグメント木を構築する。
// query(a, b):= 区間 [a,b) に対して二項演算した結果を返す。
// update(k, x):= k 番目の要素を x に変更する。
// operator[k] := k 番目の要素を返す。
// find_first(a, check) := [a,x) が check を満たす最初の要素位置 x を返す。
// find_last(b, check) := [x,b) が check を満たす最後の要素位置 x を返す。
template< typename Monoid >
struct SegmentTree {
    using F = function< Monoid(Monoid, Monoid) >;

    int sz;
    vector< Monoid > seg;

    const F f;
    const Monoid M1;
    SegmentTree(vector< Monoid > &vec, const F f, const Monoid &M1) : f(f), M1(M1) {
        int n = vec.size();
        sz = 1;
        while(sz < n)sz <<= 1;
        seg.assign(2*sz, M1);
    }

    void set(int k, const Monoid &x) {
        seg[k + sz] = x;
    }

    void build(vector< Monoid > &vec) {
        for(int i = 0; i < vec.size(); i++)set(i, vec[i]);
        for(int k = sz - 1; k > 0; k--) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    void update(int k, const Monoid &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) {
            seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }
    }

    Monoid query(int a, int b) {
        Monoid L = M1, R = M1;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) L = f(L, seg[a++]);
            if(b & 1) R = f(seg[--b], R);
        }
        return f(L, R);
    }

    Monoid operator[] (const int &k) const {
        return seg[k + sz];
    }

    template< typename C >
    int find_subtree(int a, const C &check, Monoid &M, bool type) {
        while(a < sz) {
            Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
            if(check(nxt)) a = 2 * a + type;
            else M = nxt, a = 2 * a + 1 - type;
        }
        return a - sz;
    }

    template< typename C >
    int find_first(int a, const C &check) {
        Monoid L = M1;
        if(a <= 0) {
            if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
            return -1;
        }
        int b = sz;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) {
                Monoid nxt = f(L, seg[a]);
                if(check(nxt)) return find_subtree(a, check, L, false);
                L = nxt;
                ++a;
            }
        }
        return -1;
    }

    template< typename C >
    int find_last(int b, const C &check) {
        Monoid R = M1;
        if(b >= sz) {
            if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int a = sz;
        for(b += sz; a < b; a >>= 1, b >>= 1) {
            if(b & 1){
                Monoid nxt = f(seg[--b], R);
                if(check(nxt)) return find_subtree(b, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
};


int main(){
    ll n; cin >> n;
    string s;cin >> s;
    ll q; cin >> q;
    auto f = [](const auto &a, const auto &b){return a + b;};
    vector<ll> vec(n,0);
    SegmentTree<ll> seg(vec, f, 0);
    vector<SegmentTree<ll>> g(26, seg);
    rep(i,26)g[i].build(vec);
    rep(i,n){
        ll t = s[i] - 'a';
        g[t].update(i, 1);
    }

    rep(i,q){
        ll c; cin >> c;
        if(c == 1){
            ll k; cin >> k;
            k--;
            char t;cin >> t;
            ll tnum = t - 'a';
            if(s[k] != t){
                g[tnum].update(k,1);
                g[s[k] - 'a'].update(k,0);
                s[k] = t;
            }
        }
        else {
            ll l,r; cin >> l >> r;
            l--;r--;
            ll ans = 0;
            rep(j,26){
                if(g[j].query(l, r+1) > 0)ans++;
            }
            cout << ans << "\n";
        }
    }
}