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
typedef vector<int> ivec;
const ll N = 1e9+7;

int main(){
    int n; cin >> n;
    multiset<int> mst;
    rep(i,n){
        int d; cin >> d;
        mst.insert(d);
    }
    int min_n = 0,max_n = 0;
    auto itr = mst.begin();
    rep(i,(n/2)-1)itr++;
    min_n = *itr + 1;
    itr++;
    max_n = *itr;
    cout << max_n - min_n + 1 << endl;
    return 0;
}