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


int main(){
    int n,k; cin >> n >> k;
    ld a = 0;
    vector<int> vec;
    while(1){
        int temp = ceil(ld(k) / pow(2.0, a));
        vec.push_back(temp);
        // print(ld(k) / pow(2.0, a));
        a++;
        if(temp == 1)break;
    }
    reverse(vec.begin(), vec.end());
    // print(vec);
    ld ans = 0;
    for(int i = 1;i <= n;i++){
        auto itr = lower_bound(vec.begin(), vec.end(), i);
        int temp;
        if(itr == vec.end()){itr--; temp = itr - vec.begin();}
        else if(*itr == i)temp = itr - vec.begin();
        else temp = itr - vec.begin() - 1;
        temp = vec.size() - temp - 1;
        if(temp < 0)temp = 0;
        // print(temp);
        ans += (pow(0.5, temp) / ld(n));
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}