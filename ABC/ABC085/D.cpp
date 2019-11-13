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
    ll n,h; cin >> n >> h;
    vector<Pll> ab(n);
    priority_queue<Pll> pq,clear;
    rep(i,n){
        ll a,b; cin >> a >> b;
        ab[i] = Pll(a,b);
        pq.push(Pll(b,a));
    }
    ll temp = 0,res = 0;
    bool ok = true;
    while(pq.size() && temp < h){
        Pll t = pq.top();pq.pop();
        temp += t.first;
        res++;
    }
    if(temp < h)ok = false;
    sort(ab.begin(), ab.end(),
    [](auto const a, auto const b){
        return (a.first < b.first) || (a.first == b.first && a.second > b.second);
    });
    Pll katana = ab.back();ab.pop_back();
    pq=clear;
    rep(i,n-1){  
        pq.push(Pll(ab[i].second, ab[i].first));
    }
    bool b = true;
    temp = 0;
    ll cnt = 0;
    while(pq.size() && temp < h && b){
        Pll t = pq.top();pq.pop();
        if(t.first < katana.first){
            b = false;
            continue;
        }
        temp += t.first;
        cnt++;
    }
    if(temp < h){
        ll r = h-temp;
        if(r < katana.second)cnt++;
        else{
            r -= katana.second;
            cnt += (r-1) / katana.first + 1;
            cnt++;
        }
    }

    cout << (ok ? min(res, cnt) : cnt) << endl;

}