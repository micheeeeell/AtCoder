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
const ll MOD = 1e9+7;
const int n_max = 1e5+10;

class abc {
    public:
    ll a,b,s;
    abc(){};
    abc(ll at,ll bt,ll st) : a(at%MOD), b(bt%MOD), s(st%MOD)
    {
    };

    void print(){
        cout << a << " " << b << " " << s << endl;
        return ;
    };
};

int main(){
    string s;cin >> s;
    int n = s.length();
    vector<vector<abc>> dp(n+10, vector<abc>(3));
    rep(i,3){
        abc temp(0,0,0);
        dp[0][i] = temp;
    }
    rep(i,n+1){
        if(!i)continue;
        // '?' は -2
        int now = s[i-1] - 'A';
        rep(j,3){
            // ひとつ前
            ll atemp = 0, btemp = 0, sumtemp = 0;
            rep(k,3){
                if(now == -2 || now == 0){
                    atemp += dp[i-1][k].a + 1;
                    btemp += dp[i-1][k].b;
                    sumtemp += dp[i-1][k].s;
                }
                if(now == -2 || now == 1){
                    atemp += dp[i-1][k].a;
                    btemp += dp[i-1][k].b + dp[i-1][k].a;
                    sumtemp += dp[i-1][k].s;
                }
                if(now == -2 || now == 2){
                    atemp += dp[i-1][k].a;
                    btemp += dp[i-1][k].b;
                    sumtemp += dp[i-1][k].s + dp[i-1][k].b;
                }
            }
            if(now == -2){
                abc temp(atemp, btemp, sumtemp);
                dp[i][j] = temp;
            }
            else{
                if(now == j){
                    abc temp(atemp, btemp, sumtemp);
                    dp[i][j] = temp;
                }
                else{
                    abc temp(0,0,0);
                    dp[i][j] = temp;
                }
            }
        }
    }

    rep(i,n+1){
        rep(j,3){
            cout << i << " " << j << " ";
            dp[i][j].print();
        }
    }

    ll res = 0;
    rep(i,3)res = (res + dp[n][i].s) % MOD;
    cout << res << endl;
}