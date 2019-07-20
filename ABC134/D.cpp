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
const int n_max = 1e5 * 2+10;

int arr[n_max];

// void hurui(){
//     rep(i,n_max){
//         arr[i] = 1;
//     }
//     for(int i = 2; i < sqrt(n_max);i++){
//         if(arr[i]){
//             for(int j = 0; i * (j + 2) N;j++){
//                 arr[i*(j+2) = 0;]
//             }
//         }
//     }
// }

int main(){
    int n; cin >> n;
    vector<int>a(n);
    vector<int>b(n,0);
    rep(i,n)cin >> a[i];
    // int count = 0;
    vector<int> ans;
    if(n == 1){
        cout << a[0] << endl;
        if(a[0]) cout << a[0] << endl;
        return 0;
    }
    for(int i = n-1;(n/2) <= i; i--){
        b[i] = a[i];
        if(b[i]){
            ans.pb(i+1);
            // cout << i << endl;
        }
    }
    for(int i = n/2 -1;0 <= i;i--){
        int temp = n / (i+1);
        rep(j,temp-1){
            b[i] += b[i + ((j + 1) * (i+1))];
        }
        b[i] = (b[i]%2) ^ a[i];
        if(b[i])ans.pb(i+1);
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i << " ";
    if(ans.size())cout <<endl;
    return 0;
    

}