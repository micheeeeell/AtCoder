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
#define debug(x) cerr << #x << ": " << x << "\n";
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;
// typedef vector<ll> p;



// エラストテネスの篩
const int N = 1e7+1;
bool is_prime[N];
void build_sieve(){
    fill(is_prime, is_prime + N, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < N; ++i)if(is_prime[i]){
        for(int j = 2*i; j < N; j+=i)is_prime[j] = false;
    }
}


int main(){
    ll q; cin >> q;
    ll n = 1e5+10;
    vector<vl> lr(q,vl(2,0));
    rep(i,q){
        cin >> lr[i][0] >> lr[i][1];
    }
    build_sieve();
    vector<ll> sum(n+1,0);
    rep(i,n){
        if(i%2 == 0)sum[i+1] = sum[i];
        else{
            if(is_prime[i] && is_prime[(i+1)/2]){
                sum[i+1] = sum[i] + 1;
            }
            else sum[i+1] = sum[i];
        }
    }

    // rep(i,20){
    //     print(i,sum[i]);
    // }
    debug(sum[10]);
    rep(i,q){
        cout << sum[lr[i][1]+1] - sum[lr[i][0]] << endl;
    }

}