#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<iostream>
#include<sstream>
#include<cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 20005, MA = 23, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

string s;
int f[25];
int dfs(int l, int r, int n) {
	if (n == 1) {
		if (s[l] == 'b') return 0;
		return -1;
	}
	if (n == 2) {
		if (s[l] == 'a') return 0;
		return -1;
	}
	{
		int x = dfs(l,l+f[n-1],n-1), y = dfs(r-f[n-2],r,n-2);
		if (x != -1 && y != -1) return x<<1;
	}
	{
		int y = dfs(l,l+f[n-2],n-2), x = dfs(r-f[n-1],r,n-1);
		if (x != -1 && y != -1) return x<<1|1;
	}
	return -1;
}

int main(){
	cin >> s;
	if (s == "a") { puts("2 0"); return 0;}
	if (s == "b") { puts("1 0"); return 0;}
	int n = 1, a = 1, b = 0;
	while (a < s.size()) {
		f[n] = a;
		n++;
		swap(a,b);
		a += b;
	}
	printf("%d %d\n",n,dfs(0,s.size(),n));
	
	return 0;
}





