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
    int n,m; cin >> n >> m;
    // cout << n << m;
    vector<int> c(n);
    rep(i,n) cin >> c[i];
    // rep(i,n) cout << c[i] << " "; cout << endl;
    set<int> st;
    vector<int> temp;
    vector<int> clear;
    rep(i,1 << n){
        int count = 0;
        rep(j,n){
            if(1 & (i >> j)){
                count++;
                temp.pb(c[j]);
            }
        }
        // cout << "i" << i << ' ' << count << endl;
        if(count != m){
            temp = clear;
            continue;
        }
        sort(temp.begin(),temp.end());
        do{
            int cur = 0;
            rep(k,m){
                if((temp[k] / 10) > 0) cur *= 100;
                else cur *= 10;
                cur += temp[k];
            }
            st.insert(cur);
            // rep(k,temp.size())cout << temp[k] << " ";cout << endl;
        }while(next_permutation(temp.begin(),temp.end()));
        // rep(k,temp.size())cout << temp[k] << " ";cout << endl;

        temp = clear;
    }
    int ans = st.size();
    cout << ans << endl;
    return 0;
}