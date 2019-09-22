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
    priority_queue<ld, vector<ld>, greater<ld> > pq;
    rep(i,n){
        ld temp;cin >> temp;
        pq.push(temp);
    }
    while(2 <= pq.size()){
        ld a = pq.top();pq.pop();
        ld b = pq.top();pq.pop();
        pq.push((a + b)/2.0);
    }

    ld ans  = pq.top();
    cout << ans << endl;
    // cout << pq.size() << endl;
    return 0;
}