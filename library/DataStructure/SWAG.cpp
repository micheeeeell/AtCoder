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

template<class T>
bool chmax(T &a, T b){if(a < b){a = b; return true;} return false;}
template<class T>
bool chmin(T &a, T b){if(a > b){a = b; return true;} return false;}

int main(){
    ll n,m; cin >> n >> m;
    string s;cin >> s;
    vector<ll> step(n+1, INF);
    step[n] = 0;
    auto f = [](const auto &a, const auto &b){
        return min(a,b);
    };
    SlidingWindowAggregation<ll> swag(f, INF);
    swag.push(0);
    for(int i = n-1; 0 <= i; i--){
        if(s[i] == '0'){
            step[i] = swag.accumulate() + 1;
        }
        if(swag.size() > m-1)swag.pop();
        swag.push(step[i]);
    }
    if(step[0] >= INF){
        cout << -1 << endl;
        return 0;
    }
    vector<ll> ans;
    ll stemp = step[0];
    ll cnt = 0;
    ll pos = 1;
    while(stemp){
        cnt++;
        if(step[pos] < stemp){
            ans.emplace_back(cnt);
            cnt = 0;
            stemp = step[pos];
        }

        pos++;
    }

    for(auto v : ans)cout << v << " ";
    cout << endl;
}