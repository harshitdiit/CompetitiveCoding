#include<bits/stdc++.h>
using namespace std;

#define PII pair<int, pair<int, int>>

int main(){
    int N, Q;
    cin>>N>>Q;

    vector<long long> V(N);
    for(int i=0; i<N; i++){
        cin>>V[i];
    }

    int T, L, R, X;

    vector<PII> set, add;
    for(int i=0; i<Q; i++){
        cin>>T>>L>>R>>X;
        if(T==1){
            add.push_back({X, {L, R}});
        }
        else{
            set.push_back({X, {L, R}});
        }
    }

    sort(set.begin(), set.end());
    sort(add.begin(), add.end());

    int i=0, j=0;
    while(i<add.size() && add[i].first<0){
        for(int k=add[i].second.first-1; k<add[i].second.second; k++){
            V[k]+=add[i].first;
        }
        i++;
    }

    while(j<set.size()){
        for(int k=set[j].second.first-1; k<set[j].second.second; k++){
            V[k]=set[j].first;
        }
        j++;
    }

    while(i<add.size()){
        for(int k=add[i].second.first-1; k<add[i].second.second; k++){
            V[k]+=add[i].first;
        }
        i++;
    }

    for(int k=0; k<V.size(); k++){
        cout<<V[k]<<" ";
    }

    return 0;
}
