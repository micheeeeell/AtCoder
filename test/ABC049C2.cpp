// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cmath>
// #include<aldorithm>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)

using namespace std;

void erase(string* s, int n){
    (*s).erase((*s).begin(),(*s).begin()+n);
}

int main(){
    string s;
    cin >> s;
    vector<int> t;
    string s_rev;
    bool ok = true;
    while(s.size() != 0){
        if(s.substr(0,5) != "dream" && s.substr(0,5) != "erase"){
            ok = false;
            break;
        }

        if(s.substr(0,5) == "dream"){
            if(s.substr(5,2) == "er"){
                if(s.substr(5,5) == "erase"){
                    erase(&s, 5);
                    // cout << s;
                }
                else{
                    erase(&s,7);
                }
            }
            else{
                erase(&s, 5);
            }
        }

        else if(s.substr(0,5) == "erase"){
            if(s.substr(5,1) == "r"){
                erase(&s, 6);
            }
            else{
                erase(&s, 5);
            }
        }
    }

    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
   
}
