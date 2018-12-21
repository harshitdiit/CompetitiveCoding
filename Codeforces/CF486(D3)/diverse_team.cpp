#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin>>N>>K;
  vector<int> V(N);
  set<int> S;
  for(int i=0; i<N; i++){
    cin>>V[i];
    S.insert(V[i]);
  }
  if(S.size()>=K){
    cout<<"YES"<<endl;
    int i=0;
    while(S.size()>0 && K>0){
      if(S.find(V[i])!=S.end()){
        cout<<i+1<<" ";
        S.erase(V[i]);
        K--;
      }
      i++;
    }
    cout<<endl;
  }
  else{
    cout<<"NO"<<endl;
  }
  return 0;
}
