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

// int main(){
//     int n,k;cin >> n >> k;
//     multimap<ll,ll> mp;
//     // multiset<ll> st;
//     rep(i,n){
//         ll a,b;cin >> a >> b;
//         mp.insert(Pll(a,b));
//     }
//     ll ans = 0;
//     rep(i,k){
//         auto it = mp.begin();
//         ans += (*it).first;
//         ll ta = (*it).first + (*it).second;
//         ll tb = (*it).second;
//         mp.insert(Pll(ta,tb));
//         mp.erase(it);
//         // cout << ta << endl;
//     }
//     cout << ans << endl;
//     return 0;
// }
int main(){
    int n,k;cin >> n >> k;
    priority_queue<Pll, vector<Pll>, greater<Pll> > pq;
    ll a[n_max],b[n_max];
    rep(i,n){
        cin >> a[i] >> b[i];
        pq.push(Pll(a[i],i));
    }
    ll ans = 0;
    rep(i,k){
        Pll p = pq.top();pq.pop();
        ans += p.first;
        pq.push(Pll(p.first + b[p.second],p.second));
    }
    cout << ans << endl;
    return 0;
}