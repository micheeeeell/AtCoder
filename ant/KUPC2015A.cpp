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

void erase(string* s,int n){
    (*s).erase((*s).begin(),(*s).begin()+n);
}

int main(){
    int t; cin >> t;
    string s[t];
    rep(i,t)cin >> s[i];
    ivec ans(t);
    rep(i,t){
        while(s[i].size()){
            // cout << "test" << endl;
            if(s[i].size() < 5){
                erase(&s[i],s[i].size());
                // cout << "1" << endl;
                continue;
            }
            if(s[i][0] != 't' && s[i][0] != 'k'){
                erase(&s[i],1);
                // cout << "2" << endl;
                continue;
            }
            if(s[i].substr(0,5) == "tokyo"){
                ans[i]++;
                erase(&s[i],5);
                // cout << "3" << endl;
            }
            else if(s[i].substr(0,5) == "kyoto"){
                ans[i]++;
                erase(&s[i],5);
                // cout << "4" << endl;
            }
            else{
                erase(&s[i],1);
                // cout << "5" << endl;
            }
        }
    }
    rep(i,t)cout << ans[i] << endl;
    return 0;
}