#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> ivec;
const ll N = 1e9+7;

int main(){
    vector<int> a = {1,2,3,4,5,6};
    // priority_queue<int> pque;
    // rep(i,10)pque.push(i);

    // rep(i,10){
    //     int t = pque.top();
    //     cout << t << endl;
    //     pque.pop();
    // }

    multimap<int,int> b{
        {3,1},
        {2,2},
        {1,4},
        {1,3}
    };
    auto itr = b.begin();

    rep(i,b.size()){
        P p = *itr;
        cout << p.first << " " << p.second << endl;
        // itr = next(itr,1);
        itr++;
    }
    
    // for(auto i:a)cout << (i ^ 6) << endl;
    auto ed = a.end();
    ed--;
    // cout << *ed << endl;
    return 0;
}
