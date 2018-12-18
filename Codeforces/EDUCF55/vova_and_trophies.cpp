#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, count=0;
  string S;
  cin>>N>>S;
  vector<pair<int, int> > V;
  for(int i=0; i<=N; i++){
    if(i==N){
      if(count>0){
        V.push_back({count, i});
      }
    }
    else if(S[i]=='G'){
      count++;
    }
    else{
      if(count>0){
        V.push_back({count, i});
        count=0;
      }
    }
  }

  int ans=0;
  for(int i=0; i<V.size(); i++){
    if(i!=V.size()-1 && V[i+1].second-V[i+1].first-V[i].second==1){
      if(V.size()==2){
        ans = max(ans, V[i].first+V[i+1].first);
      }
      else{
        ans = max(ans, V[i].first+V[i+1].first+1);
      }
    }
    ans = (V.size()>1 && V[i].first!=S.size())? max(ans, V[i].first+1) : max(ans, V[i].first);
    //cout<</*V.size()>1 && */(V[i].first!=V.size())<<endl;
  }

  cout<<ans;

  return 0;
}
