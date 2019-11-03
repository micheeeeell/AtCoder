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


// "A C G T" := "1 2 3 4";
ll memo[110][9999] = {};
int n;

bool ok(int x){
    assert(1000 <= x && x <= 9999);
    vector<int> t(4);
    rep(i,4){
        t[0] = x/1000; t[1] = (x - t[0] *1000)/100;
        t[2] = (x - (x/100)*100)/10; t[3] = x - (x/10)*10;
        if(i){
            int temp;
            temp = t[i-1]; t[i-1] = t[i]; t[i] = temp;
        }
        rep(j,2){
            if(t[j] == 1 && t[j+1] == 3 && t[j+2] == 2) return false;
        }
        // print(t);
    }
    return true;
}

ll dfs(int cur, int last3){
    assert(100 <= last3 && last3 <= 999);
    if(memo[cur][last3]) return memo[cur][last3];
    if(cur == n) return 1;
    ll ret = 0;
    for(int i = 1; i <= 4; i++){
        int last4 = last3 * 10 + i;
        if(ok(last4)){
            int next3 = last4 - (last4/1000)*1000;
            ret = (ret + dfs(cur + 1, next3)) % MOD;
        }
    }
    memo[cur][last3] = ret;
    return ret;
}


int main(){
    cin >> n;
    cout << dfs(0,444) << endl;
    return 0;
}