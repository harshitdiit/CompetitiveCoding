#include<bits/stdc++.h>
using namespace std;

int main(){
  int N, K, t, maxt=0;
  cin>>N>>K;
  map<int, int> M;
  for(int i=0; i<N; i++){
    cin>>t;
    if(M.find(t)==M.end())
      M[t]=0;

    M[t]++;
    if(maxt<M[t])
      maxt = M[t];
  }
  int dishes=1;
  if(maxt>K && K!=0){
    dishes = maxt%K==0 ? (maxt/K):(maxt/K)+1;
  }
  cout<<dishes*M.size()*K - N;
  return 0;
}
