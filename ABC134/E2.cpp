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
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    priority_queue<int> pq;
    rep(i,n)pq.push(a[i]);
    int i = 0;
    int count = 0;
    int tmp = pq.top();
    while(pq.size()){
        bool same = false;
        bool ok = false;
        while(!same && tmp >= a[i]){
            if(tmp == a[i])same = true;
            pq.pop();
            tmp = pq.top();
            ok = true;
        }
        if(ok)count++;
        i++;
    }
    cout << count << endl;
    return 0;

}