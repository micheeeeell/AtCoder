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
    priority_queue<int> pq_6, pq_9;
    // pq_6.push(1);
    ll money = 1;
    while(money <= n){
        pq_6.push(money);
        money *= 6;
    }
    money = 1;
    while(money <= n){
        pq_9.push(money);
        money *= 9;
    }

    // ll ans = 0;
    vector<ll> moneys_6, moneys_9;
    while(pq_6.size()){
        ll temp = pq_6.top();pq_6.pop();
        moneys_6.push_back(temp);
    }
    while(pq_9.size()){
        ll temp = pq_9.top();pq_9.pop();
        moneys_9.push_back(temp);
    }

    auto coins = [&](int x, int y){
        ll ans = 0;
        ll n_tmp = x;
        vector<ll> cc = (y == 6 ? moneys_6 : moneys_9);
        for(int i = 0; i < cc.size();i++){
            ll temp = cc[i];
            ll cnt = n_tmp/temp;
            n_tmp -= temp * cnt;
            ans += cnt;
            // cout << temp << ' ' << cnt << ' ' << n << ' ' <<  ans << ' ' << endl;
        }
        // cout << ans << endl;
        return ans;
    };

    ll res = INT_MAX;
    rep(i,n+1){
        ll temp = coins(i,6) + coins(n-i,9);
        res = min(res, temp);
    }
    cout << res << endl;
    return 0;
}