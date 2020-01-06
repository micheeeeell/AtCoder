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

class Edge{
    public:
    int from,to,cost;
    void print(){
        cout << from << " " << to << " " << cost << "\n";
        return;
    }
};

int main(){
    ll n; cin >> n;
    int node_max = 0;
    while(pow(2,node_max) <= n)++node_max;
    node_max--;

    // cout << node_max << endl;
    vector<Edge> ans;
    rep(i,node_max){
        Edge temp1 = {i+1, i+2, 0};
        Edge temp2 = {i+1, i+2, (int)pow(2,i)};
        ans.push_back(temp1);
        ans.push_back(temp2);
    }
    // vector<int> node(node_max);
    for(int i = node_max-1;0 <= i; i--){
        if(n-pow(2,i) >= pow(2,node_max)){
            Edge temp = {i+1,node_max+1,(int)(n-pow(2,i))};
            ans.push_back(temp);
            n -= pow(2,i);
        }
    }
    cout << node_max + 1 << " " << ans.size() << endl;
    for(auto i : ans)i.print();
    return 0;
}