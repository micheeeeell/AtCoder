#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef pair<ld, ld> Pld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    int n; cin >> n;
    vector<Pld> vec(n);
    rep(i,n){
        ld x,y;cin >> x >> y;
        vec[i] = Pld(x,y);
    }
    sort(all(vec));
    ld sum = 0;
    do{
        ld temp = 0;
        rep(i,n-1){
            ld x = vec[i+1].first - vec[i].first;
            ld y = vec[i+1].second - vec[i].second;
            temp += sqrt(x * x + y * y);
        }
        sum += temp;
    }while(next_permutation(all(vec)));

    ld ma = 1;
    for(int i = 1; i < n+1;++i)ma *= i;
    cout << fixed << setprecision(10) << sum / ma << endl;

}