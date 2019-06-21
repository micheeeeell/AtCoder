#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
    int p,q,r;
    cin >> p >> q >> r;
    int m = min(p +q,min(q + r, r + p));
    cout << m << endl;
}