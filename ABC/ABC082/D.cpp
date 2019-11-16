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


int main(){
    string s;cin >> s;
    // string s;
    // rep(i,8000){
    //     s += "F";
    // }
    ll x,y; cin >> x >> y;
    vector<ll> xv, yv;
    ll temp = 0;
    ll n = s.size();
    bool is_x = true;
    bool first = false;
    if(s[0] == 'F')first = true;
    rep(i,n+1){
        if(i == n){
            if(!temp)continue;
            if(is_x) xv.emplace_back(temp);
            else yv.emplace_back(temp);
            temp = 0;
        }
        if(s[i] == 'F')temp++;
        else{
            if(!temp){
                is_x = !is_x;
                continue;
            }
            if(is_x) xv.emplace_back(temp);
            else yv.emplace_back(temp);
            temp = 0;
            is_x = !is_x;
        }
    }

    // print(xv);
    // print(yv);
    ll MAX = 8080;
    ll xvs = xv.size(), yvs = yv.size();
    vvl dp_x(xvs+1, vl(2*MAX,0));
    vvl dp_y(yvs+1, vl(2*MAX,0));
    dp_x[0][MAX] = 1;
    rep(i,xvs){
        if(first && i == 0){
            dp_x[1][MAX+xv[0]] = 1;
            continue;
        }
        rep(j,2*MAX){
            if(dp_x[i][j]){
                dp_x[i+1][j+xv[i]] = 1;
                dp_x[i+1][j-xv[i]] = 1;
            }
        }
    }
    dp_y[0][MAX] = 1;
    rep(i,yvs){
        rep(j,2*MAX){
            if(dp_y[i][j]){
                dp_y[i+1][j+yv[i]] = 1;
                dp_y[i+1][j-yv[i]] = 1;
            }
        }
    }

    // rep(i,2*MAX){
    //     if(dp_x[xvs][i])print(i-MAX);
    // }

    cout << (dp_x[xvs][x+MAX] && dp_y[yvs][y+MAX] ? "Yes" : "No") << endl;

}