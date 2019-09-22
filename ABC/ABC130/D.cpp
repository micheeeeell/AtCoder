#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
typedef long long ll;
using namespace std;

int main(){
    ll n,k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll sum = 0;
    ll count = 0;
    ll left = 0,right = 0;
    rep(i,n){
        left = i;
        // count = 0;
        if(i > 0) sum -= a[left-1];
        while(sum < k){
            if(right >= n)break;
            sum += a[right];
            right++;
        }
        if(sum < k)break;
        count += n - right+1;

        if (right == left) right++;

        cout << sum << " " << left << " " << right << " " << count << endl;
    }
    cout << count << endl;
}