#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
#define int ll
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
 
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}
 
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
 
using pi=pair<int,int>;
using vi=vc<int>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
 
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n;cin>>n;
	vc<pi> lr;
	const int inf=LLONG_MAX/3;
	int mx=-inf,mn=inf;
	rep(i,n){
		int l,r;cin>>l>>r;
		l--;
		chmax(mx,l);
		chmin(mn,r);
		lr.eb(l,r);
	}
	
	int ans=0;
	for(auto z:lr){
		chmax(ans,max(int(0),mn-mx)+z.b-z.a);
	}
	vc<pi> t;
	rep(i,n){
		int a=max(int(0),mn-lr[i].a);
		int b=max(int(0),lr[i].b-mx);
		t.eb(b,-a);
	}
	sort(all(t));
	int w=inf;
	rep(i,n){
		auto z=t[i];
		z.b=-z.b;
		if(i)
			chmax(ans,w+z.a);
		chmin(w,z.b);
	}
	cout<<ans<<endl;
}