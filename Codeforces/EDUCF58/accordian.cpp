#include<bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int i=0, count=0, fs=0, fc=0, ls=0, lc=0;
  while(i<S.size() && S[i]!='['){
    i++;
  }
  if(i==S.size()){
    cout<<-1;
    return 0;
  }

  fs=i;
  i++;
  while(i<S.size() && S[i]!=':'){
    i++;
  }

  if(i==S.size()){
    cout<<-1;
    return 0;
  }

  fc=i;
  i++;

  i=S.size()-1;
  while(S[i]!=']'){
    if(i==fc){
      cout<<-1;
      return 0;
    }
    i--;
  }

  ls = i;
  i--;
  while(S[i]!=':'){
    if(i==fc+1){
      cout<<-1;
      return 0;
    }
    i--;
  }

  if(i==fc){
    cout<<-1;
    return 0;
  }

  lc = i;

  for(i=fc+1; i<lc; i++){
    if(S[i]=='|'){
      count++;
    }
  }

  cout<<(count+4);
  return 0;
}
