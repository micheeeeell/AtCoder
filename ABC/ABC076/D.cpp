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
    // t[n+1]++;
    vector<ll> v(n+2,0);
    rep(i,n) cin >> v[i+1];
    ll max_t = 2e4 + 10;

    // i 秒時の速度
    vector<ll> speed(t_sum + 10,0);
    // i + 0.5秒時の速度
    vector<ld> speed_half(t_sum + 10,0);
    ll cnt = 0;
    rep(i,t_sum + 1){
        if(i < t[cnt]){
            speed[i] = v[cnt];
            speed_half[i] = v[cnt];
        }
        // else if(i == t[cnt]){
        //     speed[i] = v[cnt];
        //     speed_half[i] = v[cnt+1];
        // }
        else{
            cnt++;
            speed[i] = v[cnt];
            speed_half[i] = v[cnt];
        }
    }

    speed[0] = 0;speed_half[t_sum-1] = 0;

    print(speed);
    print(speed_half);
    rep(i,n+1){
        if(v[i+1] <= v[i])continue;
        ll time = t[i]+1;
        ll temp_sp = v[i];
        while(temp_sp < speed[time]){
            speed[time] = min(speed[time],temp_sp+1);
            speed_half[time-1] = min(speed_half[time-1],temp_sp+ld(0.5));
            time++;temp_sp++;
        }
    }
    print(speed);
    print(speed_half);

    for(ll i = n+1; 0 < i; --i){
        if(v[i-1] < v[i])continue;
        ll time = t[i-1];
        ll temp_sp = v[i];
        while(temp_sp < speed[time]){
            speed[time] = min(speed[time], temp_sp + 1);
            speed_half[time] = min(speed_half[time],temp_sp+ld(0.5));
            time--;temp_sp++;
        }
    }
    // speed[t[n+1]] = 0;

    print(speed);
    print(speed_half);
    rep(i,t_sum+2){
        print(speed[i],speed_half[i]);
    }
}