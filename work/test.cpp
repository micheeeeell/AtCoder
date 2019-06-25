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
    ll n = 10;
    int i[n][n] = {};
    int i0[n][n] = {0};
    // vector<P> p[n] = {0};
    vector<ivec> vec(n,ivec(n,0));
    int i1[n][n] = {-1};
    cout << "i" << endl;
    rep(k,n){
        rep(j,n){
            cout << i[k][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "i0" << endl;
    rep(k,n){
        rep(j,n){
            cout << i0[k][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "i1" << endl;
    rep(k,n){
        rep(j,n){
            cout << i1[k][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "vec" << endl;
    rep(k,n){
        rep(j,n){
            cout << vec[k][j] << " ";
        }
        cout << endl;
    }
    int a[n] = {0};
    cout 
    rep(i,n)
    return 0;
}