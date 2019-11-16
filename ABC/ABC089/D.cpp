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

ll dis(Pll a, Pll b){
    ll res = 0;
    res = abs(a.first - b.first) + abs(a.second - b.second);
    return res;
}

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

// template<typename T>
// void print(T &arr){
//     ll sz = sizeof(arr)/sizeof(arr[0]);
//     for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
//     cout << arr[sz-1] << endl;
// }


int main(){
    ll h,w; cin >> h >> w;
    ll d; cin >> d;
    vector<vector<ll>> a(h, vector<ll>(w));
    vector<Pll> rev_a(h*w);
    rep(i,h){
        rep(j,w){
            ll temp;cin >> temp;
            --temp;
            a[i][j] = temp;
            rev_a[temp] = Pll(i,j);
        }
    }
    ll q; cin >> q;
    vector<ll> l(q),r(q);
    rep(i,q){
        cin >> l[i] >> r[i];
        l[i]--;r[i]--;
    }


    vector<vector<ll>> step(d), sum_step(d);
    rep(i,d){
        step[i].emplace_back(0);
        ll now = i + d;
        while(now < h*w){
            ll temp = dis(rev_a[now], rev_a[now-d]);
            step[i].emplace_back(temp);
            now += d;
        }
    }

    rep(i,d){
        sum_step[i].emplace_back(0);
        ll sz = step[i].size();
        rep(j,sz){
            sum_step[i].emplace_back(step[i][j] + sum_step[i][j]);
        }
    }

    rep(i,q){
        ll xl = l[i] / d, y = l[i] % d;
        ll xr = r[i] / d;
        ll res = 0;
        res = sum_step[y][xr+1] - sum_step[y][xl+1];
        cout << res << "\n";
    }
    // print();
    // print("step");
    // print(step);
    // print();
    // print("sum_step");
    // print(sum_step);
    return 0;
}