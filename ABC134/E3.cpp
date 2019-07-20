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
    rep(i,n)cin >> a[i];
    multiset<int> st;
    rep(i,n){
        bool ok = false;
        if(!i){
            st.insert(a[i]);
            continue;
        }
        auto st_min = st.begin();
        auto temp = st.lower_bound(a[i]);
        auto st_max = st.end();st_max--;
        if(st_min != temp)temp--;
        else{
            st.insert(a[i]);
            continue;
        }
        st.erase(temp);
        st.insert(a[i]);
    }
    cout << st.size() << endl;
    return 0;
}