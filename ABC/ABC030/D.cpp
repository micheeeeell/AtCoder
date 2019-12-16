#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = LLONG_MAX/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ll n,a; cin >> n >> a;
    a--;
    string k;cin >> k;
    vector<ll> b(n);
    rep(i,n) {
        cin >> b[i];
        b[i]--;
    }
    vector<ll> step(n);
    ll loop = 0;
    step[a] = 1;
    ll pos = a;
    while(step[b[pos]] == 0){
        step[b[pos]] = step[pos]+1;
        pos = b[pos];
    }
    loop = step[pos] - step[b[pos]] + 1;
    ll fir = step[b[pos]] - 1;
    debug(loop);
    vector<ll> step_rev(n);
    rep(i,n){
        if(step[i])step_rev[step[i]-1] = i;
    }

    vector<ll> mod_tens(n_max,0);
    mod_tens[0] = 1;
    rep(i,n_max-1){
        mod_tens[i+1] = mod_tens[i] * 10 % loop;
    }
    reverse(all(k));
    ll num = 0;
    ll c = 0;
    while(num < fir && c < k.size()){
        int t = k[c] - '0';
        if(!t)t = 10;
        if(c != 0 && k[c-1] == '0')num -= 10*pow(10,c-1);
        num += t * pow(10,c);
        c++;
    }
    debug(c);
    ll ret;
    if(num < fir)ret = step_rev[num]+1;
    else{
        // num -= fir;
        // num %= loop;
        // while(c < k.size()){
        //     num += (k[c] - '0') * mod_tens[c];
        //     num %= loop;
        //     c++;
        // }
        ll m = 0;
        ll cnt = 0;
        while(cnt < k.size()){
            m += (k[cnt] - '0') * mod_tens[cnt];
            m %= loop;
            cnt++;
        }
        // fir %= loop;
        m -= fir%loop;
        if(m < 0)m += loop;
        debug(m);
        ret = step_rev[m+fir]+1;
    }

    cout << ret << endl;

}