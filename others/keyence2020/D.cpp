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

void print(Pll &p){
    print(p.first, p.second);
}


int main(){
    ll n; cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    bool ok = false;
    ll ans = INF;
    using Plll = pair<ll, Pll>;
    
    rep(i,(1LL << n)){
        priority_queue<Plll, vector<Plll>, greater<Plll>> pq;
        rep(j,n){
            if((i >> j) & 1)pq.push(Plll(b[j],Pll(j,1)));
            else pq.push(Plll(a[j],Pll(j,0)));
        }
        ll cnt = 0;
        ll move = 0;
        bool temp = true;
        while(pq.size()){
            Plll t = pq.top();pq.pop();
            vector<Plll> vec;
            vec.emplace_back(t);
            Plll p = pq.top();
            while(p.first == t.first && pq.size()){
                vec.emplace_back(p);
                pq.pop();
                p = pq.top();
            }
            sort(all(vec),[&](const auto &a, const auto &b){
                return abs(a.second.first-cnt) < abs(b.second.first-cnt);
            });
            // debug(i);
            // for(auto j : vec)print(j.first, j.second.first, j.second.second);
            bool bo = false;
            ll use;
            for(auto j : vec){
                if(abs(j.second.first-cnt) % 2 == j.second.second){
                    move += abs(j.second.first-cnt);
                    cnt++;
                    bo = true;
                    use = j.second.first;
                    break;
                }
            }
            // if(abs(t.second.first - cnt) % 2 == t.second.second) {
            //     move += abs(t.second.first - cnt);
            //     cnt++;
            //     bo = true;
            //     // debug(t.first);
            //     // debug(t.second.first);
            //     // debug(t.second.second);
            // }
            temp &= bo;
            if(!bo)break;
            for(auto j : vec){
                if(j.second.first != use)pq.push(j);
            }
        }
        if(temp){
            // debug(i);
            // debug(move);
            chmin(ans, move/2);
        }
    }

    if(ans == INF)cout << -1 << endl;
    else cout << ans << endl;
}