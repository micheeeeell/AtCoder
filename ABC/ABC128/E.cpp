#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int N; scanf("%llu",&N);
    long long int Q; scanf("%llu",&Q);
    pair<pair<long long int, long long int>,long long int> vec[N];
    vector<long long int> start(Q);
    for(int i = 0; i<N;i++){
            long long int temp1, temp2, temp3;
            scanf("%llu %llu %llu",&temp1,&temp2,&temp3);
            vec[i] = make_pair(make_pair(temp3,temp1),temp2);
    }

    for(int i = 0;i<Q;i++){
        scanf("%llu",&start.at(i));
    }
    vector<long long int> output(Q,-1);
    bool ok = true;
    sort(vec,vec+N);
    // for (int i = 0;i<N;i++){
    //     cout<<vec[i].first.second<< " ";
    // }
    for(int i = 0; i<Q;i++){
        for(int j = 0;j<N;j++){
            long long int temp = start.at(i)+vec[j].first.first;
            if(temp >= vec[j].first.second && temp < vec[j].second){
                output.at(i) = vec[j].first.first;
                // ok = false;
                break;
            }
        }
        // if(ok)
    }
    for(int i = 0;i < Q;i++){
        cout << output.at(i) << "\n";
    }
    return 0;
}