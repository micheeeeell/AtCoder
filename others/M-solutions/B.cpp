#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)

using namespace std;
int main(){
    
    char N[15];cin >> N;
    int size = 0;
    for(int i = 0;i<15;i++){
        if(N[i]=='o')size++;
        else if(N[i]=='x')size++;
    }
    // cout << size;
    int win=0;
    for(int i = 0;i<size;i++){
        if(N[i]=='o') win++;
    }
    int remain = 0;
    remain = 15-size;
    int ans = 0;
    ans = win + remain;
    if(ans >=8){
        cout << "YES"<<endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}