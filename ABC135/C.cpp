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
    ll n; cin >> n;
    vector<ll> a(n+1);
    rep(i,n+1) cin >> a[i];
    vector<ll> b(n);
    rep(i,n) cin >> b[i];

    ll ans = 0;
    while(a.size() > 1){
        ll alast = a.back();a.pop_back();
        ll alast2 = a.back();a.pop_back();
        ll blast = 0;
        ll temp = 0;
        assert(b.size() > 0);
        blast = b.back();b.pop_back();
        
        if(alast <= blast){
            temp = alast + alast2;
            if(temp >= blast){
                ans += blast;
                temp -= blast;
            }
            else{
                ans += temp;
                temp = 0;
            }
            a.push_back(temp);
        }
        else{
            ans += blast;
            a.push_back(alast2);
        }

    }
    cout << ans << endl;
    return 0;

}