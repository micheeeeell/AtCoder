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

int main(){
    ll n; cin >> n;
    vector<ll> p(n), arr(n);
    rep(i,n){
        ll p[i]; cin >> p[i];
        arr[p[i] - 1] = i;
    }

    ll temp = 0, ans = 0;
    rep(i,n){
        if(!i){
            temp++;continue;
        }
        if(arr[i] > arr[i-1]){
            temp++;
        }
        else{
            ans = max(temp, ans);
            temp = 1;
        }
    }
    ans = max(ans, temp);

    cout << n-ans << endl;
    return 0;
}