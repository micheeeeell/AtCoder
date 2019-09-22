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
const ll N = 1e9+7;
const int n_max = 1e5+10;

int main(){
    string s;cin >> s;
    int len = s.size();
    int count = 0;
    string pre = "",now = "";
    int state = 0;
    while(len){
        now += s[state];
        // cout << "now" << ' ' << now  << ' ' << "pre" << ' ' << pre << endl;
        if(now == pre){
            state++;
            len--;
            continue;
        }
        count++;
        pre = now;
        now = "";
        state++;
        len--;
    }
    cout << count << endl;
    return 0;

}