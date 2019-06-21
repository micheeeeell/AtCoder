#include<bits/stdc++.h>
typedef long long ll;

using namespace std;


int main(){
    long long int N; scanf("%llu",&N);
    long long int Q; scanf("%llu",&Q);
    vector<pair<ll,pair<ll,ll> > > vec;
    vector<ll> start(Q);
    set<ll> st;
    for(int i = 0; i<N;i++){
            ll s, t, x;
            scanf("%llu %llu %llu",&s,&t,&x);
            vec.push_back( {s-x,{1,x}} );
            vec.push_back( {t-x,{-1,x}});
    }

    for(int i = 0;i<Q;i++){
        ll temp;
        scanf("%llu",&temp);
        vec.push_back( {temp,{2,0}} );
    }
    vector<long long int> output(Q,-1);
    // bool ok = true;
    // pair<ll,pair<int,ll>> man;
    sort(vec.begin(),vec.end());

    // auto itr_lb = lower_bound(ALL(vec), vec.first);
    // for(auto itr = vec.begin();itr!=itr_lb;itr++){
    //     if(itr*.second.first==1)
    //         st.insert(*itr);
    //     else
    //         st.erase
    // }
    int man = 0;
    for(int i = 0;i<vec.size();i++){
        
        if(vec[i].second.first == 1 ){
            st.insert(vec[i].second.second);
        }
        else if(vec[i].second.first == -1){
            st.erase(vec[i].second.second);
        }
        else{
            if(*st.begin() != 0 ){
                output.at(man) = *st.begin();
            }
            man++;
        }
    }
    for(int i = 0;i < Q;i++){
        cout << output.at(i) << "\n";
    }
    return 0;
}