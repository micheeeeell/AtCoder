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

// 含んでいる monoid の要素全体の積をO(1)で取得できるような queue を拡張したデータ構造。
// stack ふたつで queue を作るやつを応用して実現される
// stack二つで実装してますがdequeでinline化することも可能(実装予定、なし！w)
// fがmonoidの演算子
// M1がfの単位元
// push:= 要素の追加
// pop := 要素の削除
// これらは後入れ先出し(conf. queue)
// accumulate  := 含まれているmonoid全体の積を計算
// empty, size := はい 

template<typename Monoid>
struct SlidingWindowAggregation {
    using F = function< Monoid(Monoid, Monoid) >;

    stack< Monoid > front,back;
    stack< Monoid > sum_front;
    Monoid sum_back;
    const F f;
    const Monoid M1;
    SlidingWindowAggregation (const F f, const Monoid &M1) : f(f), M1(M1) {
        sum_front.push(M1);
        sum_back = M1;
    }

    void push(Monoid x) {
        back.push(x);
        sum_back = f(sum_back, x);
    }

    void pop() {
        if(front.empty()) {
            while(! back.empty()) {
                front.push(back.top());
                sum_front.push(f(front.top(), sum_front.top()));
                back.pop();
            }
            sum_back = M1;
        }
        assert(! front.empty());
        front.pop();
        sum_front.pop();
    }

    Monoid accumulate() const {
        return f(sum_front.top(), sum_back);
    }
    
    bool empty() const {
        return front.empty() && back.empty();
    }

    size_t size() const {
        return front.size() + back.size();
    }
};

int main(){
    ll n; cin >> n;
    string s;cin >> s;
    ll q; cin >> q;
    vector<ll> k(q);
    rep(i,q) cin >> k[i];
    auto f = [](auto a, auto b){
        return a + b;
    };
    
    rep(i,q){
        ll kt = k[i];
        ll cnt = 0;
        ll ans = 0;
        SlidingWindowAggregation<ll> d_num(f, 0), m_num(f,0);
        rep(i,n){
            if(s[i] == 'D')d_num.push(1);
            else d_num.push(0);
            if(s[i] == 'M'){
                m_num.push(1);
                cnt += d_num.accumulate();
            }
            else m_num.push(0);
            if(m_num.size() > kt){
                m_num.pop();
                d_num.pop();
                if(s[i-kt] == 'D')cnt -= m_num.accumulate();
            }
            if(s[i] == 'C')ans += cnt;
            // debug(i);debug(s[i]);debug(cnt);debug(ans);
        }
        cout << ans << endl;
    }
}