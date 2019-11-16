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
    int n; cin >> n;
    vector<P> blue(n), red(n);
    rep(i,n){
    int a,b; cin >> a >> b;
    red[i] = P(a,b);
    }
    rep(i,n){
        int c,d; cin >> c >> d;
        blue[i] = P(c,d);
    }
    sort(blue.begin(), blue.end());
    sort(red.begin(), red.end(),
    [](auto const &a, auto const &b) -> bool{
        return a.second > b.second;
    });
    int res = 0;
    vector<bool> red_use(n, true);
    rep(i,n){
        rep(j,n){
            if(blue[i].first > red[j].first && blue[i].second > red[j].second && red_use[j]){
                res++;
                red_use[j] = false;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}