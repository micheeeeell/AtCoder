#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(ll i = 0; i < (ll)(x); i++)
#define pb push_back
#define eb emplace_back
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
const ll MOD = 1e9+7;
const int n_max = 1e5+10;


ll n;
class neig {
    public:
    neig(){};
    template<class T>
    neig(T id){
        if(id == 0){pre = n-1; nex = 1;}
        else if(id == n-1){pre = n-2; nex = 0;}
        else{pre = id - 1; nex = id + 1;}
    }
    ll pre, nex;
};

ll ceil(ll a,ll b){
    return (a + b - 1) / b;
};

int main(){
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    priority_queue<Pll> pq;
    vector<ll> b(n);
    rep(i,n) {
        cin >> b[i];
        if(b[i] != a[i])pq.push({b[i], i});
    }
    bool ok = true;
    ll ans = 0;
    while(pq.size()){
        Pll temp = pq.top();pq.pop();
        neig tn = neig(temp.second);
        ll sum = b[tn.pre] + b[tn.nex];
        // debug(temp.first);debug(temp.second);
        // debug(sum);
        if(temp.first < sum){ok = false;break;}
        if(temp.first == a[temp.second])continue;
        if(temp.first > max(a[temp.second], sum)){
            ll t = temp.first % sum;
            if(t < a[temp.second] ){
                if((b[temp.second] - a[temp.second]) % sum != 0){
                    ok = false;
                    break;
                }
            }
            ans += (b[temp.second] - max(t, a[temp.second])) / sum;
            b[temp.second] = max(t, a[temp.second]);
        }
        if(b[temp.second] != a[temp.second])pq.push({b[temp.second], temp.second});
    }

    cout << (ok ? ans : -1) << endl;
}