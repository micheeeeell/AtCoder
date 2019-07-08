#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> ivec;
const ll N = 1e9+7;

const int nmax = 8,m = 100;
vector<int> ab[nmax];
// int V = 0,E = 0;
// int moved[n];
int dfs(int x, int n, bool moved[nmax]){
    // rep(i,n) cout << moved[i] << ' ' ;
    // cout <<endl;
    bool allmoved = true;
    rep(i,n){
        if(moved[i] == false) allmoved = false;
    }
    if(allmoved) {
        // cout << "test" << endl;
        return 1;
    }
    // moved[x] = 1;
    int ans = 0;
    rep(i,ab[x].size()){
        int v = ab[x][i];
        // if() continue;
        if(moved[v] == 0){
            moved[v] = 1;
            ans += dfs(v,n,moved);
            moved[v] = 0;
        }
    }
    // cout << "ans"  << ' ' << ans << endl;
    return ans;
}
// dfsでの実装
// int main(){
//     int n,m; cin >> n >> m;
//     // vector<int> ab[n];
//     rep(i,m){
//         int a,b; cin >> a >> b;
//         ab[a-1].pb(b-1);
//         ab[b-1].pb(a-1);
//     }
//     bool moved[n] = {};
//     moved[0] = true;
//     cout << dfs(0,n,moved) << endl;
//     return 0;
// }

// next_parmutationを用いた実装（全探索）
int main(){
    int n,m; cin >> n >> m;
    bool ab[n][n] = {};
    rep(i,m){
        int a,b; cin >> a >> b;
        a--;b--;
        ab[a][b] = true;
        ab[b][a] = true; 
    }
    vector<int> v(n-1);
    iota(v.begin(),v.end(),1);
    int ans = 0;
    do{
        bool ok = true;
        rep(i,n-1){
            if(i == 0){
                if(ab[0][v[i]] == false) ok = false;
            }
            else{
                if(ab[v[i-1]][v[i]] == false) ok = false;
            }
        }
        if(ok) {
            ans++;
            // rep(i,n-1)cout << v[i] << " ";cout << endl;
        }
    }while(next_permutation(v.begin(),v.end()));
    cout << ans << endl;
    return 0;
}