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
    vector<ll> a(n);
    priority_queue<ld> pq;
    rep(i,n){
        cin >> a[i];
        pq.push(ld(a[i]));
    } 
    
    ll count = 0;
    while(count < m){
        ld temp = pq.top();pq.pop();
        temp /= 2.0;
        pq.push(temp);
        count++;
    }
    ll res = 0;
    while(pq.size()){
        ll ans = floor(pq.top());pq.pop();
        res += ans;
    }
    cout << res << endl;
    return 0;
}