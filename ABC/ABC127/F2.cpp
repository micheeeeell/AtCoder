#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = numeric_limits<ll>::max()/4;
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

int main(){
    ll q; cin >> q;
    ll ans = 0;
    // multiset<ll> left, right;
    priority_queue<ll> left;
    priority_queue<ll, vector<ll>, greater<ll>> right;
    rep(i,q){
        ll t; cin >> t;
        if(t == 1){
            ll a,b; cin >> a >> b;
            ans += b;
            ll l, r;
            if(left.size() == 0 && right.size() == 0){
                left.push(a);
                right.push(a);
            }
            else{
                l = left.top();left.pop();
                r = right.top();right.pop();
                if(a <= l){
                    left.push(a);
                    left.push(a);
                    right.push(l);
                    right.push(r);
                    ans += l-a;
                }
                else if(r <= a){
                    right.push(a);
                    right.push(a);
                    left.push(r);
                    left.push(l);
                    ans += a-r;
                }
                else{
                    left.push(a);
                    left.push(l);
                    right.push(a);
                    right.push(r);
                }
            }
            
        }
        else{
            cout << left.top() << " " << ans << "\n";
        }
    }
}