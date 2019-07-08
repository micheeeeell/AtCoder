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

int main(){
    string s;cin >> s;
    // rep(i,4) cin >> s[i];
    int count[4] = {};
    // int sj[4];
    // sj[0] = s[0] - 'a';
    // count[0]++;
    
    for(int i = 0; i< 4;i++){
        rep(j,4){
            if(s[i]== s[j]){
                count[j]++;
            }
            // else count[i]++;
        }
    }
    bool ok = true;
    rep(i,4){
        if(count[i] != 0 && count[i] != 2) ok = false;
    }
    // rep(i,4) cout << count[i] ;
    // cout << endl;
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}