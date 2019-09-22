#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
#define rep(i,x) for(int i=0;i<x;i++)

int main() {
	int N, D, ans = 0;
	cin >> N >> D;
	int i, j, k;
	int x[10][10];

	rep(i, N) {
		rep(j, D) {
			cin >> x[i][j];
		}
	}
	rep(i, N) {
		rep(j, i)//j<i　ダブルカウントしないように
		{
			int s = 0;
			int t = 0;
			rep(k, D) {
				s = x[i][k] - x[j][k];
				t += s * s;

                // cout << k  << ' ' <<  i  << ' ' << j << ' ' <<  sqrt(t)  << ' ' << s << endl;
				// if (sqrt(t) == (int)s) {
				// 	ans++;
				// }
			}
            if(ceil(sqrt(t)) == floor(sqrt(t))) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}