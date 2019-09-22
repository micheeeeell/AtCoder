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

vector<int> z(string s){
    int len = s.size();
    vector<int> res(len);
    res[0] = len;
    int i = 1, j = 0;
    while(i < len){
        while(i+j < len && s[j] == s[i+j]) ++j;
        res[i] = j;
        if(j == 0){ ++i; continue;}
        int k = 1;
        while(i+k < len && k+res[k] < j){
            res[i+k] = res[k], ++k;
        }
        i += k; j -= k;
    }
    rep(i,len){
        res[i] = min(res[i], i);
    }
    return res;
}

int main(){
    ll n; cin >> n;
    string s;cin >> s;
    ll ans = 0;
    rep(i,n){
        vector<int> vec = z(s.substr(i));
        // auto itr = vec.begin();itr++;
        ll temp = *max_element(vec.begin(), vec.end());
        ans = max(ans,temp);
    }
    cout << ans << endl;
    return 0;
}