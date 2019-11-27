#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;


int main(){
    ll a,b,k; cin >> a >> b >> k;
    ll temp = 0;
    ll res;
    for(int i = 100;0 < i;i--){
        if(!i)continue;
        if(a%i == 0 && b%i == 0){
            temp++;
            if(temp == k){
                res = i;
                break;
            }
        }
        
    }
    cout << res << endl;
}