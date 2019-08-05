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
const ll N = 1e9+7;
const int n_max = 1e5+10;
int main(){
    string s; cin >> s;
    int len = s.size();
    vector<int> a(len,0);
    int rt = 1,lt = 0,chg = 0,sum = 1;
    rep(i,len-1){
        if(s[i] == 'R' && s[i+1] == 'R'){
            rt++;
            sum++;
        }
        else if(s[i] == 'R' && s[i+1] == 'L'){
            lt++;
            sum++;
            chg = i;
        }
        else if(s[i] == 'L' && s[i+1] == 'L'){
            lt++;
            sum++;
        }
        else if(s[i] == 'L' && s[i+1] == 'R'){
            // cout << rt  << ' ' << lt  << ' ' << sum << endl;
            if(!(sum%2)){
                a[chg] = sum/2;
                a[chg+1] = sum/2;
            }
            else if(lt > rt){
                int temp = lt-rt;
                if((rt + temp)%2){
                    a[chg] = sum/2;
                    a[chg+1] = sum/2+1;
                }
                else{
                    a[chg] = sum/2+1;
                    a[chg+1] = sum/2;
                }
            }
            else if(lt < rt){
                int temp = rt-lt;
                if((lt + temp)%2 == 0){
                    a[chg] = sum/2;
                    a[chg+1] = sum/2+1;
                }
                else{
                    a[chg] = sum/2+1;
                    a[chg+1] = sum/2;
                }
            }
            rt = 1;lt = 0;sum = 1;
        }

        if(i == len-2){
            // cout << rt  << ' ' << lt  << ' ' << sum << endl;
            if(!(sum%2)){
                a[chg] = sum/2;
                a[chg+1] = sum/2;
            }
            else if(lt > rt){
                int temp = lt-rt;
                if((rt + temp)%2){
                    a[chg] = sum/2;
                    a[chg+1] = sum/2+1;
                }
                else{
                    a[chg] = sum/2+1;
                    a[chg+1] = sum/2;
                }
            }
            else if(lt < rt){
                int temp = rt-lt;
                if((lt + temp)%2 == 0){
                    a[chg] = sum/2;
                    a[chg+1] = sum/2+1;
                }
                else{
                    a[chg] = sum/2+1;
                    a[chg+1] = sum/2;
                }
            }
        }
    }
    rep(i,len){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;

}