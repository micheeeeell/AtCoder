#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(ll i = 0; i < x; i++)
typedef long long ll;
const ll N = 1e9 + 7;
using namespace std;


int main(){
    int n,x;cin >> n >> x;
    vector<pair<int,pair<int,int>>> ubn(n),lbn(n);
    ll B = 0;
    rep(i,n){
        int b,l,u;cin >> b >> l >> u;
        ubn[i] = {u,{b,i}};
        lbn[i] = {l,{b,i}};
        B += l*b;
    }
    ll score[n] = {};
    sort(ubn.begin(),ubn.end());
    sort(lbn.begin(),lbn.end());
    ll A = 0;
    int count = n-1;
    ll ans = 0;
    while(A<B){
        A += ubn[count].first * x;
        B += (ubn[count].first - lbn[count].first) * ubn[count].second.first;
        score[ubn[count].second.second] = x;
        ans += x;
        count--;
    }
    if(A==B) {
        cout << ans << endl;
        return 0;
    }
    else{
        count++;
        B -= (ubn[count].first - lbn[count].first) * ubn[count].second.first;
        A -= ubn[count].first * x;
        score[ubn[count].second.second] = 0;
        ans -= x;
    }
    int remain = B-A;
    ll ubans = 0;
    int temp_remain = remain + (ubn[count].first - lbn[count].first) * ubn[count].second.first;
    // ubans = max((remain / ubn[count].first)+1, ubn[count].second.first);
    if(temp_remain % ubn[count].first) ubans = max((remain / ubn[count].first)+1, ubn[count].second.first);
    else ubans = max((remain / ubn[count].first), ubn[count].second.first);
    // score[ubn[count].second.second] = ubans;
    ll lbans = 0;
    int i = n-1;
    while(!lbans){
        if(score[lbn[i].second.second]){
            i--;
            continue;
        }
        if(remain % lbn[i].first)lbans = (remain / lbn[i].first)+1;
        else lbans = remain / lbn[i].first;
    }
    // score[lbn[i].second.second] = lbans;
    ans += min(ubans,lbans);
    cout << "ubans " << ubans << " lbans " << lbans << endl;
    rep(j,n)cout << j << " " << score[i] << endl;
    cout << ans << endl;
    return 0;


}