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

int main(){
	ll n, k;cin >> n >> k;
	vector<Pll> dt(n);
	set<ll> tst;
	rep(i,n){
		ll t,d;cin >> t >> d;
		t--;
		dt.at(i) = Pll(d,t);
		tst.insert(t);
	}
	ll tmax = tst.size();
	sort(dt.begin(), dt.end(), greater<Pll>());
	//vector<vector<ll>> dp(n, vector<ll>(k,-1));
	priority_queue<Pll, vector<Pll>, greater<Pll>> pq;
	vector<ll> num(n,0), p(n+10,0);
	ll count = 0, type = 0;
	ll sum = 0;
	rep(i,k){
		sum += dt.at(i).first;
		pq.push(dt.at(i));
		if(!num.at(dt.at(i).second))type++;
		num.at(dt.at(i).second)++;
		count++;
	}
	p.at(type) = sum + type * type;
	while(type < min(k, tmax)){
		Pll temp = pq.top();pq.pop();
		if(num.at(temp.second) == 1)continue;
		sum -= temp.first;
		while(count < n){
			if(num.at(dt.at(count).second)) count++;
			else{
				sum += dt.at(count).first;
				pq.push(dt.at(count));
				num.at(dt.at(count).second)++;
				count++;
				break;
			}
		}
		type++;
		p.at(type) = sum + type * type;
	}
	
	cout << *max_element(p.begin(), p.end()) << endl;
	return 0;
}
