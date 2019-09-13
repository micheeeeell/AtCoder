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
    vector<Pll> happy(n);
    priority_queue<Pll> pq;
    rep(i,n){
        ll a,b; cin >> a >> b;
        happy[i] = Pll(a,b);
        pq.push(Pll(a+b, i));
    }

    ll taka = 0, aoki = 0;
    ll count = 0;
    while(pq.size()){
        Pll p = pq.top();pq.pop();
        if(count%2 == 0)taka += happy[p.second].first;
        else aoki += happy[p.second].second;
        count++;
    }

    cout << taka - aoki << endl;
    return 0;
}