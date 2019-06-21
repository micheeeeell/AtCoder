#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
typedef long long ll;
using namespace std;
const int N = 1e5+5;
vector<int> neigh[N];
int ans[N];
int m = 0;
int used[N];
vector<int> c(N);

int dfs(int v){
    used[v] = 1;
    ans[v] = c[m];
    m++;
    for(int u:neigh[v]){
        if(!used[u]){
            dfs(u);
        }
    }
}

int main(){
    int n; cin >> n;
    vector<int> a(n-1),b(n-1);
    rep(i,n-1){
        cin >> a.at(i) >> b.at(i);
        a.at(i)--;b.at(i)--;
    }
    
    rep(i,n){
        cin >> c.at(i);
    }
    sort(c.begin(),c.end(),greater<int>());
    // rep(i,n) cout << c[i] << endl;
    
    rep(i,n-1){
        neigh[a.at(i)].push_back(b.at(i));
        neigh[b.at(i)].push_back(a.at(i));
    }
    int sum = 0;
    for(int i = 1;i < n; i++){
        sum += c.at(i);
    }
    dfs(0);

    cout << sum << endl;
    rep(i,n) cout << ans[i] << " ";
    return 0;

}
