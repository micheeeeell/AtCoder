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
    int n,k; cin >> n >> k;
    string s; cin >> s;
    int start = 0,end = 0;
    vector<P> lake;
    rep(i,n){
        if(!i) continue;
        int now = s[i] - '0';
        int pre = s[i-1] - '0';
        // cout << now  << ' ' << pre<< endl;
        if(!now && pre){
            start = i;
        }
        if(now && !pre || (i == n-1 && !now)){
            end = i-1;
            lake.push_back(P(start,end));
        }
    }
    int lsize = lake.size();
    int ans = 0;
    rep(i,lsize-k+1){
        int one_start,one_end;
        if(lake[i].first == 0 || i == 0)one_start = 0;
        else one_start = lake[i-1].second + 1;
        if(lake[i+k-1].second == n-1 || i+k-1 == lsize-1)one_end = n-1;
        else one_end = lake[i+k].first - 1;
        ans = max(ans, one_end - one_start + 1);
    }
    // rep(i,lake.size()) cout << lake[i].first  << ' ' << lake[i].second << endl;
    // cout << lake.size() << endl;

    if(lsize > k)cout << ans << endl;
    else cout << n << endl;
    return 0;
}