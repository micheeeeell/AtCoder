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

 int main(){
    ll n,m; cin >> n >> m;
    vector<ll> node[n];
    ll count[n] = {};
    rep(i,m){
        ll a,b; cin >> a >> b;
        a--;b--;
        node[a].pb(b);
        node[b].pb(a);
        count[a]++;count[b]++;
    }
    rep(i,n)sort(node[i].begin(),node[i].end(),greater<ll>());
    
    if(m%2){
        cout << -1 << endl;
        return 0;
    }
    vector<ll> node_ans[n];
    rep(i,n){
        int tmp = node[i].size();
        rep(j,tmp){

            if(count[i]%2){
                // count[i]--;
                ll temp = node[i].back();
                if(node[temp].size()>1){
                    node[i].pop_back();
                    node_ans[temp].pb(i);
                    node[temp].pop_back();
                    count[i]--;
                }
                else{
                    node_ans[i].pb(temp);
                    node[temp].pop_back();
                    node[i].pop_back();
                    count[temp]--;
                }

            }
            else{
                rep(j,node[i].size()){
                    node_ans[i].pb(node[i][j]);
                    node[node[i][j]].pop_back();
                    count[node[i][j]]--;
                } 
                break;
            }
        }
    }

    // rep(i,n){
    //     int tmpcnt = count[i];
    //     while(tmpcnt){
    //         if(!tmpcnt % 2){
    //             rep(j,2){
    //                 node_ans[i].pb(node[i][tmpcnt]);
    //                 node[node[i][tmpcnt]].pop_back();
    //                 count[node[i][tmpcnt]]--;
    //                 tmpcnt--;
    //             }
    //         }
    //         else{
    //             int temp = node[i][tempcnt];
    //             if(node[temp].size() > 1){
    //                 node[i].pop_back();
    //                 node_ans[temp].pb(i);
    //                 node[temp].pop_back();
    //                 tmpcnt--;
    //             }
    //             else{

    //             }
    //         }
    //     }
    // }

    rep(i,n){
        rep(j,node_ans[i].size())cout << i+1 << " " << node_ans[i][j]+1 << endl;
    }
    return 0;


 }