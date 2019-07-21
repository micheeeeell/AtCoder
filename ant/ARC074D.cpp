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
    int n;cin >> n;
    priority_queue<ll> pq_min;
    priority_queue<ll,vector<ll>,greater<ll> > pq_max;
    ll a[n*3];
    ll sum_max = 0,sum_min = 0;
    rep(i,3*n){
        // ll a;cin >> a;
        cin >> a[i];
        if(i < n){
            pq_max.push(a[i]);
            sum_max += a[i];
        }
        
        if(i >= 2 * n){
            pq_min.push(a[i]);
            sum_min += a[i];
        }
    }
    assert(pq_max.size() == n);assert(pq_min.size() == n);
    // ll ans = sum_max - sum_min;
    Pll psmax[n+1],psmin[n+1];
    psmax[0] = Pll(sum_max,n-1);
    psmin[n] = Pll(sum_min,2*n-1);
    rep(i,n+1){
        ll k = i + n -1;
        if(!i)continue;
        sum_max += a[k];
        pq_max.push(a[k]);
        ll temp_min = pq_max.top();pq_max.pop();
        sum_max -= temp_min;
        psmax[i] = Pll(sum_max,k);
    }
    for(int i = n; i >= 0;i--){
        ll k = i + n;
        if(i ==n)continue;
        sum_min += a[k];
        pq_min.push(a[k]);
        ll temp_max = pq_min.top();pq_min.pop();
        sum_min -= temp_max;
        psmin[i] = Pll(sum_min,k);
    }
    ll ans = LLONG_MIN;
    rep(i,n+1){
        ans = max(psmax[i].first - psmin[i].first, ans);
        // cout << i << " " << psmax[i].first << " " << psmin[i].first << endl;
    }

    cout << ans << endl;
    return 0;
}