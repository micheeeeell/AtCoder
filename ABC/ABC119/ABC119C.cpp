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

int A,B,C;
int INF = INT_MAX;
ll dfs(int n,ll a, ll b, ll c, int count, vector<ll> &vec){
    if(count == n){
        if(0 < a && 0 < b && 0 < c)return abs(a-A) + abs(b-B) + abs(c-C) - 30;
        else return INF;
    }
    ll res0 = dfs(n,a,b,c,count+1,vec);
    ll res1 = dfs(n,a+vec[count],b,c,count+1,vec) + 10;
    ll res2 = dfs(n,a,b+vec[count],c,count+1,vec) + 10;
    ll res3 = dfs(n,a,b,c+vec[count],count+1,vec) + 10;
    return min(min(res0,res1),min(res2,res3));
}

int main(){
    int n; cin >> n;
    cin >> A >> B >> C;
    vector<ll> l(n);
    rep(i,n) cin >> l[i];

    ll ans = dfs(n,0,0,0,0,l);
    cout << ans << endl;
    return 0;
}