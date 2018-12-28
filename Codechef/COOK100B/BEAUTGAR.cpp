#include<bits/stdc++.h>
using namespace std;

int main(){
  int T;
  cin>>T;
  while(T--){
    string S;
    cin>>S;
    int tR=0, tG=0;
    S = S + S[0];

    for(int i=0; i<S.size()-1; i++){
      if(S[i]==S[i+1]){
        if(S[i]=='R'){
          tR++;
        }
        else{
          tG++;
        }
      }
    }
    if(tR==tG && (tR+tG==2 || tR+tG==0)){
      cout<<"yes\n";
    }
    else{
      cout<<"no\n";
    }
  }
  return 0;
}
