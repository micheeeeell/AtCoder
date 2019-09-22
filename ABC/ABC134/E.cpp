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
    int n; cin >> n;
    vector<int> a(n);
    int count = 0;
    int temp_count = 0;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,n){
        if(!i)continue;
        if(a[i] <= a[i-1]) {
            // count++;
            temp_count++;
            // cout << "test" << endl;
        }
        else{
            count = max(count, temp_count);
            temp_count = 0;
        }
    }
    count = max(count, temp_count);
    cout << count + 1 << endl;
    return 0;
}