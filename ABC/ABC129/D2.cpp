#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)

using namespace std;
int main(){
    int h,w;
    cin >> h >> w;
    int ht = 0, wt = 0;
    vector<string> s(h);
    set<int> st;
    rep(i,h){
        cin >> s.at(i);
    }
    // cout << s.at(0)[0];
    rep(i,h){
        rep(j,w){
            if(s.at(i)[j] == '.'){
                int ans  = 1;
                ht = i;wt = j;
                for(int k = i;k < h;k++){
                    if(s.at(k+1)[j] == '.'){
                        ans++;
                    }
                    else break;
                }
                for(int k = i;k >= 0;k--){
                    if(s.at(k-1)[j] == '.'){
                        ans++;
                    }
                    else break;
                }
                for(int k = j;k < w;k++){
                    if(s.at(i)[k+1] == '.'){
                        ans++;
                    }
                    else break;
                }
                for(int k = j;k >= 0;k--){
                    if(s.at(i)[k-1] == '.'){
                        ans++;
                    }
                    else break;
                }
                // ans = ans - 4;
                st.insert(ans);
                cout << i << j << ans << endl;
            }
        }
    }
    cout << *st.end() << endl;
}