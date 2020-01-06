// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
// #include<aldorithm>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> t;
    rep(i,s.size())
        if(s[i] == 'd' && s[i+1] == 'r' && s[i+2] == 'e' && s[i+3] == 'a' && s[i+4] == 'm'){
            t.push_back(0);
        }
        else if(s[i] == 'e' && s[i+1] == 'r'){
            t.push_back(1);
        }
        else if(s[i] == 'a' && s[i+1] == 's' && s[i+2] == 'e'){
            t.push_back(2);
        }
    }
    // for(auto i:t )
    //     cout << i ;
    // cout << endl;
    bool ok = true;
    rep(i,t.size()){
        if(t[i] == 0 && t[i+1] == 2 ){
            ok = false;
            break;
        }
        else if(i > 1 && t[i-1] == 2 && t[i] == 2){
            ok = false;
            break;
        }
        else if(i > 2 && t[i-2] == 1 && t[i-1] == 1 && t[i] == 1){
            ok = false;
            break;
        }
        else if(i > 2 && t[i-2] == 1 && t[i-1] == 1 && t[i] == 0){
            ok = false;
            break;
        }

    }
    // cout << *(t.end()-1) << *(t.end()-2) << endl;
    if(*(t.end()-1) == 1 && *(t.end()-2) == 1){
        ok = false;
    }
    if(*(t.begin())==1 && *(t.begin()+1) == 1){
        ok = false;
    }

    if(ok){
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
        
}