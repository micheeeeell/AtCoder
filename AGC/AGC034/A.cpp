#include<bits/stdc++.h>
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)

using namespace std;
// enum{ Nothing, rock, fail = 100};
int ans = 0;
int jump(int pos, int goal,int other, string s){
    // cout << pos << endl;
    // cout << goal << endl;
    if(pos == goal){
        ans = 1;
    }

    else if(s[pos+2] != '#' && pos+2 != other && pos+1 != goal){
        pos += 2;
        jump(pos,goal,other,s);
    }    
    else if(s[pos+1] != '#' && pos+1 != other){
        pos += 1;
        jump(pos,goal,other,s);
    }
    else{
        ans = 0;
    }
    // cout << "test" << pos << ans;
    return ans;
    
}

int main(){
    int n,a,b,c,d;
    string s;
    cin >> n >> a >> b >> c >> d;
    a--;b--;c--;d--;
    cin >> s;

    if(c < d){
        
        int funuke = jump(b,d,a,s);
        // cout << funuke <<endl;
        // cout << sunuke << endl;
        if(funuke == 1){
            b = d;
        }
        int sunuke = jump(a,c,b,s);
        if(sunuke == 1 && funuke == 1){
            cout << "Yes" << endl;
            return 0;
        }
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    else{
        int i = b;
        while(i < d){
            if(s[i+1] != '#' && s[i+2 != '#']){
                b = i+1;
                break;
            }
            else if(s[i-1] != '#' && s[i+1] !='#'){
                b = i;
                break;
            }
            else if(s[i+2] != '#')i++;
            i++;
            // cout <<"i"<< i << endl;
        }
        int sunuke = jump(a,c,b,s);
        if(sunuke == 1){
            a = c;
        }
        int funuke = jump(b,d,a,s);
        if(sunuke == 1 & funuke == 1){
            cout << "Yes" << endl;
            return 0;
        }
        else {
            cout << "No" << endl;
            return 0;
        }
        
    }


}