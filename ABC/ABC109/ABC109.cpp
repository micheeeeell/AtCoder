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

template<typename T>
void print(T &arr){
    ll sz = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0;i < sz-1;i++){cout << arr[i] << ' ';}
    cout << arr[sz-1] << endl;
}


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
const int h_max = 510, w_max = 510;
int h,w;
int is_moved[h_max][w_max] = {};
template<typename T, typename U>
void solve(vector<vector<T>> &mp,vector<vector<U>> &ans, int x, int y){
    is_moved[x][y] = 1;
    // if(px != -1 && mp[x][y]){
    //     if(mp[px][py]%2){
    //         mp[px][py]++;mp[x][y]--;
    //         vector<int> temp = {x+1, y+1, px+1, py+1};
    //         ans.push_back(temp);
    //     }
    // }
    rep(i,4){
        int nx = x + dx[i], ny = y + dy[i];
        if(is_moved[nx][ny] || nx < 0 || ny < 0 || h <= nx || w <= ny)continue;
        if(mp[x][y]%2){
            mp[x][y]--;mp[nx][ny]++;
            vector<int> temp = {x+1,y+1,nx+1,ny+1};
            ans.push_back(temp);
        }
        solve(mp,ans,nx,ny);
        // solve(mp,ans,nx,ny,x,y);
    }
}


int main(){
    cin >> h >> w;
    vector<vector<int>> a(h,vector<int>(w));
    rep(i,h)rep(j,w)cin >> a[i][j];

    vector<vector<int>> ans;
    solve(a,ans,0,0);
    // print(a);
    // print();
    cout << ans.size() << endl;
    print(ans);
    return 0;
}