#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#define rep(i,x) for(int i = 0; i < x; i++)
typedef long long ll;
using namespace std;
const ll N = 1e9+7;

ll dev(ll x, ll y){
    ll ans = 0;
    ans = x / y;
    return ans;
}

ll gcd(ll m, ll n)
{
	ll temp;
	while (m % n != 0)
	{
		temp = n;
		n = m % n;
		m = temp;
	}
	return n;
}
int main(){
    ll a,b,c,d; cin >> a >> b >> c >> d;
    ll cd = gcd(c,d);
    ll cd2 = c*d/cd; 
    ll ans1 = dev(b,c) + dev(b,d) - dev(b,cd2);
    ll ans2 = dev(a-1,c) + dev(a-1,d) - dev(a-1,cd2);
    ll ans = (b - a + 1) - (ans1 - ans2);
    cout << ans << endl;
    return 0;
}