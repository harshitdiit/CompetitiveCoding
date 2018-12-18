#include<bits/stdc++.h>
using namespace std;

int main(){
  long long N, H, total=0, reqd=0, bht=0;
  cin>>N>>H;
  vector<long long> S(N);
  for(int i=0; i<N; i++){
    cin>>S[i];
    total+=S[i];
  }
  sort(S.begin(), S.end());
  for(int i=0; i<N; i++){
    reqd++;
    if(S[i]>bht)
      bht++;
  }
  reqd = reqd + (S.back()-bht);
  cout<<total-reqd;
  return 0;
}
