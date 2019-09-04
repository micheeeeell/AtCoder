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
    ll n,k; cin >> n >> k;
    ll max_a = 1e12 + 10;
    int max_pow = 0;
    ll temp = 1;
    while(temp < max_a){
        temp <<= 1;
        max_pow++;
    }
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    // cout << temp << " " << max_pow << endl;
    ll dp_0[max_pow] = {}, dp_1[max_pow] = {};
    temp = 1;
    int k_max = 0;
    while(temp <= k){
        temp <<= 1;k_max++;
    }
    rep(i,n){
        rep(j,k_max){
            ll atemp = a[i] >> j;
            if(1 & atemp)dp_1[j]++;
            else dp_0[j]++;
        }
    }
    // cout << k_max;
    vector<ll> theory_ans(k_max,0);
    rep(i,k_max){
        if(dp_0[i] <= dp_1[i])theory_ans[i] = 0;
        else theory_ans[i] = 1;
    }
    ll ans= 0;
    rep(i,k_max)ans += theory_ans[i] * pow(2, i);
    // cout << ans << endl;
    ll res;
    auto change = [&](vector<ll> vec){
        ll ret = 0;
        rep(i,k_max)ret += vec[i] * pow(2, i);
        return ret;
    };
    auto f = [&](ll x){
        ll ret = 0;
        rep(i,n){
            ret += (x ^ a[i]);
        }
        return ret;
    };

    if(ans <= k){
        res = ans;
        cout << f(res) << endl;
        return 0;
    }
    int k_bit[k_max];
    rep(i,k_max){
        if((k >> i) & 1)k_bit[i] = 1;
        else k_bit[i] = 0;
    }

    ll ret = 0;
    for(int i = k_max-1; 0 <= i;i--){
        vector<ll> temp = theory_ans;
        if(!k_bit[i])continue;
        for(int j = k_max-1;i < j;j--)temp[j] = k_bit[j];
        temp[i] = 0;
        res = change(temp);
        // cout << res << endl;
        assert(res <= k);
        ret = max(ret, f(res));
    }

    ret = max(ret,f(k));

    cout << ret << endl;
    return 0;

    //以下は嘘解法
    // for(int i = k_max-1;0 <= i;i--){
    //     ll ktemp = k >> i;
    //     ll atemp = ans >> i;
    //     if(ktemp & 1){
    //         if(atemp & 1)continue;
    //         else break;
    //     }
    //     else{
    //         if(atemp & 1)ans -= pow(2, i);
    //         else continue;
    //     }
    // }

    // assert(ans <= k);

    // cout << f(ans) << endl;
    
}