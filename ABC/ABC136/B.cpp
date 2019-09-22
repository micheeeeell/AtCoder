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
    int n; cin >> n;
    int ans = 0;
    if(n <= 9){
        ans = n;
        cout << ans << endl;
        return 0;
    }
    else ans += 9;
    if(n <= 99){
        cout << ans << endl;
        return 0;
    }
    else if(n <= 999){
        ans += (n-99);
        cout << ans << endl;
        return 0;
    }
    else ans += 900;
    if(n <= 9999){
        cout << ans << endl;
        return 0;
    }
    else if(n <= 99999){
        ans += (n-9999);
        cout << ans << endl;
        return 0;
    }
    else if(n == 100000){
        ans += 90000;
        cout << ans << endl;
        return 0;
    }
    return 0;
} 
