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
    int n;cin >> n;

    vector<int> node[n];
    rep(i,n){
        node[i].pb(i+1);
        node[i].pb(i+n+1);
    }
    vector<P> ans;
    int two = 20;
    set<ll> st;
    rep(i,two){
        st.insert(1 << i);
    }

    // for(auto itr = st.begin(); itr != st.end();itr++){
    //     cout << *itr << endl;
    // }
    // cout << st.insert(3).second << endl;
    if(!st.insert(n).second){
        cout << "No" << endl;
        return 0;
    }

    if(n%2){
        rep(i,n){
            if(i == 0)continue;
            if(i%2){
                ans.pb(P(node[0][0],node[i][0]));
                ans.pb(P(node[i][0],node[i+1][0]));
                ans.pb(P(node[0][0],node[i+1][1]));
                ans.pb(P(node[i+1][1],node[i][1]));
            }
        }
        ans.pb(P(node[0][1],node[2][0]));
    }
    else{
        rep(i,n-1){
            if(i == 0)continue;
            if(i%2){
                ans.pb(P(node[0][0],node[i][0]));
                ans.pb(P(node[i][0],node[i+1][0]));
                ans.pb(P(node[0][0],node[i+1][1]));
                ans.pb(P(node[i+1][1],node[i][1]));
            }
        }
        ans.pb(P(node[0][1],node[2][0]));
        // int temp = (n^3)-1;
        int temp = 0;
        int jud = 0;
        rep(j,two){
            if(n & (1 << j)){
                jud = (1 << j);
                temp = (n ^ jud);
                break;
            }
        }
        // cout << "temp" << temp << endl;
        ans.pb(P(node[temp][1],node[n-1][0]));
        ans.pb(P(node[n-1][1],node[jud-1][0]));
    }

    cout << "Yes" << endl;
    for(auto p : ans) cout << p.first  << " " << p.second << endl;
    return 0;

}