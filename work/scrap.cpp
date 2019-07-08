#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define rep(i,x) for(int i = 0; i < x; i++)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> ivec;
const ll N = 1e9+7;

int main(){
    wchar_t s[] = L"いせうちゅかにとつぶ";
    // string s("abcdefg");
    sort(s.begin(),s.end());
    rep(i,s.size())cout << s[i];
    cout << endl;
    int count = 0;
    do{
        bool ok = true;
        rep(i,s.size()){
            if(s[i] == 'ゅ'){
                if(i == 0){ok = false;continue;}
                if(s[i+1] != 'う'){ok = false;continue;}
                if(s[i-1] != 'ち' && i != 2 && s[i-1] != 'に'){ok = false;continue;}
            }
        }
        // if(ok)cout << "つ" << s[0] << s[1] <<"り" << s[2] << s[3] << s[4] << s[5] << "く" << s[6] << s[7] << s[8] << s[9] << endl;
        if(ok)count++;
    }while(next_permutation(s.begin(),s.end()));
    cout << count << endl;
    return 0;
}