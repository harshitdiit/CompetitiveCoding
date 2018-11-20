#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  string S;
  cin>>N>>S;
  int tc=-1;
  for(int i=0; i<N-1; i++){
    if(S[i]>S[i+1]){
      tc=i;
      break;
    }
  }
  if(N>1){
    if(tc!=-1)
      S.erase(S.begin()+tc);
    else
      S.erase(S.end()-1);
  }
  cout<<S<<endl;
  return 0;
}
