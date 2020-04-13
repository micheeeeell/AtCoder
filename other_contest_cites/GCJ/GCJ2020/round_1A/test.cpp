#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define rrep(i,x) for(ll i = (ll)(x)-1;0 <= i; i--)
#define reps(i,x) for(ll i = 1; i < (ll)(x)+1; i++)
#define rreps(i,x) for(ll i = (ll)(x); 1 <= i; i--)
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
const int n_max = 1e5+10;
// #define int ll

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int Q;
	cin >> Q;
	for (int q = 0; q < Q; q++) {
		int N;
		cin >> N;
		string left, right;
		bool na = false;
		for (int i = 0; i < N; i++) {
			
			string s, l, r;
			cin >> s;
			int ast_ind = find(s.begin(), s.end(), '*') - s.begin();
			l = s.substr(0, ast_ind);
			r = s.substr(ast_ind + 1);
			if (left.size() > l.size()) {
				na = left != l.substr(0, left.size());
			}
			else {
				na = left.substr(0, l.size()) != l;
				left = l;
			}
			if (na) break;
			if (right.size() > r.size()) {
				na = right.substr(right.size() - r.size()) != r;
			}
			else {
				na = right != r.substr(r.size() - right.size());
				right = r;
			}
			if (na) break;
		}
		cout << "Case #" << q + 1 << ": ";
		if (na) cout << '*' << endl;
		else cout << left << right << endl;
	}
	return 0;
}