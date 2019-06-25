#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> ivec;
const ll N = 1e9+7;

string s;
int dfs(int i,int sum){
    if(i == s.size()+1) return sum;
    int d = s[i] - '0';
    

}

int main(){
    cin >> s;
    int len = s.size();
    int op2[3] = {};
    rep(i,(1 << (len-1))){
        int op[3] = {};
        int sum = 0;
        sum += s[0] - '0';
        // cout << "test" << endl;
        for(int j = len - 2;j >= 0; j--){
            if(1 & (i >> j)){
                op[2-j] = 1;
                sum += s[3-j] - '0';
                // cout << i << ' ' << j << endl;
            }
            else{
                op[2-j] = 0;
                sum -= s[3-j] - '0';
                // cout << i << ' ' << j << endl;
            }
        }
        if(sum == 7) {
            rep(i,3) op2[i] = op[i];
            break;
        }
    }
    string ans;
    rep(i,3){
        if(op2[i] == 1) ans.push_back('+');
        else ans.push_back('-');
    }
    rep(i,len-1){
        cout << s[i] << ans[i];
    }
    cout << s[3] << "=7" << endl;
    return 0;
}