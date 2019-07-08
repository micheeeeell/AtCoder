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
    string sdash,t; cin >> sdash >> t;
    vector<int> hatena;
    rep(i,sdash.size()) if(sdash[i] == '?')hatena.pb(i);
    bool rewrite = false;
    rep(i,sdash.size()){
        if(sdash.substr(i,t.size()) == t) rewrite = true;
    }
    int hsize = 0;
    for(int i = (sdash.size()-1); 0 <= i;i--){
        if(sdash[i] == '?')hsize++;
        else hsize = 0;
        if(!rewrite && hsize == t.size()){
            rep(j,t.size()){
                sdash[i+j] = t[j];
            }
            rewrite = true;
        }
        rep(j,t.size()){
            bool ok = true;
            if(t[j] == sdash[i] && !rewrite){
                rep(k,j){
                    if(sdash[i-j+k] != '?' && sdash[i-j+k] != t[k]) ok = false;
                }
                rep(k,t.size()-j-1){
                    if(sdash[i+k+1] != '?' && sdash[i+k+1] != t[k]) ok = false;
                }
                if(ok){
                    rep(k,t.size()){
                        sdash[i-j+k] = t[k];
                    }
                    rewrite = true;
                    break;
                }
            }
        }
    }
    for(auto i : hatena){
        if(sdash[i] == '?') sdash[i] = 'a';
    }
    if(rewrite)cout << sdash << endl;
    else cout << "UNRESTORABLE" << endl;
    return 0;
}