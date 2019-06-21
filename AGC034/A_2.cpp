#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)

using namespace std;


int main(){
    int n,a,b,c,d;
    string s;
    cin >> n >> a >> b >> c >> d;
    a--;b--;c--;d--;
    cin >> s;
    int temp=0;
    string ans = "Yes";

    if(c<d){
        for(int i = b+1;i<d;i++){
            if(s[i] == '#' && s[i+1] == '#') {
                ans = "No";
                // break;
            }
        }
        for(int j = a+1;j<c;j++){
            if(s[j] == '#' && s[j+1] == '#') {
                ans = "No";
                // break;
            }
        }
    }
    else{
        for(int i = b-1;i<d;i++){
            if(s[i] == '.' && s[i+1] == '.' && s[i+2] == '.'){
                temp = 1;
            }
        }
        for(int i = b+1;i<d;i++){
            if(s[i] == '#' && s[i+1] == '#') {
                ans = "No";
                // break;
            }
        }
        for(int j = a+1;j<c;j++){
            if(s[j] == '#' && s[j+1] == '#') {
                ans = "No";
                // break;
            }
        }
        
        if(temp != 1) ans ="No";

    }
    cout << ans <<endl;
    return 0;
}