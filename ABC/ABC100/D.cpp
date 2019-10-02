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
    ll n,m; cin >> n >> m;
    vector<vector<ll>> vec(n, vector<ll>(3,0));
    rep(i,n)rep(j,3)cin >> vec[i][j];

    ll res = 0;
    rep(i,(1 << 3)){
        priority_queue<ll> pq;
        priority_queue<ll> empty;
        rep(j,n){
            ll temp = 0;
            rep(k,3){
                if((i >> k) & 1) temp += vec[j][k];
                else temp -= vec[j][k];
            }
            pq.push(temp);
        }
        ll cal = 0;
        rep(j,m){
            cal += pq.top();pq.pop();
        }
        swap(pq, empty);
        res = max(res, cal);
    }
    cout << res << endl;
    return 0;
}
