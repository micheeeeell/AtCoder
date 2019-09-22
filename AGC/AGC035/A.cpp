#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> ivec;
const ll N = 1e9+7;

int main(){
    int n;cin >> n;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    set<ll> st;
    rep(i,n){
        st.insert(a[i]);
    }
    int st_size = st.size();
    bool ok = false;
    if(st_size == 1){
        auto itr = st.begin();
        if(!*itr)ok = true;
    }
    else if(st_size == 2){
        if(n % 3 == 0){
            auto itr = st.begin();
            int count = 0;
            if(!*itr){
                rep(i,n){
                    if(a[i] == 0)count++;
                }
            }
            if(count == n/3)ok = true;
        }
    }
    else if(st_size == 3){
        if(n % 3 == 0){
            auto itr = st.begin();
            ll x,y,z;
            x = *itr;itr++;
            y = *itr;itr++;
            z = *itr;
            cout << x << " " << y << " " << z << endl;
            cout << (x^y^z) << endl;
            int count[3] = {};
            if((x^y^z) == 0){
                ok = true;
                rep(i,n){
                    if(a[i] == x)count[0]++;
                    else if(a[i] == y)count[1]++;
                    else count[2]++;
                }
                rep(i,3){
                    if(count[i] != n/3)ok = false;
                }
            }
        }
    }
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}