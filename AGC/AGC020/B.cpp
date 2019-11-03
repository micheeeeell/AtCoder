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


// void print(P x){
//     cout << x.first << " " << x.second << endl;
//     return ;
// };

int main(){
    int k; cin >> k;
    vector<ll> a(k);
    rep(i,k) cin >> a[i];
    vector<pair<ll, ll>> res(k);

    // mを超えない，xで割るとr余る最大の数
    auto remaind = [](ll m, ll x, ll r){
        ll temp = (m / x)*x + r;
        if(m < temp)temp -= x;
        // print("remaind");
        // print(m,x,r,temp);
        assert(m >= temp);
        return temp;
    };

    // mを超える，xで割るとr余る最大の数
    auto over = [](ll m, ll x, ll r){
        ll temp = (m / x)*x + r;
        if(m > temp)temp += x;
        // print("over");
        // print(m,x,r,temp);
        assert(m <= temp);
        return temp;
    };
    bool ok = true;
    if(a[k-1] == 2){
        res[k-1] = Pll(2,3);
    }else{
        ok = false;
    }
    for(int i = k-2; 0 <= i; --i){
        ll mi,ma;
        ma = remaind(res[i+1].second + a[i]-1, a[i], a[i]-1);
        mi = over(res[i+1].first, a[i], 0);
        if(mi > ma){ok = false;break;}
        res[i] = Pll(mi,ma);
    }
    if(ok) print(res[0].first, res[0].second);
    else cout << -1 << endl;
    return 0;

}