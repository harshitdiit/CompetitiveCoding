#include<bits/stdc++.h>
using namespace std;

int main(){
  string S, D;
  cin>>S;

  int N=S.size();

  if(S.size()%2==0){
    for(int i=0; i<S.size()/2; i++){
      D=S[N-1-i]+D;
      D=S[i]+D;
    }
  }
  else{
    for(int i=0; i<S.size()/2; i++){
      D=S[i]+D;
      D=S[N-1-i]+D;
    }
    D=S[N/2]+D;
  }
  cout<<D;
  return 0;
}
