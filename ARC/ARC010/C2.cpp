#include <iostream>
#include <vector>
#include <map>
#define repeat_from(i,m,n) for (int i = (m); (i) < (n); ++(i))
#define repeat(i,n) repeat_from(i,0,n)
typedef long long ll;
using namespace std;
constexpr ll inf = 1000000007;
int main() {
    int n, m, y, z; cin >> n >> m >> y >> z;
    vector<char> c(m);
    vector<int> p(m);
    repeat (i,m) cin >> c[i] >> p[i];
    string b; cin >> b;
    map<char,int> rc; repeat (i,m) rc[c[i]] = i;
    vector<vector<ll> > cur(m, vector<ll>(1 << m, - inf));
    vector<vector<ll> > prv(m, vector<ll>(1 << m, - inf));
    repeat (i,n) {
        int ci = rc[b[i]];
        prv = cur;
        { auto & it = cur[ci][1 << ci]; it = max<ll>(it, p[ci]); }
        repeat (j, m) {
            repeat (k, 1 << m) {
                if (prv[j][k] == - inf) continue;
                auto & it = cur[ci][k | (1 << ci)];
                it = max(it, prv[j][k] + p[ci] + (ci == j ? y : 0));
            }
        }
    }
    ll result = 0;
    repeat (j, m) {
        repeat (k, 1 << m) {
            result = max(result, cur[j][k] + (k == (1<<m)-1 ? z : 0));
        }
    }
    cout << result << endl;
    return 0;
}