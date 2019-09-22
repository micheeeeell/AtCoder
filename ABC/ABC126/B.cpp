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

int main(){
    int n; cin >> n;
    int front = n / 100;
    int back = n - (n/100)*100;
    bool fok,bok, all_ok = true;//trueなら月,年に使える
    if(0 < front && front <= 12)fok = true;
    else if(front <= 99)fok = false;
    else all_ok = false;
    if(0 < back && back <= 12)bok = true;
    else if(back <= 99)bok = false;
    else all_ok = false;

    if(!all_ok){cout << "NA" << endl;return 0;}
    if(fok){
        cout << (bok ? "AMBIGUOUS" : "MMYY") << endl;
    }
    else{
        cout << (bok ? "YYMM" : "NA") << endl;
    }
    return 0;
}