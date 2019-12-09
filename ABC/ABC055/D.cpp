#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
#define rep(i,x) for(int i = 0; i < (int)(x); i++)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << (x) << "\n";
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
const ll INF = LLONG_MAX/4;
const int n_max = 1e5+10;

void print(vector<bool> &ani){
    int n = ani.size();
    rep(i,n)cerr << ani[i] << " ";
    cerr << endl;
    // cerr << ani << endl;
}

int main(){
    ll n; cin >> n;
    string s;cin >> s;
    // 0が羊，1が狼
    vector<bool> ani(n+2);
    bool ok = false;
    rep(i,2){
        rep(j,2){
            ani[0] = i;
            ani[1] = j;
            // debug(i);
            // debug(j);
            rep(k,n){
                if(s[k] == 'o'){
                    if(ani[k+1] == 0){
                        ani[k+2] = ani[k];
                    }
                    else ani[k+2] = !ani[k];
                }
                else{
                    if(ani[k+1] == 0){
                        ani[k+2] = !ani[k];
                    }
                    else ani[k+2] = ani[k];
                }
                // debug(ani[k])
            }
            print(ani);
            debug(ani[n]);
            debug(ani[n+1]);
            debug(i);
            debug(j);
            debug(ani[n] == i);
            debug(ani[n+1] == j);   
            if(ani[n] == i && ani[n+1] == j){
                ok = true;
                goto tobreak;
            }
        }
    }
    tobreak:
    string res;
    if(!ok){
        cout << -1 << endl;
        return 0;
    }
    else{
        rep(i,n){
            if(ani[i+1])res += "W";
            else res += "S";
        }
    }
    cout << res << endl;
}