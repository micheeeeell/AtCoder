#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n), am, ap;
    multiset<int> aplus;
    bool ok = true;
    int minus = 0, plus = 0;
    rep(i,n){
        cin >> a[i];
        if(a[i] < 0) {
            minus++;
            aplus.insert(-a[i]);
            am.push_back(a[i]);
        }
        else(a[i] > 0) {
            plus++;
            aplus.insert(a[i]);
            ap.push_back(a[i]);
        }
        else{
            
        }
    }
    int ans = 0;
    if(*max_element(a.begin(),a.end()) < 0 || *min_element(a.begin(),a.end()) > 0) ok = false;
    for(auto i : aplus){
        ans += i;
    }
    if(!ok){
            ans -= *aplus.begin() * 2;
    }
    cout << ans << endl;
    
    vector<int>x(n-1),y(n-1);
    sort(ap.begin(),ap.end());sort(am.begin(), am.end(), greater<int>());
    int count = 0, mc = 0;
    if(minus > 1 && plus > 1) {
        x[0] = am[0]; y[0] = ap[0];
        plus--;
    }
    else if(plus == 1){
        x[0] = ap[0]; y[0] = am[0];
        minus--;
    }
    else if(minus == 1){
        x[0] = am[0]; y[0] = ap[0];
        plus--;
    }
    else if(minus == 0){
        y[0] = ap[0]; x[0] = ap[1];
        minus++;
        count = -1;
        plus-=2;
    }
    else if(plus == 0){
        y[0] = am[0]; x[0] = am[1]; 
        plus++;
        mc = -1;
        minus-=2;
    }
    // minus--;
    for(int i = 1;i < n-1; i++){
        if(plus > 1){
            x[i] = x[i-1] - y[i-1];
            y[i] = ap[i-mc];
            plus--;
            count++;
        }
        else if(minus >= 1 && plus == 1){
            x[i] = ap[i - mc];
            y[i] = x[i-1] - y[i-1];
            minus--;
            count++;
            plus--;
        }
        else if(minus >= 1){
            x[i] = x[i-1] - y[i-1];
            y[i] = am[i - count];
        }
    }
    rep(i,n-1){
        cout << x[i] << " " << y[i] << "\n";
    }
}