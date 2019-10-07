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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];

    ll res = 0;
    ll sum = 0;
    ll xor_sum = 0;
    int right = 0;

    rep(left, n){
        while(right < n && (sum + a[right]) == (xor_sum ^ a[right])){
            sum += a[right]; xor_sum ^= a[right];
            ++right;
        }

        int num = right - left;
        // res += (num + 1) * num / 2;
        res += num;

        if(right == left) ++right;
        else{
            sum -= a[left];
            xor_sum ^= a[left];
        }
    }
    cout << res << endl;
    return 0;
}