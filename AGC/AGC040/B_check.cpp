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


void swap(ll &a, ll &b){
    ll tmp = a;
    a = b;
    b = tmp;
    return;
}

ll solve(vector<Pll> lr, ll n){
     auto comp = [](auto const a, auto const b){
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    };
    // sort(lr.begin(), lr.end(),comp);
    sort(lr.begin(), lr.end());

    vector<Pll> down(n), up(n);

    down[0] = lr[0];
    rep(i,n){
        if(!i)continue;
        ll l, r;
        l = max(lr[i].first, down[i-1].first);
        r = min(lr[i].second, down[i-1].second);
        down[i] = Pll(l,r);
    }

    up[n-1] = lr[n-1];
    for(int i = n-2; 0 <= i; --i){
        ll l,r;
        l = max(lr[i].first, up[i+1].first);
        r = min(lr[i].second, up[i+1].second);
        up[i] = Pll(l,r);
    }

    auto cal = [](ll a, ll b){
        if(a <= b)return b-a+1;
        else return ll(0);
    };
    ll ans = 0;
    rep(i,n-1){
        ll temp = 0;
        temp += cal(down[i].first, down[i].second);
        temp += cal(up[i+1].first, up[i+1].second);
        ans = max(ans, temp);
    }
    // 一つだけ別
    rep(i,n){
        if(i == 0 || i == n-1)continue;
        ll temp = 0;
        ll l,r;
        l = max(down[i-1].first, up[i+1].first);
        r = min(down[i-1].second, up[i+1].second);
        temp += cal(l,r);
        temp += cal(lr[i].first, lr[i].second);
        ans = max(ans, temp);
    }

    return ans;
   
    // cout << ans << endl;
}

void print(vector<Pll> x){
    int n = x.size();
    rep(i,n){
        cout << x[i].first << " " << x[i].second << "\n";
    }
    return;
}

ll guchoku(vector<Pll> lr, ll n){
    ll res = 0;
    rep(i,(1 << n)){
        ll temp = 0;
        vector<Pll> one, two;
        rep(j,n){
            if((i >> j) & 1)one.push_back(lr[j]);
            else two.push_back(lr[j]);
        }
        if(one.size() == 0 || two.size() == 0)continue;
        int os = one.size(), ts = two.size();
        ll l = one[0].first, r = one[0].second;
        rep(i,os){
            l = max(l, one[i].first);
            r = min(r, one[i].second);
        }
        // cout << "one" << endl;
        // print(one);
        // cout << "lr" << endl;
        // cout << l << " " << r << endl;
        // cout << max(0ll,r-l+1) << endl;
        temp += max(0ll,r-l+1);
        l = two[0].first, r = two[0].second;
        rep(i,ts){
            l = max(l, two[i].first);
            r = min(r, two[i].second);
        }
        // cout << "two" << endl;
        // print(two);
        // cout << "lr" << endl;
        // cout << l << " " << r << endl;
        // cout << max(0ll,r-l+1) << endl;
        temp += max(0ll,r-l+1);
        res = max(res, temp);
        // cout << res << endl;
    }
    return res;
}
int main(){
    random_device rnd;

    
    rep(i,1000){
        int n = rnd() % 9 + 2;
        // n = 3;
        vector<Pll> lr(n);
        rep(j,n){
            ll l = rnd() % 100 + 1;
            ll r = rnd() % 100 + 1;
            if(r < l)swap(l,r);
            lr[j] = Pll(l,r);
        }

        if(solve(lr, n) != guchoku(lr, n)){
            cout << "error!" << endl;
            cout << n << endl;
            print(lr);
            cout << solve(lr,n) << endl;
            cout << guchoku(lr,n) << endl;
        }

    }
}