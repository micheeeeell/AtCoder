#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef pair<int,int> P;

int main(){
    vector<ll> a[20],a_mid[20];
    int n; cin >> n;
    rep(i,n){
        ll al;cin >> al;
        a[0].pb(al);
    }
    rep(i,n-2){
        rep(j,a[i].size()-2){
            a_mid[i].pb(a[i][j+1]);
        }
        auto temp = min_element(a_mid[i].begin(),a_mid[i].end());
        auto beg = a_mid[i].begin();
        auto ed = a_mid[i].end();
        ed--;
        if(a[i].size() == 3){
            a[i+1].pb(a[i][0] + a[i][1]);
            a[i+1].pb(a[i][1] + a[i][2]);
            break;
        }

        if(a_mid[i].begin() == temp){
            a[i+1].pb(a[i][0] + a_mid[i][0]);
            a[i+1].pb(a_mid[i][0] + a_mid[i][1]);
            for(int k = 3;k < a[i].size();k++){
                a[i+1].pb(a[i][k]);
            }
        }
        else if(ed == temp){
            rep(k,a[i].size()-3){
                a[i+1].pb(a[i][k]);
            }
            int size = a[i].size();
            a[i+1].pb(a[i][size-3] + a[i][size-2]);
            a[i+1].pb(a[i][size-2] + a[i][size-1]);
        }
        else{
            temp--;
            a[i+1].pb(a[i][0]);
            int size = a[i].size();
            for(auto check = a_mid[i].begin();check != a_mid[i].end();){
                if(check != temp){
                    a[i+1].pb(*check);
                    check++;
                }
                else{
                    int tmin1 = *check;check++;
                    int tmin2 = *check;check++;
                    int tmin3 = *check;check++;
                    a[i+1].pb(tmin1 + tmin2);
                    a[i+1].pb(tmin2 + tmin3);
                }
            }
            a[i+1].pb(a[i][size-1]);

        }

    }
    cout << endl;
    rep(i,n-1){
        for(auto j : a[i]) cout << j << " ";
        cout << endl;
    }
    cout << endl;
    rep(i,n-1){
        for(auto j : a_mid[i]) cout << j << " ";
        cout << endl;
    }
    assert(a[n-2].size() == 2);
    cout << a[n-2][0] + a[n-2][1] << endl;
    return 0;

}