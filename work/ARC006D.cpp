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
const ll N = 1e9+7;
const int n_max = 1e5+10;
const int h_max = 1010;
const int w_max = 1010;

void print() {
  cout << endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) != 0) cout << " ";
  print(forward<Tail>(tail)...);
}

template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
}

template <class T>
void print(vector<vector<T>> &df) {
  for (auto& vec : df) {
    print(vec);
  }
}

vvi is_moved(h_max,vi(w_max,0));
ll dx[4] = {0,1,0,-1};
ll dy[4] = {1,0,-1,0};
ll ddx[4] = {1,1,-1,-1};
ll ddy[4] = {1,-1,1,-1};

string smap[h_max];
ll h,w;
ll all_count = 0;
ll lake_count = 0;
ll min_lake = INT_MAX;
ll min_y,max_y,y_size;
void dfs(ll x, ll y){
    is_moved[x][y] = 1;
    all_count++; lake_count++;
    min_y = min(y,min_y);
    max_y = max(y,max_y);
    // print(x,y,all_count,lake_count,min_lake);
    rep(i,4){
        ll nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && 0 <= ny && nx < h && ny < w &&smap[nx][ny] == 'o' && is_moved[nx][ny] == 0){
            dfs(nx,ny);
        }
        // min_lake = min(min_lake,lake_count);
    }
    min_lake = min(min_lake,lake_count);
    rep(i,4){
        ll nx = x + ddx[i], ny = y + ddy[i];
        if(0 <= nx && 0 <= ny && nx < h && ny < w &&smap[nx][ny] == 'o' && is_moved[nx][ny] == 0){
            lake_count = 0;
            dfs(nx,ny);
        }
    }
    min_lake = min(min_lake,lake_count);
}
int main(){
    cin >> h >> w;
    ll acount = 0, bcount = 0, ccount = 0;
    rep(i,h){
        cin >> smap[i];
    }
    rep(i,h){
        rep(j,w){
            if(smap[i][j] == 'o' && is_moved[i][j] == 0){
                all_count = 0;lake_count = 0;min_lake = INT_MAX;
                min_y = INT_MAX;max_y = 0;y_size = 0;
                dfs(i,j);
                y_size = (max_y - min_y + 1) / 5;
                ll temp = all_count / (y_size * y_size);
                // print(i,j);
                // print(all_count, y_size);
                // ll temp;
                // assert(all_count % min_lake == 0);
                if(temp == 12)acount++;
                else if(temp == 16)bcount++;
                else if(temp == 11) ccount++;
            }
        }
    }
    // rep(i,h){
    //     rep(j,w){
    //         cout << is_moved[i][j] << ' ';
    //     }
    //     cout << "\n";
    // }

    cout << acount  << ' ' << bcount  << ' ' << ccount << endl;
    return 0;

}