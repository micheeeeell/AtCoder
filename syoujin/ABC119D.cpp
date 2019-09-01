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
    ll a,b,q;cin >> a >> b >> q;
    vector<ll> s(a);//神社
    rep(i,a) cin >> s[i];
    vector<ll> t(b);//寺
    rep(i,b) cin >> t[i];
    vector<ll> x(q);
    rep(i,q) cin >> x[i];
    vector<ll> near_temple(a);
    rep(i,a){
        auto itr = upper_bound(t.begin(), t.end(),s[i]);
        if(itr == t.begin())near_temple[i] = abs(*itr - s[i]);
        else if(itr == t.end()){
            itr--;near_temple[i] = abs(*itr - s[i]);
        }
        else{
            ll temp = *itr;itr--;
            ll temp2 = *itr;
            assert(temp2 <= s[i] && s[i] <= temp);
            near_temple[i] = min(abs(s[i] - temp2), abs(s[i] - temp));
        }
    }
    vector<ll> near_shrine(b);
    rep(i,b){
        auto itr = upper_bound(s.begin(), s.end(),t[i]);
        if(itr == s.begin())near_shrine[i] = abs(*itr - t[i]);
        else if(itr == s.end()){
            itr--;near_shrine[i] = abs(*itr - t[i]);
        }
        else{
            ll temp = *itr;itr--;
            ll temp2 = *itr;
            assert(temp2 <= t[i] && t[i] <= temp);
            near_shrine[i] = min(abs(t[i] - temp2), abs(t[i] - temp));
        }
    }

    rep(i,q){
        auto itr_sh = upper_bound(s.begin(), s.end(), x[i]);
        auto itr_te = upper_bound(t.begin(), t.end(), x[i]); 
        ll temp_s1, temp_s2, temp_t1, temp_t2;
        ll sh1,sh2,te1,te2;
        if(itr_sh == s.begin()){
            sh1 = itr_sh - s.begin();
            temp_s1 = abs(s[sh1] - x[i]) + near_temple[sh1];
            temp_s2 = LONG_MAX;
        }
        else if(itr_sh == s.end()){
            sh1 = itr_sh - s.begin() - 1;
            temp_s1 = abs(s[sh1] - x[i]) + near_temple[sh1];
            temp_s2 = LONG_MAX;
        }
        else{
            sh1 = itr_sh - s.begin();
            sh2 = sh1 - 1;
            temp_s1 = abs(s[sh1] - x[i]) + near_temple[sh1];
            temp_s2 = abs(s[sh2] - x[i]) + near_temple[sh2];
        }

        if(itr_te == t.begin()){
            te1 = itr_te - t.begin();
            temp_t1 = abs(t[te1] - x[i]) + near_shrine[te1];
            temp_t2 = LONG_MAX;
        }
        else if(itr_te == t.end()){
            te1 = itr_te - t.begin() - 1;
            temp_t1 = abs(t[te1] - x[i]) + near_shrine[te1];
            temp_t2 = LONG_MAX;
        }
        else{
            te1 = itr_te - t.begin();
            te2 = te1 - 1;
            temp_t1 = abs(t[te1] - x[i]) + near_shrine[te1];
            temp_t2 = abs(t[te2] - x[i]) + near_shrine[te2];
        }

        ll ans = min(min(temp_s1, temp_s2), min(temp_t1, temp_t2));
        cout << ans << "\n";
    }
    return 0;
}