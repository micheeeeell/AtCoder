#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
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

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll t_sum = 0;
    vector<ll> t(n+2,0);
    
    rep(i,n){
        cin >> t[i+1];
        t_sum += t[i+1];
    }
    rep(i,n+1)t[i+1] += t[i];
    vector<ll> v(n+2,0);
    rep(i,n) cin >> v[i+1];
    vector<ld> speed(2*t_sum + 10,0);
    ll cnt = 0;
    rep(i,2*t_sum){
        // if(!i)continue;
        if(i < 2*t[cnt])speed[i] = v[cnt];
        else{
            speed[i] = min(v[cnt],v[cnt+1]);
            cnt++;
        }
    }
    // rep(i,2*t_sum+1){
    //     print(i*0.5,"\t", speed[i]);
    // }
    // print(speed);
    rep(i,2*t_sum){
        speed[i+1] = min(speed[i+1], speed[i] + 0.5);
    }
    // print(speed);
    for(int i = 2*t_sum; 0 < i;--i){
        speed[i-1] = min(speed[i-1],speed[i] + 0.5);
    }
    // print(speed);
    // rep(i,2*t_sum+1){
    //     print(i*0.5,"\t", speed[i]);
    // }
    ld res = 0;
    rep(i,2*t_sum){
        res += ld(0.5 * (speed[i] + speed[i+1]) * 0.5);
    }
    cout << fixed;
    cout << setprecision(10) << res << endl;
}