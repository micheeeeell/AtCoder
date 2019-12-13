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
const ll N = 1e9+7;
const int n_max = 1e5+10;

const vi num = {2,5,5,4,5,6,3,7,6};

int main(){
	int n,m;cin >> n >> m;
	vi a(m);
	rep(i,m){
		cin >> a.at(i);
		a.at(i)--;
	}
	vi dp(n+1,-INT_MAX);
	dp.at(0) = 0;
	rep(i,n+1){
		rep(j,m){
			if(i < num.at(a.at(j)))continue;
			dp.at(i) = max(dp.at(i), dp.at(i-num.at(a.at(j))) + 1);
		}
	}
	//rep(i,dp.size())cout << dp.at(i) << " ";
	//cout << endl;

	vi ans;
	sort(a.begin(),a.end(),greater<int>());
	int count = n;
	while(0 < count){
		rep(j,m){
			if(count < num.at(a.at(j)))continue;
			if(dp.at(count) == 1){
				if(count != num.at(a.at(j)))continue;
			}
			if(dp.at(count) == dp.at(count - num.at(a.at(j)))+1){
				ans.pb(a.at(j)+1);
				//cout << count << " " << a.at(j) + 1 << endl;
				count -= num.at(a.at(j));
				break;
			}
		}
	}
	
	
	rep(i,ans.size())cout << ans.at(i);
	cout << endl;
	return 0;	
}
