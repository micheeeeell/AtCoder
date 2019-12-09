#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(ll i=0;i<x;i++)
using namespace std;

int main(){
    ll n;cin >> n;
    vector<ll> ap,am,a;
    rep(i,n){
        ll temp;cin >> temp;
        if(temp < 0){
            am.push_back(temp);
        }
        // else if(temp == 0){
        //     az.push_back(temp);
        // }
        else{
            ap.push_back(temp);
        }
        a.push_back(temp);
    }
    vector<ll> x(n-1),y(n-1);
    sort(ap.begin(),ap.end());
    sort(am.begin(),am.end(),greater<ll>());
    if(n > 2){
        if(am.size() == 0){
            x[0] = ap[0];
            y[0] = ap[1];
            // ap.erase(ap[0]);
            // ap.erase(ap[1]);
            ap.erase(ap.begin());
            ap.erase(ap.begin());
            am.push_back(x[0] - y[0]);
        }
        else if(ap.size() == 0){
            x[0] = am[0];
            y[0] = am[1];
            am.erase(am.begin());
            am.erase(am.begin());
            ap.push_back(x[0] - y[0]);
        }
        else if(ap.size() > 1){
            x[0] = am.back();
            y[0] = ap.back();
            ap.pop_back();
            am.pop_back();
            am.push_back(x[0] - y[0]);
        }
        else{
            x[0] = ap.back();
            y[0] = am.back();
            ap.pop_back();
            am.pop_back();
            ap.push_back(x[0] - y[0]);
        }
        ll i = 1;
        while(ap.size() > 1){
            x[i] = am.back();
            y[i] = ap.back();
            ap.pop_back();
            am.pop_back();
            am.push_back(x[i] - y[i]);
            i++;
            // cout << i << "m";
        }
        while(am.size() > 1){
            x[i] = ap.back();
            y[i] = am.back();
            ap.pop_back();
            am.pop_back();
            ap.push_back(x[i] - y[i]);
            i++;
            // cout << i <<"p";
        }
        // cout << i << endl;
        x[i] = ap[0];
        y[i] = am[0];
        ll ans = x[i]-y[i];
        i++;
        cout << ans << endl;
        rep(j,n-1) cout << x[j] << " " << y[j] << "\n";
        return 0;
    }
    else{
        x[0] = max(a[0],a[1]);
        y[0] = min(a[0],a[1]);
        ll ans = x[0] - y[0];
        cout << ans << endl;
        rep(j,n-1) cout << x[j] << " " << y[j] << "\n";
        return 0;
    }

    return 0;
}