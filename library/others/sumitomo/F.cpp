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
    ll t1,t2; cin >> t1 >> t2;
    ll a1,a2; cin >> a1 >> a2;
    ll b1,b2; cin >> b1 >> b2;
    if(t1*a1 + t2*a2 == t1*b1 + t2*b2){
        cout << "infinity" << endl;
        return 0;
    }
    ll res = 0;
    ll s1 = t1*(a1-b1);
    ll s2 = t2*(a2-b2);
    if(s1 < 0){
        s1 = -s1;
        s2 = -s2;
    }
    ll s = s1 + s2;
    if(0 < s1 && 0 < s2){
        res = 0;
    }
    else{
        if(s1 < abs(s2)){
            ll num = s1 / abs(s);
            if(s1%abs(s) == 0)res = num*2;
            else res = num*2+1;
        }
    }

    cout << res << endl;
}