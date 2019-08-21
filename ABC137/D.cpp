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
const ll N = 1e9+7;
const int n_max = 1e5+10;

int main(){
    int n,m; cin >> n >> m;
    vector<P> ab;
    priority_queue<int> pq;
    rep(i,n){
        int a,b; cin >> a >> b;
        ab.pb(P(a,b));
    }
    sort(ab.begin(),ab.end());
    // for(auto i : ab)cout << i.first << " " << i.second << endl;
    // rep(i,ab.size()) cout << ab[i].first << endl;
    int left = 0;
    ll ans = 0;
    for(int i = 0;i < m;i++){
        while(left < ab.size()){
            // cout << i  << ' ' << left << endl;
            if(ab[left].first == (i+1)){
                pq.push(ab[left].second);
                left++;
            }
            else break;
        }
        if(pq.size()){
            int temp = pq.top();pq.pop();
            ans += temp;
        }
    }
    cout << ans << endl;
    return 0;
}