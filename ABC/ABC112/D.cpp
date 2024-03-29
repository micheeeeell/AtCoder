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
    ll n,m; cin >> n >> m;
    priority_queue<ll> pq;
    rep(i,sqrt(m)+1){
        if(!i)continue;
        if(m%i == 0){
            pq.push(i);
            pq.push(m/i);
        }
    }

    bool ok = true;
    ll ans = 0;
    while(ok){
        ll temp = pq.top();pq.pop();
        if(n * temp <= m){
            ans = temp;
            ok = false;
        }
    }

    cout << ans << endl;
    return 0;
}
