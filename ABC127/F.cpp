#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;

int main(){
    ll q; cin >> q;
    ll flag[q];
    vector<pair<ll, ll>> ab;
    vector<multiset<ll>> a,b;
    multiset<ll> aset,bset;
    rep(i,q){
        int temp, tempa, tempb;
        cin >> temp;
        flag[i] = temp - 1;
        if(!flag[i]){
            cin >> tempa >> tempb;
            ab.push_back(make_pair(tempa,tempb));
            aset.insert(tempa); bset.insert(tempb);
            a.push_back(aset);b.push_back(bset);
        }
    }

    // sort(ab.begin(), ab.end());
    // ll x = 0,cst = 0;
    // if(ab.size()%2){
    //     rep(i,ab.size()){
    //         if(i < ab.size()/2 + 1)x -= ab[i];
    //     }
        
    // }
}