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
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll N = 1e9+7;
const int n_max = 1e5+10;

int main(){
    int n; cin >> n;
    priority_queue<int> pq;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        pq.push(a[i]);
    }
    int temp1 = pq.top();pq.pop();
    auto temp2 = pq.top();
    rep(i,n){
        if(a[i] == temp1) cout << temp2 << endl;
        else cout << temp1 << endl;
    }
    return 0;
}