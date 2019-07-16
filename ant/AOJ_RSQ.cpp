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
const ll INF = INT_MAX;

struct SegmentTree{
    private:
        int n;
        vector<int> node;

    public:
        SegmentTree(vector<int> v){
            int sz = v.size();
            n = 1;while(n < sz)n *= 2;
            node.resize(2*n-1,0);

            rep(i,sz)node[i+n-1] = v[i];
            for(int i = n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
        }

        void add(int x,int val){
            x += (n - 1);

            node[x] += val;
            while(x > 0){
                x = (x - 1) / 2;
                node[x] = node[x*2+1] + node[x*2+2];
            }
        }

        int getsum(int a, int b, int k = 0, int l = 0, int r = -1){
            if(r < 0) r = n;

            if(r <= a || b <= l) return 0;

            if(a <= l && r <= b) return node[k];

            int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
            int vr = getsum(a, b, k*2+2, (l+r)/2, r);
            return vl+vr;
        }
};

int main(){
    int n,q;cin >> n >> q;
    vector<int> xy[q];
    rep(i,q){
        int com,x,y;cin >> com >> x >> y;
        // xy[i] = {com,x,y};
        xy[i].pb(com);xy[i].pb(x);xy[i].pb(y);
    }

    vector<int> a(n,0);
    SegmentTree seg(a);

    rep(i,q){
        int com,x,y;
        com = xy[i][0];x = xy[i][1];y = xy[i][2];
        if(com) cout << seg.getsum(x-1,y) << endl;
        else seg.add(x-1,y);
    }

    return 0;
}