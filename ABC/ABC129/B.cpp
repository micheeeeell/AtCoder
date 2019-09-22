#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){
    int n;
    int sum = 0;
    int s1 = 0;
    cin >> n;
    vector<int> w(n);
    for(int i = 0; i < n;i++){
        int temp;
        cin >> temp;
        w.at(i) = temp;
        sum += temp;
    }
    set<int> weight;
    for(int i = 0;i < n;i++){
        s1 += w.at(i);
        int s2 = sum-s1;
        int ans = s1-s2;
        if(ans < 0)ans = -ans;
        weight.insert(ans);
    }
    cout << *weight.begin() << endl;

}