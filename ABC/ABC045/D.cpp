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
#define eb emplace_back
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
const ll INF = LLONG_MAX/4;
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
    ll h,w,n; cin >> h >> w >> n;
    // bool gr[h][w];
    vector<ll> a(n), b(n);
    map<Pll,bool> used,m;
    rep(i,n){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        // gr[a[i]][b[i]] = 1;
        m[Pll(a[i],b[i])] = true;
        used[Pll(a[i],b[i])] = false;
    }
    // bool used[n];
    vector<ll> res(10,0);
    
    auto check = [&](ll x, ll y){
        for(int i = -2; i <= 0; i++){
            for(int j = -2;j <= 0; j++){
                ll xs = x + i;
                ll ys = y + j;
                if(xs < 0 || ys < 0 || h <= xs+2 || w <= ys + 2)continue;
                int temp = 0;
                bool ok = true;
                rep(ii,3)rep(jj,3){
                    // if(gr[xs + ii][ys + jj])temp++;
                    // if(m[Pll(xs+ii , ys+jj)])temp++;
                    auto it = m.find(Pll(xs+ii , ys+jj));
                    if(it != m.end()){
                        temp++;
                        if(used[Pll(xs+ii, ys+jj)])ok = false;
                    }
                }
                if(ok)res[temp]++;
            }
        }
        used[Pll(x,y)] = true;
    };
    rep(i,n)check(a[i], b[i]);
    ll sum = 0;
    rep(i,10)sum += res[i];
    res[0] = (h-2)*(w-2) - sum;
    print(res);
}