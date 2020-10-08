#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, x) for (int i = 0; i < x; i++)
using namespace std;

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll modpow(ll mt, ll n, ll mod) {
    if (n < 0) {
        n  = -n;
        mt = modinv(mt, mod);
        // debug(mt, n);
    }
    ll res = 1, tmp = mt;
    while (n) {
        if (n & 1) {
            res *= tmp;
            res %= mod;
        }
        tmp *= tmp;
        tmp %= mod;
        n /= 2;
    }

    return res;
}
int main() {
    int a, m;
    cin >> a >> m;
    cout << modinv(a, m) << endl;
}