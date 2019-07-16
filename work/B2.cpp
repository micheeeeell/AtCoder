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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll N = 1e9+7;
const int n_max = 1e5+10;

vector<int> node[n_max];
vector<int> depth(n_max,0);
vector<int> moved(n_max, 0);
vector<int> deg(n_max, 0);
vector<P> ans;

void dfs(int v, int pre = -1){
    for(auto to : node[v]){
        if(to != pre){
            if(moved[to] == 0){
                depth[to] = depth[v] + 1;
                moved[to] = 1;
                dfs(to,v);
            }
            else{
                if(depth[to] < depth[v]){
                    ans.pb(P(to,v));
                    deg[to]++;
                    // cout <<"to"  << ' ' <<  to  << ' ' << v << endl;
                }
            }
        }
    }

    if(pre != -1){
        if(deg[v] % 2){
            ans.pb(P(v,pre));
            deg[v]++;
        }
        else{
            ans.pb(P(pre,v));
            deg[pre]++;
        }
    }


}

int main(){
    int n,m; cin >> n >> m;
    // vi node[n];
    rep(i,m){
        int a,b; cin >> a >> b;
        a--;b--;
        node[a].pb(b);
        node[b].pb(a);
    }
    if(m%2){
        cout << -1 << endl;
        return 0;
    }
    moved[0]++;
    dfs(0);
    // cout << ans.size() << endl;
    for(auto p : ans) cout << p.first + 1  << ' ' << p.second + 1 << endl;
    return 0;

}